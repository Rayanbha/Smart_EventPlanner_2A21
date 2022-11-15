#ifndef EVENTS_H
#define EVENTS_H
#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>

#include <QFileDialog>
#include <QTextDocument>
#include <QPdfWriter>
#include <QPainter>
#include <QDesktopServices>
#include <QPrinter>
#include <QFileDialog>
#include <QTextDocument>
#include <QMessageBox>
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
         QSqlQueryModel *tri_date();
         QSqlQueryModel* tri_type();
         QSqlQueryModel * recherche(QString );
         QSqlQueryModel* tri_id();
         void statistique(QVector<double>* ticks,QVector<QString> *labels);
         void CREATION_PDF();
         float alerte();

};

#endif // EVENTS_H
