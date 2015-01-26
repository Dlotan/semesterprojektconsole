#ifndef VIRUSINSERTTHREAD_H
#define VIRUSINSERTTHREAD_H

#include <QObject>
#include <QThread>
#include <QList>
#include <QSqlQuery>

class VirusInsertThread
{
public:
    VirusInsertThread(QSqlQuery &query, QString tableName,
        QList<double> &before, QList<double> &after);

    void run();
private:
    QString tableName;
    QSqlQuery query;
    QList<double> before;
    QList<double> after;
};

#endif // VIRUSINSERTTHREAD_H
