#ifndef EVENTS_H
#define EVENTS_H
#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Events
{
private :
    int id_event ;
    QString id_emp ;
    QString nom_event;
    QString type_event;
    QString client_event;
    QDate date_event;
    float cost_event;
    int guest_number ;
    float reduction_event ;


public:
    Events();
    Events( int ,QString , QString , QString  , QString , QDate , float , int  );
    QSqlQueryModel * afficher();
        bool ajouter();
          bool supprimer(QString) ;
         bool modifier(int id_event );
};

#endif // EVENTS_H
