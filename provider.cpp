#include "provider.h"
#include <QSqlQuery>
#include<QDebug>
#include<QTimer>
#include<QDateTime>
#include "mainwindow.h"
#include<QSystemTrayIcon>
Provider::Provider()
{

}
Provider::Provider(QString id , QString nom ,QString prenom ,QString type,QString adresse ,int num,float prix , QString qualite)
{
    this->id = id ;
    this->nom = nom ;
    this->prenom = prenom ;
    this->type = type ;
    this->adresse = adresse ;
    this->num = num ;
    this->prix = prix ;
    this->qualite = qualite ;
}
QSqlQueryModel * Provider::afficher()
{
    QSqlQueryModel *model=new QSqlQueryModel(); //model a voir model besh yat7at fel table view
       model->setQuery("SELECT * FROM FOURNISSEUR"); // a revoir
       model->setHeaderData(0,Qt::Horizontal,QObject::tr("id")); // les entetes li fel tableview
       model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
       model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
       model->setHeaderData(3,Qt::Horizontal,QObject::tr("type"));
       model->setHeaderData(4,Qt::Horizontal,QObject::tr("adresse"));
       model->setHeaderData(5,Qt::Horizontal,QObject::tr("numero téléphone"));
       model->setHeaderData(6,Qt::Horizontal,QObject::tr("prix"));
       model->setHeaderData(7,Qt::Horizontal,QObject::tr("qualité"));
       return model;
}
bool Provider::ajouter()

{
       QSqlQuery query; // !!!!!!!!!!!!!!!!!!!
       QString res = QString::number(num);
       QString res1 = QString::number(prix);
       query.prepare("INSERT INTO FOURNISSEUR(NOM,PRENOM,TYPE,ADRESSE,NUM,PRIX,QUALITE)""VALUES (:nom,:prenom,:type,:adresse,:num,:prix,:qualite)");
       query.bindValue(":nom",nom);
       query.bindValue(":prenom",prenom);
       query.bindValue(":type",type);
       query.bindValue(":adresse",adresse);
       query.bindValue(":num",res);
       query.bindValue(":prix",res1);
       query.bindValue(":qualite",qualite);
       return query.exec();  // traja3lek true walla false selon lrequete taadet walle
}
bool Provider::modifier(QString id)
{
    QSqlQuery query;
    QString res = QString::number(num); // nbadlouhom string besh najmou n7otouhom fel bindvalue loouta
    QString res1 = QString::number(prix);
    query.prepare("UPDATE FOURNISSEUR SET NOM=:nom,PRENOM=:prenom,TYPE=:type,ADRESSE=:adresse,NUM=:num,PRIX=:prix,QUALITE=:qualite WHERE id_fournisseur=:id");
                  query.bindValue(":nom",nom);
                  query.bindValue(":prenom",prenom);
                  query.bindValue(":type",type);
                  query.bindValue(":adresse",adresse);
                  query.bindValue(":num",res);
                  query.bindValue(":prix",res1);
                  query.bindValue(":qualite",qualite);
                  query.bindValue(":id",id);
        return query.exec();
}
bool Provider::supprimer(QString id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM FOURNISSEUR WHERE id_fournisseur= :id");
    query.bindValue(":id",id);
    return query.exec();
}



QSqlQueryModel *Provider::rech(QString nom,QString prenom,QString type)
{

    QSqlQueryModel *model= new QSqlQueryModel();//le modelle qu'on vas afficher de dans
    model->setQuery("SELECT * FROM FOURNISSEUR WHERE NOM LIKE'%"+nom+"%' and PRENOM LIKE'%"+prenom+"%'and TYPE LIKE'%"+type+"%'" );
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("type"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("adresse"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("numero téléphone"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("prix"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("qualité"));
      return model;
}

QSqlQueryModel *Provider::ordre_name()
     {
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from FOURNISSEUR   order by NOM " );
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("type"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("adresse"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("numero téléphone"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("prix"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("qualité"));
         return model;
}


QSqlQueryModel *Provider::ordre_num()
     {
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from FOURNISSEUR    order by NUM " );
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("type"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("adresse"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("numero téléphone"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("prix"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("qualité"));

         return model;
}

//stat
QList<qreal> MainWindow::stat_budget()
{
    QList<qreal> list ;
    QSqlQuery query;
    query.prepare("SELECT * FROM FOURNISSEUR ");//prerparer la bd
    query.exec();//executer la BD
    while(query.next())
    {list.append(query.value(6).toInt());}//nejbed num m base

    return list;
}

QList<QString> MainWindow::stat_bud()
{
    QList<QString> list ;
    QSqlQuery query;
    query.prepare("SELECT*FROM FOURNISSEUR ");
    query.exec();
    while(query.next())
    {list.append(query.value(3).toString());}

    return list;
}



