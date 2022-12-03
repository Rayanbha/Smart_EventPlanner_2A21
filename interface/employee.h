#ifndef EMPLOYEE_H
#define EMPLOYEE_H
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
#include "message.h"

class employe
{
    QString ID_emp,departement,first_name,password,last_name,ID_chef;
    int salary;
public:
    //constructeurs
    employe();
    employe(QString,QString,QString,QString,QString,QString,int);
    //getters
    QString getID(){return ID_emp;}
    QString getdepartement(){return departement;}
    QString getfirst(){return first_name;}
    QString getpassword(){return password;}
    QString getlast(){return last_name;}
    QString getchef(){return ID_chef;}
    int getsalary(){return salary;}
    //setters
    void setID(QString ident){ID_emp=ident;}
    void setdepartement(QString d){departement=d;}
    void setfirst(QString f){first_name=f;}
    void setpassword(QString p){password=p;}
    void setlast(QString l){last_name=l;}
    void setchef(QString c){ID_chef=c;}
    void setsalary(int sal){salary=sal;}
    //fonction
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(QString);
    bool modifier(QString ID_emp);
    QSqlQueryModel * searchID(QString ID_emp);
    QSqlQueryModel * searchF(QString first_name);
    QSqlQueryModel * searchL(QString last_name);
    QSqlQueryModel * sort_Lastn();
    QSqlQueryModel * sort_firstn();
    QSqlQueryModel * sort_salary();

};
namespace Ui {
class employee;
}

class employee : public QDialog
{
    Q_OBJECT


public:
    explicit employee(QWidget *parent = nullptr);
    ~employee();

private slots:
    void on_pushButton_ajouter_clicked();
    void on_pushButton_supprimer_clicked();
    void on_pushButton_modifier_clicked();
    void on_tableView1_activated(const QModelIndex &index);
    void on_pushButton_reset_clicked();
    void on_pushButton_search_clicked();
    void on_pushButton_sort_clicked();
    void on_pushButton_export_clicked();
    void on_pushButton_send_clicked();

private:
    Ui::employee *ui;
    employe Etmp;
};

#endif // EMPLOYEE_H
