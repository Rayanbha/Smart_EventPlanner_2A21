#ifndef PROVIDER_H
#define PROVIDER_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Provider
{
private:
    QString id ;
    QString nom;
    QString prenom;
    QString type ;
    QString adresse;
    int num;
    float prix ;
    QString qualite ;

public:
    Provider();
    Provider(QString , QString,QString,QString,QString,int,float , QString);
    QSqlQueryModel * afficher();
    bool ajouter();
    bool modifier(QString id);
    bool supprimer(QString id);



};

#endif // PROVIDER_H
