#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include "client.h"
#include<QMessageBox>
#include<string>
#include<iostream>
#include<QComboBox>

MainWindow::MainWindow(QWidget *parent):
     QMainWindow(parent),
     ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix(":/image/image/logo.png");


    ui->tableView->setModel(Etmp.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_add_clicked()
{
    QString FirstName=ui->lineEdit_FirstName->text();
    QString LastName=ui->lineEdit_LastName->text();
    int Day=ui->spinBox->text().toInt();
    int month=ui->month->text().toInt();
    int year=ui->year->text().toInt();

    int cin=ui->lineEdit_CIN->text().toInt();
    QString email=ui->lineEdit_Email->text();
    QString event=ui->event->currentText();

    client c(FirstName,LastName,Day,month,year,cin,email,event);

    bool test=c.ajouter();
    if (test)
       {
           ui->tableView->setModel(Etmp.afficher());
           QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("ajout effectue\n ""click cancel"),QMessageBox::Cancel);

       }
    else
       {
            QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("ajout non fonctional\n""click to cancel"),QMessageBox::Cancel);
       }
}


void MainWindow::on_delete_2_clicked()
{

    int CIN=ui->lineEdit_CIN->text().toInt();
    bool test=Etmp.supprimer(CIN);
    if (test)
    { ui->tableView->setModel(Etmp.afficher());
        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("suppression effectue\n ""click cancel"),QMessageBox::Cancel);

}
 else
    {QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("suppression non fonctional\n""click to cancel"),QMessageBox::Cancel);}
}

void MainWindow::on_tableView_activated(const QModelIndex &index)
{
            QString val=ui->tableView->model()->data(index).toString();

            QSqlQuery query;

            query.prepare("select * from client where CIN='"+val+"'or FirstName='"+val+"'or LastName='"+val+"' or Day='"+val+"' or Month='"+val+"' or year='"+val+"' or Email='"+val+"' or Event='"+val+"' ");

            if(query.exec())
            {
                while(query.next())
                {
                     ui->lineEdit_FirstName->setText(query.value(0).toString());
                     ui->lineEdit_LastName->setText(query.value(1).toString());
                     ui->spinBox->setValue(query.value(2).toInt());
                     ui->month->setValue(query.value(3).toInt());
                     ui->year->setValue(query.value(4).toInt());
                     ui->lineEdit_CIN->setText(query.value(5).toString());
                     ui->lineEdit_Email->setText(query.value(6).toString());
                     ui->event->setCurrentText(query.value(7).toString());


                }
            }


}

void MainWindow::on_update_clicked()
{
    QString FirstName=ui->lineEdit_FirstName->text();
    QString LastName=ui->lineEdit_LastName->text();
    int Day=ui->spinBox->text().toInt();
    int month=ui->month->text().toInt();
    int year=ui->year->text().toInt();
    int cin=ui->lineEdit_CIN->text().toInt();
    QString email=ui->lineEdit_Email->text();
    QString event=ui->event->currentText();

       client c(FirstName,LastName,Day,month,year,cin,email,event);


      bool test=c.update();
      if (test)
      { ui->tableView->setModel(Etmp.afficher());
          QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("Modification effectue\n ""click cancel"),QMessageBox::Cancel);

  }
   else
      {QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("Modification non fonctional\n""click to cancel"),QMessageBox::Cancel);}


}

void MainWindow::on_pushButton_clicked()
{ //kQSqlQuery query;
    ui->lineEdit_FirstName->setText(nullptr);
    ui->lineEdit_LastName->setText(nullptr);
    ui->spinBox->setValue(0);
    ui->month->setValue(0);
    ui->year->setValue(1);
    ui->lineEdit_CIN->setText(nullptr);
    ui->lineEdit_Email->setText(nullptr);
    ui->event->setCurrentText("Event");
}
