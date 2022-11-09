#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include "client.h"
#include<QMessageBox>
#include<string>
#include<iostream>
#include<QComboBox>
#include<QRadioButton>
#include"dialog_stat.h"

MainWindow::MainWindow(QWidget *parent):
     QMainWindow(parent),
     ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix(":/image/image/logo.png");


    ui->tableView->setModel(Etmp.afficher());
    ui->tableView_2->setModel(Etmp.afficher());


        QRegularExpression rx("^[A-Za-z]+$");

        QValidator *validator = new QRegularExpressionValidator(rx, this);
        ui->lineEdit_FirstName->setValidator(validator);
        ui->lineEdit_LastName->setValidator(validator);



            QValidator *validator_CIN= new QIntValidator(00000001, 99999999, this);

            ui->lineEdit_CIN->setValidator(validator_CIN);
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
    ui->CIN2->setText(nullptr);
     ui->tableView->setModel(Etmp.afficher());
}


void MainWindow::on_search_clicked()
{ QString cin=ui->CIN2->text();
    ui->tableView->setModel(Etmp.search(cin));

}


void MainWindow::on_sort_clicked()
{
   if(ui->radioButton_CIN->isChecked())
   {
    ui->tableView_2->setModel(Etmp.sort_CIN());
   }
   else if(ui->radioButton_lastname->isChecked())
   {
ui->tableView_2->setModel(Etmp.sort_LastN());

    }
   else if(ui->radioButton_firstname->isChecked())
   {
       ui->tableView_2->setModel(Etmp.sort_FirstN());
   }

}


void MainWindow::on_Stat_clicked()
{
    Dialog_stat stats;
    stats.setModal(true);
    stats.exec();
}

void MainWindow::on_Export_clicked()
{
    QPdfWriter pdf("D:/Work/project QT/client/Client.pdf");

                     QPainter painter(&pdf);

                     int i = 4000;


                     painter.drawText(3000,1500,"LISTE DES CLIENTS");
                     painter.setPen(Qt::blue);
                     painter.setFont(QFont("Arial", 50));
                     painter.drawRect(2700,1200,1700,500);
                     painter.drawRect(0,3000,9600,500);
                     painter.setPen(Qt::black);
                     painter.setFont(QFont("Arial", 9));
                     painter.drawText(500,3300,"First Name");
                     painter.drawText(1500,3300,"Last Name");
                     painter.drawText(2500,3300,"Day");
                     painter.drawText(3500,3300,"Month");
                     painter.drawText(4500,3300,"Year");
                     painter.drawText(5500,3300,"CIN");
                     painter.drawText(7000,3300,"Email");
                     painter.drawText(8500,3300,"Event");

                     QSqlQuery query;
                     query.prepare("select * from client");
                     query.exec();
                     while (query.next())
                     {
                         painter.drawText(500,i,query.value(0).toString());
                         painter.drawText(1500,i,query.value(1).toString());
                         painter.drawText(2500,i,query.value(2).toString());
                         painter.drawText(3500,i,query.value(3).toString());
                         painter.drawText(4500,i,query.value(4).toString());
                         painter.drawText(5500,i,query.value(5).toString());
                         painter.drawText(6500,i,query.value(6).toString());
                         painter.drawText(8500,i,query.value(7).toString());

                         i = i +500;
                     }

                     int reponse = QMessageBox::question(this, "PDF généré", "Afficher le PDF ?", QMessageBox::Yes |  QMessageBox::No);
                     if (reponse == QMessageBox::Yes)
                     {
                         QDesktopServices::openUrl(QUrl::fromLocalFile("D:/Work/project QT/client/Client.pdf"));

                         painter.end();
                     }
                     if (reponse == QMessageBox::No)
                     {
                         painter.end();
                     }
}
