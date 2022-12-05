#include "client.h"
#include "ui_client.h"
#include<QMessageBox>
#include<QPdfWriter>

client::client(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::client)
{
    ui->setupUi(this);
    QPixmap pix(":/image/image/logo.png");


    ui->tableView->setModel(tmp.afficher());
    ui->tableView_2->setModel(tmp.afficher());


        QRegularExpression rx("^[A-Za-z]+$");

        QValidator *validator = new QRegularExpressionValidator(rx, this);
        ui->lineEdit_FirstName->setValidator(validator);
        ui->lineEdit_LastName->setValidator(validator);



            QValidator *validator_CIN= new QIntValidator(00000001, 99999999, this);

            ui->lineEdit_CIN->setValidator(validator_CIN);


}

client::~client()
{
    delete ui;
}



clients::clients(){}

clients::clients(QString FirstName,QString LastName,QString date ,int CIN ,QString email, QString event)
{
    this->Firstname=FirstName;
    this->Lastname=LastName;
    this->date=date;
    this->CIN=CIN;
    this->email=email;
    this->event=event;

}


QSqlQueryModel * clients::afficher()
{
        QSqlQueryModel * model=new QSqlQueryModel();

        model->setQuery("select * from client ");
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("First Name"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("Last Name"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("Birthday"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("CIN"));
        model->setHeaderData(4,Qt::Horizontal,QObject::tr("Email"));
        model->setHeaderData(5,Qt::Horizontal,QObject::tr("Event"));

        return model;

}



bool clients:: ajouter()
{

    QSqlQuery query;

    QString c=QString::number(CIN);

    query.prepare("insert into client(FirstName,LastName,Birthday,CIN,email,event)""values(:FirstName,:LastName,:date,:CIN,:email,:event)");


   query.bindValue(":FirstName",Firstname);
   query.bindValue(":LastName",Lastname);
   query.bindValue(":Birthday",date);
   query.bindValue(":CIN",c);
   query.bindValue(":email",email);
   query.bindValue(":event",event);


   return query.exec();
}



bool clients:: supprimer(int CIN)
{
   QSqlQuery query;
   QString x=QString::number(CIN);
   query.prepare("delete from client where CIN=:CIN ");
   query.bindValue(":CIN",x);
   return   query.exec();


}

bool clients::update()
{

    QSqlQuery query;

    QString c=QString::number(CIN);


     query.prepare("UPDATE client set  Firstname=:FirstName,Lastname=:LastName,birthday=:date,CIN=:CIN,email=:email,event=:event WHERE CIN=:CIN");



    query.bindValue(":FirstName",Firstname);
    query.bindValue(":LastName",Lastname);
    query.bindValue(":birthday",date);

    query.bindValue(":CIN",c);
    query.bindValue(":email",email);
    query.bindValue(":event",event);

    return query.exec();


}

QSqlQueryModel  *clients::search_FirstName(const QString  &FirstName)
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from client where(FirstName like '"+FirstName+"')");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("First Name"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Last Name"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Birthday"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("CIN"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Email"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Event"));

    return model;

}
QSqlQueryModel  *clients::search_LastName(const QString  &LastName)
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from client where(LastName like '"+LastName+"')");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("First Name"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Last Name"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Birthday"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("CIN"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Email"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Event"));

    return model;

}
QSqlQueryModel  *clients::search_CIN(const QString  &cin)
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from client where(CIN like '"+cin+"')");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("First Name"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Last Name"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Birthday"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("CIN"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Email"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Event"));

    return model;

}
QSqlQueryModel *clients::sort_CIN()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from client order by CIN");
    model->setQuery("select * from client ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("First Name"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Last Name"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Birthday"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("CIN"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Email"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Event"));

    return model;

}


QSqlQueryModel *clients::sort_FirstN()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from client ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("First Name"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Last Name"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Birhtday"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("CIN"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Email"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Event"));

    return model;

}

QSqlQueryModel *clients::sort_LastN()
{

    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from client ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("First Name"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Last Name"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Birthday"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("CIN"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Email"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Event"));

    return model;

}

