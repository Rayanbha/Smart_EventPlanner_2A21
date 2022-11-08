#include "events.h"

Events::Events()
{

}
 Events::Events(int id_event ,QString a , QString  b, QString c, QString d, QDate e, float f, int k)
{
    this->id_event = id_event;
     this->id_emp = a ;
     this->nom_event = b ;
     this->type_event = c ;
     this->client_event = d;
     this->date_event = e ;
     this->cost_event = f ;
     this->guest_number = k ;

}
 QSqlQueryModel * Events::afficher()
 {

     QSqlQueryModel *model=new QSqlQueryModel();
     model->setQuery("SELECT * FROM EVENT ");
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID event"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("Event name"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("Date"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("Event type"));
     model->setHeaderData(4,Qt::Horizontal,QObject::tr("Client id"));
     model->setHeaderData(5,Qt::Horizontal,QObject::tr("Cost"));
     model->setHeaderData(6,Qt::Horizontal,QObject::tr("Guest number"));
     model->setHeaderData(7,Qt::Horizontal,QObject::tr("Reduction"));
     model->setHeaderData(8,Qt::Horizontal,QObject::tr("Id employe"));
     return model;
 }
     bool Events::ajouter()

     {
            QSqlQuery query;

            QString res1 = QString::number(cost_event);
            QString res2 = QString::number(guest_number);
             query.prepare("INSERT INTO EVENT(ID_EMP,EVENT_NAME,EVENT_TYPE,EVENT_CLIENT,EVENT_DATE,EVENT_COST,GUEST_NUMBER)""VALUES (:emp,:nom,:type,:client,:date,:cost,:guest)");
             query.bindValue(":emp",id_emp);
             query.bindValue(":nom",nom_event);
             query.bindValue(":type",type_event);
             query.bindValue(":client",client_event);
             query.bindValue(":date",date_event);
             query.bindValue(":cost",res1);
             query.bindValue(":guest",res2);
             return query.exec();
     }
     bool Events ::supprimer(QString id)
     {
     QSqlQuery query;
     QString res=QString(id);
     query.prepare("delete from  event where ID_event= :id");
     query.bindValue(":id",res);
     return query.exec();
     }
     bool Events::modifier(int id_event)
     {
         QSqlQuery query;
         QString res = QString::number(id_event);
         QString res1 = QString::number(cost_event);
         QString res2 = QString::number(guest_number);
         query.prepare("UPDATE EVENT SET EVENT_NAME=:nom,EVENT_TYPE=:type,EVENT_CLIENT=:client,EVENT_DATE=:date,EVENT_COST=:cost ,GUEST_NUMBER=:guest where ID_EVENT=:id");
         query.bindValue(":id",res);
         query.bindValue(":emp",id_emp);
         query.bindValue(":nom",nom_event);
         query.bindValue(":type",type_event);
         query.bindValue(":client",client_event);
         query.bindValue(":date",date_event);
         query.bindValue(":cost",res1);
         query.bindValue(":guest",res2);

         return query.exec();
     }


     QSqlQueryModel * Events::recherche(int id)
     {
         QString res=QString ::number(id);

         QSqlQueryModel *model=new QSqlQueryModel();
         model->setQuery("SELECT * FROM EVENT WHERE ID_EVENT ='"+res+"'");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID event"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("Event name"));
          model->setHeaderData(2,Qt::Horizontal,QObject::tr("Date"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("Event type"));
         model->setHeaderData(4, Qt::Horizontal, QObject::tr("Client id"));
         model->setHeaderData(5, Qt::Horizontal, QObject::tr("Cost"));
         model->setHeaderData(6, Qt::Horizontal, QObject::tr("Guest number"));
         model->setHeaderData(7, Qt::Horizontal, QObject::tr("Reduction"));
          model->setHeaderData(8,Qt::Horizontal,QObject::tr("Id employe"));

         return model;
     }
     QSqlQueryModel* Events::tri_id()
     {
         QSqlQueryModel *model=new QSqlQueryModel();
                 model->setQuery("select * from EVENT order by ID_EVENT");
                 model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID event"));
                 model->setHeaderData(1, Qt::Horizontal, QObject::tr("Event name"));
                  model->setHeaderData(2,Qt::Horizontal,QObject::tr("Date"));
                 model->setHeaderData(3, Qt::Horizontal, QObject::tr("Event type"));
                 model->setHeaderData(4, Qt::Horizontal, QObject::tr("Client id"));
                 model->setHeaderData(5, Qt::Horizontal, QObject::tr("Cost"));
                 model->setHeaderData(6, Qt::Horizontal, QObject::tr("Guest number"));
                 model->setHeaderData(7, Qt::Horizontal, QObject::tr("Reduction"));
                  model->setHeaderData(8,Qt::Horizontal,QObject::tr("Id employe"));
        return model;
     }


      QSqlQueryModel *Events::tri_date()
      {
          QSqlQueryModel *model=new QSqlQueryModel();
                  model->setQuery("select * from EVENT order by EVENT_DATE");
                  model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID event"));
                  model->setHeaderData(1, Qt::Horizontal, QObject::tr("Event name"));
                   model->setHeaderData(2,Qt::Horizontal,QObject::tr("Date"));
                  model->setHeaderData(3, Qt::Horizontal, QObject::tr("Event type"));
                  model->setHeaderData(4, Qt::Horizontal, QObject::tr("Client id"));
                  model->setHeaderData(5, Qt::Horizontal, QObject::tr("Cost"));
                  model->setHeaderData(6, Qt::Horizontal, QObject::tr("Guest number"));
                  model->setHeaderData(7, Qt::Horizontal, QObject::tr("Reduction"));
                   model->setHeaderData(8,Qt::Horizontal,QObject::tr("Id employe"));
         return model;
          }

      QSqlQueryModel *Events::tri_type()
      {
          QSqlQueryModel *model=new QSqlQueryModel();
                  model->setQuery("select * from EVENT order by EVENT_TYPE");
                  model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID event"));
                  model->setHeaderData(1, Qt::Horizontal, QObject::tr("Event name"));
                   model->setHeaderData(2,Qt::Horizontal,QObject::tr("Date"));
                  model->setHeaderData(3, Qt::Horizontal, QObject::tr("Event type"));
                  model->setHeaderData(4, Qt::Horizontal, QObject::tr("Client id"));
                  model->setHeaderData(5, Qt::Horizontal, QObject::tr("Cost"));
                  model->setHeaderData(6, Qt::Horizontal, QObject::tr("Guest number"));
                  model->setHeaderData(7, Qt::Horizontal, QObject::tr("Reduction"));
                   model->setHeaderData(8,Qt::Horizontal,QObject::tr("Id employe"));
         return model;
          }
