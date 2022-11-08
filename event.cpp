#include "events.h"

events::events()
{

} Avion::Avion(int a , QString b , QString  c, QDate d, int e, int f, int k, QString g)
{
     this->Id_avion = a ;
     this->marque= b ;
     this->type_moteur = c ;
     this->date_vol = d;
     this->conso = e ;
     this->kilometrage = f ;
     this->prix_achat = k ;
     this->etat_avion = g ;
}
 QSqlQueryModel * Avion::afficher()
 {
     QSqlQueryModel *model=new QSqlQueryModel();
     model->setQuery("SELECT * FROM AVION ");
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("Id_avion"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("marque"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("type_moteur"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr(" date_vol"));
     model->setHeaderData(4,Qt::Horizontal,QObject::tr("conso"));
     model->setHeaderData(5,Qt::Horizontal,QObject::tr("kilometrage"));
     model->setHeaderData(6,Qt::Horizontal,QObject::tr("prix_achat"));
     model->setHeaderData(7,Qt::Horizontal,QObject::tr("etat_avion"));

     return model;
 }
     bool Avion::ajouter()

     {
            QSqlQuery query;
            QString res = QString::number(Id_avion);
            QString res1 = QString::number(conso);
            QString res2 = QString::number(kilometrage);
            query.prepare("INSERT INTO AVION(ID,MARQUE,TYPE,DATEV,PRIX,CONSO,KILOM,ETAT_AVION)""VALUES (:id,:marque,:type,:datev,:prix,:conso,:kilom,etat_avion)");

             query.bindValue(":id",res);
             query.bindValue(":marque",marque);
             query.bindValue(":type",type_moteur);
             query.bindValue(":datev",date_vol);
             query.bindValue(":prix",prix_achat);
             query.bindValue(":conso",res1);
             query.bindValue(":kilom",res2);
             query.bindValue(":etat",etat_avion);

             return query.exec();
     }
     bool Avion:: supprimer(int Id_avion)
     {
     QSqlQuery query;
     int res3=Id_avion;
       query.prepare ("Delete from avion where ID= :id");
       query.addBindValue (res3);
          return query.exec () ;
      }