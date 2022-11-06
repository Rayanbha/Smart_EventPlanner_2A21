#ifndef CLIENT_H
#define CLIENT_H
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QString>
#include <QDate>
///
class client
{
    QString Firstname,Lastname,email,event;
    int CIN;
    int day,month,year;

public:
    client();
    client(QString ,QString ,int,int,int,int ,QString,QString);


    //get
   QString get_FirstName(){return Firstname;}
   QString get_LastName(){return Lastname;}
   QString get_email(){return email;}
   int get_CIN(){return CIN;}
   int get_day(){return day ;}
   int get_month(){return month;}
   int get_year(){return year;}
   QString get_event(){return event;}

    //set
   void set_FirstName(QString fn){Firstname=fn;}
   void set_LastName(QString ln){Lastname=ln;}
   void set_email(QString mail){email=mail;}
   void set_event(QString evt){event=evt;}
   void set_CIN(int cn){CIN=cn;}
   void set_day(int d){day=d;}
   void set_year(int y){year=y;}
   void set_month(int m){month=m;}

    //fonctions
   bool ajouter();
  bool supprimer(int);
  bool update();

  //affichage
 QSqlQueryModel * afficher();
 QSqlQueryModel  *search(const QString &cin);


 //trier
 QSqlQueryModel *sort_CIN();
 QSqlQueryModel *sort_FirstN();
 QSqlQueryModel *sort_LastN();


 float stats();

};

#endif // CLIENT_H
