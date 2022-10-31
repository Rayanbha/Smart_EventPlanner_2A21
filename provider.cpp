#include "provider.h"

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
    query.prepare("DELETE FROM fournisseur WHERE id_fournisseur= :id");
    query.bindValue(":id",id);
    return query.exec();
}

