#include "events.h"
#include <QPdfWriter>
#include <QPainter>
#include <QDesktopServices>
#include <QPrinter>
#include <QFileDialog>
#include <QTextDocument>
#include <QMessageBox>
#include <QSystemTrayIcon>
Events::Events()
{

}
 Events::Events(int id_event ,QString a , QString  b, QString c, QString d, QDate e, float f, int k)
{
    this->id_event = id_event;
     this->id_emp = a ;
     this->nom_event = b ;
     this->type_event = c ;
     this->client_event = d;
     this->date_event = e ;
     this->cost_event = f ;
     this->guest_number = k ;

}
 QSqlQueryModel * Events::afficher()
 {

     QSqlQueryModel *model=new QSqlQueryModel();
     model->setQuery("SELECT * FROM EVENT ");
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID event"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("Event name"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("Date"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("Event type"));
     model->setHeaderData(4,Qt::Horizontal,QObject::tr("Client id"));
     model->setHeaderData(5,Qt::Horizontal,QObject::tr("Cost"));
     model->setHeaderData(6,Qt::Horizontal,QObject::tr("Guest number"));
     model->setHeaderData(7,Qt::Horizontal,QObject::tr("Reduction"));
     model->setHeaderData(8,Qt::Horizontal,QObject::tr("Id employe"));
     return model;
 }
     bool Events::ajouter()

     {
            QSqlQuery query;

            QString res1 = QString::number(cost_event);
            QString res2 = QString::number(guest_number);
             query.prepare("INSERT INTO EVENT(ID_EMP,EVENT_NAME,EVENT_TYPE,EVENT_CLIENT,EVENT_DATE,EVENT_COST,GUEST_NUMBER)""VALUES (:emp,:nom,:type,:client,:date,:cost,:guest)");
             query.bindValue(":emp",id_emp);
             query.bindValue(":nom",nom_event);
             query.bindValue(":type",type_event);
             query.bindValue(":client",client_event);
             query.bindValue(":date",date_event);
             query.bindValue(":cost",res1);
             query.bindValue(":guest",res2);
             return query.exec();
     }
     bool Events ::supprimer(QString id)
     {
     QSqlQuery query;
     QString res=QString(id);
     query.prepare("delete from  event where ID_event= :id");
     query.bindValue(":id",res);
     return query.exec();
     }
     bool Events::modifier(int id_event)
     {
         QSqlQuery query;
         QString res = QString::number(id_event);
         QString res1 = QString::number(cost_event);
         QString res2 = QString::number(guest_number);
         query.prepare("UPDATE EVENT SET EVENT_NAME=:nom,EVENT_TYPE=:type,EVENT_CLIENT=:client,EVENT_DATE=:date,EVENT_COST=:cost ,GUEST_NUMBER=:guest where ID_EVENT=:id");
         query.bindValue(":id",res);
         query.bindValue(":emp",id_emp);
         query.bindValue(":nom",nom_event);
         query.bindValue(":type",type_event);
         query.bindValue(":client",client_event);
         query.bindValue(":date",date_event);
         query.bindValue(":cost",res1);
         query.bindValue(":guest",res2);

         return query.exec();
     }


     QSqlQueryModel * Events::recherche(QString res)
     {


         QSqlQueryModel *model=new QSqlQueryModel();
         model->setQuery("SELECT * FROM event WHERE ( id_event LIKE '%"+res+"%' OR event_name LIKE '%"+res+"%' OR event_type LIKE '%"+res+"%' OR event_client LIKE '%"+res+"%' ) ");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID event"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("Event name"));
          model->setHeaderData(2,Qt::Horizontal,QObject::tr("Date"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("Event type"));
         model->setHeaderData(4, Qt::Horizontal, QObject::tr("Client id"));
         model->setHeaderData(5, Qt::Horizontal, QObject::tr("Cost"));
         model->setHeaderData(6, Qt::Horizontal, QObject::tr("Guest number"));
         model->setHeaderData(7, Qt::Horizontal, QObject::tr("Reduction"));
          model->setHeaderData(8,Qt::Horizontal,QObject::tr("Id employe"));

         return model;
     }
     QSqlQueryModel* Events::tri_id()
     {
         QSqlQueryModel *model=new QSqlQueryModel();
                 model->setQuery("select * from EVENT order by ID_EVENT");
                 model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID event"));
                 model->setHeaderData(1, Qt::Horizontal, QObject::tr("Event name"));
                  model->setHeaderData(2,Qt::Horizontal,QObject::tr("Date"));
                 model->setHeaderData(3, Qt::Horizontal, QObject::tr("Event type"));
                 model->setHeaderData(4, Qt::Horizontal, QObject::tr("Client id"));
                 model->setHeaderData(5, Qt::Horizontal, QObject::tr("Cost"));
                 model->setHeaderData(6, Qt::Horizontal, QObject::tr("Guest number"));
                 model->setHeaderData(7, Qt::Horizontal, QObject::tr("Reduction"));
                  model->setHeaderData(8,Qt::Horizontal,QObject::tr("Id employe"));
        return model;
     }


      QSqlQueryModel *Events::tri_date()
      {
          QSqlQueryModel *model=new QSqlQueryModel();
                  model->setQuery("select * from EVENT order by EVENT_DATE");
                  model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID event"));
                  model->setHeaderData(1, Qt::Horizontal, QObject::tr("Event name"));
                   model->setHeaderData(2,Qt::Horizontal,QObject::tr("Date"));
                  model->setHeaderData(3, Qt::Horizontal, QObject::tr("Event type"));
                  model->setHeaderData(4, Qt::Horizontal, QObject::tr("Client id"));
                  model->setHeaderData(5, Qt::Horizontal, QObject::tr("Cost"));
                  model->setHeaderData(6, Qt::Horizontal, QObject::tr("Guest number"));
                  model->setHeaderData(7, Qt::Horizontal, QObject::tr("Reduction"));
                   model->setHeaderData(8,Qt::Horizontal,QObject::tr("Id employe"));
         return model;
          }

      QSqlQueryModel *Events::tri_type()
      {
          QSqlQueryModel *model=new QSqlQueryModel();
                  model->setQuery("select * from EVENT order by EVENT_TYPE");
                  model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID event"));
                  model->setHeaderData(1, Qt::Horizontal, QObject::tr("Event name"));
                   model->setHeaderData(2,Qt::Horizontal,QObject::tr("Date"));
                  model->setHeaderData(3, Qt::Horizontal, QObject::tr("Event type"));
                  model->setHeaderData(4, Qt::Horizontal, QObject::tr("Client id"));
                  model->setHeaderData(5, Qt::Horizontal, QObject::tr("Cost"));
                  model->setHeaderData(6, Qt::Horizontal, QObject::tr("Guest number"));
                  model->setHeaderData(7, Qt::Horizontal, QObject::tr("Reduction"));
                   model->setHeaderData(8,Qt::Horizontal,QObject::tr("Id employe"));
         return model;
          }
      void Events::statistique(QVector<double>* ticks,QVector<QString> *labels)
      {
          QSqlQuery q;
          int i=0;
          q.exec("select Event_name from EVENT");
          while (q.next())
          {
              QString id_event = q.value(0).toString();
              i++;
              *ticks<<i;
              *labels <<id_event;
          }
      }
      void Events::CREATION_PDF()
      {
          QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
          if (QFileInfo(fileName).suffix().isEmpty())
              { fileName.append(".pdf"); }

          QPrinter printer(QPrinter::PrinterResolution);
          printer.setOutputFormat(QPrinter::PdfFormat);
          printer.setPaperSize(QPrinter::A4);
          printer.setOutputFileName(fileName);

          QTextDocument doc;
          QSqlQuery q;
          q.prepare("SELECT * FROM EVENT ");
          q.exec();
          QString pdf="<br> <h1  style='color:blue'>LISTE DES EVENT  <br></h1>\n <br> <table>  <tr>  <th>CIN </th> <th>NOM </th> <th>PRENOM  </th> <th>AGE  </th><th>TEL  </th><th>ADRESS   </th> </tr>" ;
      //br traja ll star oel tr tzidlek colonne th tzidlek ligne h1 asghrr size o akbr size h6 //

          while ( q.next())
              {

              pdf= pdf+ " <br> <tr> <td>"+ q.value(0).toString()+" " + q.value(1).toString() +"</td>   <td>" +q.value(2).toString() +" <td>" +q.value(3).toString() +" <td>" +q.value(4).toString() +" <td>" +q.value(5).toString() +" "" " "</td> </td>" ;
          }
          doc.setHtml(pdf);
          doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
          doc.print(&printer);


      }


      float Events::alerte()
      {
          int i=0;
          QSqlQuery query("SELECT EVENT_COST FROM EVENT");
          while (query.next())
          {

              if (query.value(0).toFloat()<1000)
              {
                  i++;
              }

          }
          return i;
      }



