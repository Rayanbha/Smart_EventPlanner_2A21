#ifndef MESSAGE_H
#define MESSAGE_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
//#include <QTime>

class message
{
    QString msg;
    //QDate time=QDate::currentDate();

public:
    //constructeurs
    message();
    message(QString);
    //getters
    QString getmsg(){return msg;}
    //setters
    void setID(QString messaget){msg=messaget;}
    //fonction
    QSqlQueryModel * affichermsg();
    bool sendmsg();

};


#endif // MESSAGE_H