void client::on_add_clicked()
{
    QString FirstName=ui->lineEdit_FirstName->text();
    QString LastName=ui->lineEdit_LastName->text();

    QString date=ui->dateEdit->date().toString("dd/MM/yyyy");

    int cin=ui->lineEdit_CIN->text().toInt();
    QString email=ui->lineEdit_Email->text();
    QString event=ui->event->currentText();

    clients c(FirstName,LastName,date,cin,email,event);

    bool test=c.ajouter();
    if (test)
       {
           ui->tableView->setModel(tmp.afficher());
           QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("ajout effectue\n ""click cancel"),QMessageBox::Cancel);

       }
    else
       {
            QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("ajout non fonctional\n""click to cancel"),QMessageBox::Cancel);
       }
}


void client::on_delete_2_clicked()
{

    int CIN=ui->lineEdit_CIN->text().toInt();
    bool test=tmp.supprimer(CIN);
    if (test)
    { ui->tableView->setModel(tmp.afficher());
        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("suppression effectue\n ""click cancel"),QMessageBox::Cancel);

}
 else
    {QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("suppression non fonctional\n""click to cancel"),QMessageBox::Cancel);}
}

void client::on_tableView_activated(const QModelIndex &index)
{
            QString val=ui->tableView->model()->data(index).toString();
            QSqlQuery query;

            query.prepare("select * from client where CIN='"+val+"' ");

            if(query.exec())
            {
                while(query.next())
                {
                     ui->lineEdit_FirstName->setText(query.value(0).toString());
                     ui->lineEdit_LastName->setText(query.value(1).toString());
                     ui->dateEdit->setDate(QDate::fromString(query.value(2).toString(),"dd/MM/yyyy"));
                     ui->lineEdit_CIN->setText(query.value(3).toString());
                     ui->lineEdit_Email->setText(query.value(4).toString());
                     ui->event->setCurrentText(query.value(5).toString());
                }
            }


}

void client::on_update_clicked()
{
    QString FirstName=ui->lineEdit_FirstName->text();
    QString LastName=ui->lineEdit_LastName->text();
    QString date=ui->dateEdit->date().toString("dd/MM/yyyy");
    int cin=ui->lineEdit_CIN->text().toInt();
    QString email=ui->lineEdit_Email->text();
    QString event=ui->event->currentText();

       clients c(FirstName,LastName,date,cin,email,event);


      bool test=c.update();
      if (test)
      { ui->tableView->setModel(tmp.afficher());
          QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("Modification effectue\n ""click cancel"),QMessageBox::Cancel);

  }
   else
      {QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("Modification non fonctional\n""click to cancel"),QMessageBox::Cancel);}


}

void client::on_pushButton_clicked()
{ //kQSqlQuery query;
    ui->lineEdit_FirstName->setText(nullptr);
    ui->lineEdit_LastName->setText(nullptr);
    ui->dateEdit->setDate( QDate::fromString( "01/01/2000", "dd/MM/yyyy" ) );
    ui->lineEdit_CIN->setText(nullptr);
    ui->lineEdit_Email->setText(nullptr);
    ui->event->setCurrentText("Event");
    ui->CIN2->setText(nullptr);
     ui->tableView->setModel(tmp.afficher());
}


void client::on_search_clicked()
{ QString cin=ui->CIN2->text();
  QString FirstName=ui->CIN2->text();
  QString LastName=ui->CIN2->text();
            if(ui->CIN1->isChecked())
            {     ui->tableView->setModel(tmp.search_CIN(cin));


            }    else if (ui->FirstName1->isChecked())
            {  ui->tableView->setModel(tmp.search_FirstName(FirstName));}
            else if (ui->LastName1->isChecked())
            { ui->tableView->setModel(tmp.search_LastName(LastName));}
}


void client::on_sort_clicked()
{
   if(ui->radioButton_CIN->isChecked())
   {
    ui->tableView_2->setModel(tmp.sort_CIN());
   }
   else if(ui->radioButton_lastname->isChecked())
   {
ui->tableView_2->setModel(tmp.sort_LastN());

    }
   else if(ui->radioButton_firstname->isChecked())
   {
       ui->tableView_2->setModel(tmp.sort_FirstN());
   }

}


