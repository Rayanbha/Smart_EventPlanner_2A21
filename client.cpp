#include "client.h"


client::client(){}

client::client(QString FirstName,QString LastName,int day,int month,int year,int CIN ,QString email, QString event)
{
    this->Firstname=FirstName;
    this->Lastname=LastName;
    this->day=day;
    this->month=month;
    this->year=year;
    this->CIN=CIN;
    this->email=email;
    this->event=event;

}


QSqlQueryModel * client::afficher()
{
        QSqlQueryModel * model=new QSqlQueryModel();

        model->setQuery("select * from client ");
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("First Name"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("Last Name"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("Day"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("Month"));
        model->setHeaderData(4,Qt::Horizontal,QObject::tr("Year"));
        model->setHeaderData(5,Qt::Horizontal,QObject::tr("CIN"));
        model->setHeaderData(6,Qt::Horizontal,QObject::tr("Email"));
        model->setHeaderData(7,Qt::Horizontal,QObject::tr("Event"));

        return model;

}



bool client:: ajouter()
{

    QSqlQuery query;

    QString c=QString::number(CIN);
    QString d=QString::number(day);
    QString m=QString::number(month);
    QString y=QString::number(year);

    query.prepare("insert into client(FirstName,LastName,day,month,year,CIN,email,event)""values(:FirstName,:LastName,:day,:month,:year,:CIN,:email,:event)");


   query.bindValue(":FirstName",Firstname);
   query.bindValue(":LastName",Lastname);
   query.bindValue(":day",d);
   query.bindValue(":month",m);
   query.bindValue(":year",y);
   query.bindValue(":CIN",c);
   query.bindValue(":email",email);
   query.bindValue(":event",event);


   return query.exec();
}



bool client:: supprimer(int CIN)
{
   QSqlQuery query;
   QString x=QString::number(CIN);
   query.prepare("delete from client where CIN=:CIN ");
   query.bindValue(":CIN",x);
   return   query.exec();


}

bool client::update()
{

    QSqlQuery query;

    QString c=QString::number(CIN);
    QString d=QString::number(day);
    QString m=QString::number(month);
    QString y=QString::number(year);


 //   query.prepare("update client set Firstname='"+Firstname+"',Lastname='"+Lastname+"',birthday='"+birthday+"',CIN='"+CIN+"',email='"+email+"',event='"+event+"' where CIN='"+CIN+"'");
    query.prepare("UPDATE client set  Firstname=:FirstName,Lastname=:LastName,day=:day,month=:month,year=:year,CIN=:CIN,email=:email,event=:event WHERE CIN=:CIN ");



    query.bindValue(":FirstName",Firstname);
    query.bindValue(":LastName",Lastname);
    query.bindValue(":day",d);
    query.bindValue(":month",m);
    query.bindValue(":year",y);
    query.bindValue(":CIN",c);
    query.bindValue(":email",email);
    query.bindValue(":event",event);

    return query.exec();


}
