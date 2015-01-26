#include <QCoreApplication>
#include <database/database.h>
#include <database/sqlquerymodel.h>

#include "dicemaster.h"
#include "filemanager.h"
#include <QDebug>
#include <cstdlib>
#include <QTime>

#include "generator/generatornormal.h"
#include <QTextStream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    std::srand(QTime::currentTime().msec());
    FileManager::initialize();
    Database *database = new Database();
    QString command = "";
    QTextStream qtin(stdin);
    while(true)
    {
        qtin >> command;
        if(!command.endsWith(")"))
        {
            command += "()";
        }
        command.remove(" ");
        QStringList arguments = command.remove(")").split("(");
        command = arguments[0];
        qDebug() << "command:" << command;
        arguments = arguments[1].split(",");
        qDebug() << "arguments:" << arguments;
        if(command == "exit")
        {
            break;
        }
        else if(command == "list")
        {
            database->list();
        }
        else if(command == "new" || command == "create")
        {
            if(arguments.length() < 2)
            {
                qDebug() << "wrong command";
                qDebug() << "create(name,distribution)";
                continue;
            }
            database->createTable(arguments[0], arguments[1], true);
        }
        else if(command == "parasite")
        {
            qDebug() << "Commands are parasiteInsert or parasiteUpdate";
        }
        else if(command == "parasiteInsert")
        {
            if(arguments.length() < 4)
            {
                qDebug() << "wrong command";
                qDebug() << "parasiteInsert(name,parasiteDistribution,amount,initialclasses)";
                continue;
            }
            database->virusInsert(arguments[0],arguments[1],arguments[2].toInt(),arguments[3].toInt());
        }
        else if(command == "parasiteUpdate")
        {
            if(arguments.length() < 4)
            {
                qDebug() << "wrong command";
                qDebug() << "parasiteUpdate(name,parasiteDistribution,amount,initialclasses)";
                continue;
            }
            database->virusInsert(arguments[0],arguments[1],arguments[2].toInt(),arguments[3].toInt());
        }
        else if(command == "delete")
        {
            if(arguments.length() < 1)
            {
                qDebug() << "wrong command";
                qDebug() << "delete(name)";
                continue;
            }
            database->deleteTable(arguments[0]);
        }
        else if(command == "fill")
        {
            if(arguments.length() < 3)
            {
                qDebug() << "wrong command";
                qDebug() << "fill(name,amount,initialclasses)";
                continue;
            }
            database->fillTable(arguments[0], arguments[1].toInt(), arguments[2].toInt());
        }
        else if(command == "profileSingle")
        {
            database->profile(false);
        }
        else
        {
            qDebug() << "unknown command";
        }
    }
    qDebug() << "finished";
    return a.exec();
}
