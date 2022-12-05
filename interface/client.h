#ifndef CLIENT_H
#define CLIENT_H


#include <QDate>
#include"stat_combo.h"
#include"exportexcelobject.h"
#include"smtp.h"
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QSqlError>
#include <QDialog>
#include <QModelIndex>
#include <QPainter>
#include <QDesktopServices>
#include <QPdfWriter>
#include <QUrl>
#include <QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts>
#include <QChartView>
#include <QLineSeries>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
class clients
{
    QString Firstname,Lastname,email,event;
    int CIN;
    QString date;
public:
    clients();
    clients(QString ,QString ,QString,int,QString,QString);


    //get
   QString get_FirstName(){return Firstname;}
   QString get_LastName(){return Lastname;}
   QString get_email(){return email;}
   int get_CIN(){return CIN;}
   QString get_date(){return date;}


   QString get_event(){return event;}

    //set
   void set_FirstName(QString fn){Firstname=fn;}
   void set_LastName(QString ln){Lastname=ln;}
   void set_email(QString mail){email=mail;}
   void set_event(QString evt){event=evt;}
   void set_CIN(int cn){CIN=cn;}
   void set_date(QString d){date=d;}

    //fonctions
   bool ajouter();
  bool supprimer(int);
  bool update();

  //affichage
 QSqlQueryModel * afficher();
 QSqlQueryModel  *search_CIN(const QString &cin);
 QSqlQueryModel  *search_FirstName(const QString &FirstName);
 QSqlQueryModel  *search_LastName(const QString &LastName);



 //trier
 QSqlQueryModel *sort_CIN();
 QSqlQueryModel *sort_FirstN();
 QSqlQueryModel *sort_LastN();


 float stats();

};



namespace Ui {
class client;
}

class client : public QDialog
{
    Q_OBJECT

public:
    explicit client(QWidget *parent = nullptr);
    ~client();
private slots:
    void on_add_clicked();
    void on_delete_2_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_update_clicked();

    void on_pushButton_clicked();

    void on_search_clicked();


    void on_sort_clicked();


    void on_Export_clicked();

    void on_Stat_clicked();

    void on_Excel_clicked();


    void  browse();
    void  sendMail();
    void mailSent(QString status);


    void on_Send_clicked();

    void on_browse_clicked();

    void update_label();

private:
    Ui::client *ui;
    stat_combo *s;
    QStringList files;

    clients tmp;


};

#endif // CLIENT_H
