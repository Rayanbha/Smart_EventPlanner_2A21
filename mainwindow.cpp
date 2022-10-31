#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QMessageBox>
#include "connection.h"
#include <QIntValidator>





MainWindow::MainWindow(QTabWidget *parent):
      QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit_salary->setValidator(new QIntValidator(100,10000,this)); //salary should be between 100 and 10000
    QPixmap pix("C:/Qt/background");
    ui->label_pic->setPixmap(pix);
    QPixmap pix2("C:/Qt/background");
    ui->label_pic2->setPixmap(pix2);
    ui->tableView1->setModel(Etmp.afficher());
    ui->tableView2->setModel(Etmp.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButton_ajouter_clicked()
{
   QString ID_emp=ui->lineEdit_ID->text();
   QString first_name=ui->lineEdit_first->text();
   QString last_name=ui->lineEdit_last->text();
   QString password=ui->lineEdit_password->text();
   QString departement=ui->box->currentText();
   QString ID_chef=ui->lineEdit_chef->text();
   int salary=ui->lineEdit_salary->text().toInt();

   if(ID_emp.length()<11&&ID_emp.length()>5&&first_name.length()<16&&last_name.length()<16&&password.length()<13&&ID_chef.length()<11&&ID_chef.length()>5&&departement.length()<3)
    {
   employee e(ID_emp, departement, first_name, password, last_name, ID_chef, salary);
   bool test=e.ajouter();
     if(test)
     {
         ui->tableView1->setModel(Etmp.afficher());
         ui->tableView2->setModel(Etmp.afficher());
      QMessageBox::information(nullptr,QObject::tr("OK"),
                               QObject::tr("Ajout effectué \n"
                                           "Click Cancel to exit."),QMessageBox::Cancel);
     }
     else
         QMessageBox::critical(nullptr,QObject::tr("not OK"),
                               QObject::tr("Ajout non effectué \n"
                                           "Click Cancel to exit."),QMessageBox::Cancel);
   }
   else
       QMessageBox::critical(nullptr,QObject::tr("not OK"),
                             QObject::tr("NON-RESPECT D'UNE CONDITION \n"
                                         "Click Cancel to exit."),QMessageBox::Cancel);

}
void MainWindow::on_pushButton_supprimer_clicked()
{
   QString ID_emp=ui->lineEdit_ID->text();

   bool test1=Etmp.supprimer(ID_emp);
     if(test1)
     {

         ui->tableView1->setModel(Etmp.afficher());
         ui->tableView2->setModel(Etmp.afficher());
      QMessageBox::information(nullptr,QObject::tr("OK"),
                               QObject::tr("suppression effectuée \n"
                                           "Click Cancel to exit."),QMessageBox::Cancel);
     }
     else
         QMessageBox::critical(nullptr,QObject::tr("not OK"),
                               QObject::tr("suppression non effectuée \n"
                                           "Click Cancel to exit."),QMessageBox::Cancel);

}
void MainWindow::on_tableView1_activated(const QModelIndex &index)
{
 QString val=ui->tableView1->model()->data(index).toString();
 QSqlQuery qry;
 qry.prepare("select * from employee where ID_emp='"+val+"'");
 if(qry.exec())
 {
  while(qry.next())
  {
   ui->lineEdit_ID->setText(qry.value(0).toString());
   ui->lineEdit_first->setText(qry.value(2).toString());
   ui->lineEdit_last->setText(qry.value(4).toString());
   ui->lineEdit_password->setText(qry.value(3).toString());
   ui->box->setCurrentText(qry.value(1).toString());
   ui->lineEdit_salary->setText(qry.value(5).toString());
   ui->lineEdit_chef->setText(qry.value(6).toString());
  }
 }
 else
 {
  QMessageBox::critical(this,tr("error::"),qry.lastError().text());
 }
}
void MainWindow::on_pushButton_modifier_clicked()
{


    QString ID_emp=ui->lineEdit_ID->text();
    QString first_name=ui->lineEdit_first->text();
    QString last_name=ui->lineEdit_last->text();
    QString password=ui->lineEdit_password->text();
    QString departement=ui->box->currentText();
    QString ID_chef=ui->lineEdit_chef->text();
    int salary=ui->lineEdit_salary->text().toInt();
    QString res = QString::number(salary);
    if(ID_emp.length()<11&&ID_emp.length()>5&&first_name.length()<16&&last_name.length()<16&&password.length()<13&&ID_chef.length()<11&&ID_chef.length()>5)
     {
    employee e1(ID_emp, departement, first_name, password, last_name, ID_chef, salary);
    bool test2=e1.modifier(ID_emp);
      if(test2)
      {

          ui->tableView1->setModel(Etmp.afficher());
          ui->tableView2->setModel(Etmp.afficher());
       QMessageBox::information(nullptr,QObject::tr("OK"),
                                QObject::tr("modification effectué \n"
                                            "Click Cancel to exit."),QMessageBox::Cancel);
      }
      else
          QMessageBox::critical(nullptr,QObject::tr("not OK"),
                                QObject::tr("modification non effectué \n"
                                            "Click Cancel to exit."),QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr,QObject::tr("not OK"),
                              QObject::tr("NON-RESPECT D'UNE CONDITION \n"
                                          "Click Cancel to exit."),QMessageBox::Cancel);
}


void MainWindow::on_pushButton_reset_clicked()
{
    ui->lineEdit_ID->setText("211JMT");
    ui->lineEdit_first->setText(nullptr);
    ui->lineEdit_last->setText(nullptr);
    ui->lineEdit_password->setText(nullptr);
    ui->box->setCurrentText("");
    ui->lineEdit_salary->setText(nullptr);
    ui->lineEdit_chef->setText("211JMT");
}
