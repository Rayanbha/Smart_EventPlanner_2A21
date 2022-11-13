#ifndef MESSAGE_H
#define MESSAGE_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>

class message
{
    QString msg;

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
    bool ajoutermsg();

};


#endif // MESSAGE_H
