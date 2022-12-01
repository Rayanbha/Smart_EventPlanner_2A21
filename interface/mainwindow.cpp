#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    int ret=A.connect_arduino();
             switch(ret){
             case(0):qDebug()<< "arduino is availble and connected to :"<< A.getarduino_port_name();
                 break;
             case(1):qDebug()<< "arduino is availble but not connected to :"<< A.getarduino_port_name();
                 break;
             case(-1):qDebug()<< "arduino is not availble";
             }
            // QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));


   QObject::connect(&A.serial,SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer

     //le slot update_label suite à la reception du signal readyRead (reception des données).
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


             // this->hide();

                 if (q.compare(R)==0)
                  {
                     employee employee;
                     employee.setModal(true);
                     employee.exec();

                  }
                 else if (q.compare(C)==0)
                  {
                     client client;
                     client.setModal(true);
                     client.exec();
                  }

                 else if (q.compare(S)==0)
                  {
                     supplier supplier;
                     supplier.setModal(true);
                     supplier.exec();
                  }

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
QString ch="";

void MainWindow::update_label()  { //label arduino

    QSqlQuery query;
     QByteArray data="";
     QString mdp="";

    data=A.read_from_arduino();

     qDebug() <<  " data is " <<*data;
     if(ch.length()<=10)


   {  ch=ch+data;}
       data[11]='\0';
     qDebug() <<  " ch is " <<ch;


    if(ch!="")
       {
        query.prepare("select * from employee where password='"+ch+"'");
        if(query.exec())
        {
           mdp=ch;
          ui->lineEdit_Password->setText(ch);
         QString message ="welcome";
         QByteArray br = message.toUtf8();
         A.write_to_arduino(br);
         ch="";
         }
        else
        {
            QString message ="acces denied";
            QByteArray br = message.toUtf8();
            A.write_to_arduino(br);
            QMessageBox::critical(nullptr,QObject::tr("login failed"),
                                    QObject::tr("FAILED TO connected ..........  \n"
                                                 "acces denied \n"
                                                "Click Cancel to exit."),QMessageBox::Cancel);
            ch="";
        }

       }

   /* if(ch.length()>10)
     {
     ch="";
     }
*/
    }

