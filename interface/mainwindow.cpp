#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButton_login_clicked()
{
    QString username,password;
    QString R,C,S,E,q;
    R="RH";
    C="CM";
    S="SM";
    E="EM";
    username=ui->lineEdit_Username->text();
    password=ui->lineEdit_Password->text();
    QSqlQuery qry;
    qry.prepare("select * from employee where ID_emp='"+username+"'and password='"+password+"'");

    if (qry.exec())
    {

        int count=0;
       while(qry.next())
        {
           q = qry.value(1).toString();
           qDebug()<<q;
            count++;
        }
        if(count==1)
        {
            QMessageBox::information(nullptr,QObject::tr("login done"),
                                     QObject::tr("login succesfully \n" 
                                                 "Click Cancel to exit."),QMessageBox::Cancel);


              this->hide();
                 //if(username=="211JMT3727")
                 if (q.compare(R)==0)
                  {
                     employee employee;
                     employee.setModal(true);
                     employee.exec();
                  }
                // else if(username=="211JMT6094")
                 else if (q.compare(C)==0)
                  {
                     client client;
                     client.setModal(true);
                     client.exec();
                  }
                // else if(username=="211JMT6438")
                 else if (q.compare(S)==0)
                  {
                     supplier supplier;
                     supplier.setModal(true);
                     supplier.exec();
                  }
                // else if(username=="211JMT9876")
                 else if (q.compare(E)==0)
                  {
                     hafla hafla;
                     hafla.setModal(true);
                     hafla.exec();
                  }
        }
        if(count>1)
        {
            QMessageBox::critical(nullptr,QObject::tr("login failed"),
                                    QObject::tr("user already connected  \n"
                                                "Click Cancel to exit."),QMessageBox::Cancel);
        }
        if(count<1)
        {
            QMessageBox::critical(nullptr,QObject::tr("login failed"),
                                    QObject::tr("wrong username or password \n"
                                                "Click Cancel to exit."),QMessageBox::Cancel);
        }
    }
}
