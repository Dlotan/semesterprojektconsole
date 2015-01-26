#ifndef INSERTTHREAD_H
#define INSERTTHREAD_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QList>
#include <QThread>

class InsertThread
{
public:
    InsertThread(QSqlQuery& query, QString tableName, QList<double>& numbers);
    void run();
private:
    QSqlQuery query;
    QString tableName;
    QList<double> numbers;
};

#endif // INSERTTHREAD_H