void client::on_Export_clicked()
{
    QPdfWriter pdf("D:/Work/project QT/client/Client.pdf");

                     QPainter painter(&pdf);

                     int i = 4000;
                     painter.drawPixmap(QRect(100,400,2000,2000),QPixmap("D:/Work/project QT/image/logo.png"));
                     painter.drawText(3000,1500,"LISTE DES CLIENTS");
                     painter.setPen(Qt::red);
                     painter.setFont(QFont("Arial", 50));
                     painter.drawRect(2700,1200,1700,500);
                     painter.drawRect(0,3000,9600,500);
                     painter.setPen(Qt::black);
                     painter.setFont(QFont("Arial", 9));
                     painter.drawText(500,3300,"First Name");
                     painter.drawText(2000,3300,"Last Name");
                     painter.drawText(3500,3300,"Birthday");

                     painter.drawText(5000,3300,"CIN");
                     painter.drawText(6500,3300,"Email");
                     painter.drawText(8000,3300,"Event");

                     QSqlQuery query;
                     query.prepare("select * from client");
                     query.exec();
                     while (query.next())
                     {
                         painter.drawText(500,i,query.value(0).toString());
                         painter.drawText(2000,i,query.value(1).toString());
                         painter.drawText(3500,i,query.value(2).toString());
                         painter.drawText(5000,i,query.value(3).toString());
                         painter.drawText(6500,i,query.value(4).toString());
                         painter.drawText(8000,i,query.value(5).toString());

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

/*void client::on_Stat_clicked()
{
    s = new stat_combo();

  s->setWindowTitle("Statistique ");
  s->choix_pie();
  s->show();
}*/

void client::on_Excel_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                        tr("Excel Files (*.xls)"));
    QSqlQuery qry;
    if (fileName.isEmpty())
            return;

        ExportExcelObject obj(fileName, "client", ui->tableView);

        //colums to export
        obj.addField(-1,"Client","char(20)");
        obj.addField(0, "FirstName", "char(20)");
        obj.addField(1, "LastName", "char(20)");
        obj.addField(2, "Birthday", "char(20)");
        obj.addField(3, "CIN", "char(20)");
        obj.addField(4, "Email", "char(20)");
        obj.addField(5, "Event", "char(20)");

        //colums to export
/*qry.prepare("select * from employee");
if(qry.exec())
{
        obj.addField(7, "ID_emp", "char(20)");
        obj.addField(9, "Password", "char(20)");
        obj.addField(9, "Department", "char(20)");

        obj.addField(10, "Prenom", "char(20)");
        obj.addField(11, "Nom", "char(20)");
        obj.addField(12, "Salary", "char(20)");
        obj.addField(13, "ID_chef", "char(20)");
}
*/
        int retVal = obj.export2Excel();
        if( retVal > 0)
        {
            QMessageBox::information(this, tr("Done"),
                                     QString(tr("%1 records exported!")).arg(retVal)
                                     );
        }
}





void  client::browse()
{
    files.clear();

    QFileDialog dialog(this);
    dialog.setDirectory(QDir::homePath());
    dialog.setFileMode(QFileDialog::ExistingFiles);

    if (dialog.exec())
        files = dialog.selectedFiles();

    QString fileListString;
    foreach(QString file, files)
        fileListString.append( "\"" + QFileInfo(file).fileName() + "\" " );

    ui->file->setText( fileListString );

}
void   client::sendMail()
{
    Smtp* smtp = new Smtp("rayan.hadjalouane@esprit.tn","211JMT6094", "smtp.gmail.com");
        connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

        if( !files.isEmpty() )
            smtp->sendMail("rayan.hadjalouane@esprit.tn", ui->rcpt->text() , ui->subject->text(),ui->msg->text(), files );
        else
            smtp->sendMail("rayan.hadjalouane@esprit.tn", ui->rcpt->text() , ui->subject->text(),ui->msg->text());}


void client::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( 0, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}




void client::on_browse_clicked()
{
    browse();
}
void client::on_Send_clicked()
{
    sendMail();
}
