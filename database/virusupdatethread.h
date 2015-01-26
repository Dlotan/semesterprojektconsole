#ifndef VIRUSUPDATETHREAD_H
#define VIRUSUPDATETHREAD_H


#include <QObject>
#include <QThread>
#include <QList>
#include <QSqlQuery>

class VirusUpdateThread
{
public:
    VirusUpdateThread(QSqlQuery &query, QString tableName,
        QList<double> &before, QList<double> &update);

    void run();
private:
    QString tableName;
    QSqlQuery query;
    QList<double> before;
    QList<double> update;
};

#endif // VIRUSUPDATETHREAD_H
