#include "hafla.h"
#include "ui_hafla.h"
#include <QPdfWriter>
#include <QPainter>
#include <QDesktopServices>
#include <QPrinter>
#include <QFileDialog>
#include <QTextDocument>
#include <QMessageBox>
#include <QSystemTrayIcon>
hafla::hafla(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::hafla)
{
    ui->setupUi(this);
    QPixmap pix("C:/Qt/bg");
    ui->label_bg->setPixmap(pix);
    ui->tableView_event->setModel(etmp.afficher());
    ui->comboBox->setModel(etmp.afficher());
    QValidator *validator_guest = new QIntValidator(10, 999, this);
    QValidator *validator_prix = new QIntValidator(0, 50000, this);

    // the edit lineedit will only accept integers between 100 and 999

    ui->lineEdit_cost_event->setValidator(validator_prix);
    ui->lineEdit_number_event->setValidator(validator_guest);

    QRegularExpression rx("^[A-Za-z]+$");

    QValidator *validator = new QRegularExpressionValidator(rx, this);
    ui->lineEdit_name_event->setValidator(validator);
    ui->lineEdit_type_event->setValidator(validator);
    ui->lineEdit_clientevent->setValidator(validator);
 //ui->tabWidgetf->setCurrentIndex(0);
     ui->tableView_event->setModel(etmp.afficher());

}

hafla::~hafla()
{
    delete ui;
}
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

   /* void Events::CREATION_PDF()
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

      }*/

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
      void hafla::on_pushButton_add_event_clicked()
      {

          QString id_emp = ui->lineEdit_idemp_event->text();
          QString event_name = ui->lineEdit_name_event->text();
          QString event_type = ui->lineEdit_type_event->text();
          QString Client_name = ui->lineEdit_clientevent->text();
          QDate Date = ui->dateEdit_event->date();
          float cost = ui->lineEdit_cost_event->text().toFloat();
          int Guest_number = ui ->lineEdit_number_event->text().toInt();
          Events etmp (1,id_emp,event_name,event_type,Client_name,Date,cost,Guest_number);
          bool test =  etmp.ajouter();
          if(test)
                  {
                      QMessageBox::information(nullptr, QObject::tr("database is open"),
                                  QObject::tr("ajout successful.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
                      ui->tableView_event->setModel(etmp.afficher());
                       ui->comboBox->setModel(etmp.afficher());

              }
                  else
                     { QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                                  QObject::tr("ajout failed.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel); }
      }
      void hafla::on_pushButton_delete_event_clicked()
      {
        QString id=ui->lineEdit_id_event->text();
           bool test=etmp.supprimer(id);
           if (test)
           {
               ui->tableView_event->setModel(etmp.afficher());
                ui->comboBox->setModel(etmp.afficher());
              QMessageBox :: information (nullptr, QObject ::tr("OK"),
                            QObject ::tr("suppression effectué\n"
                                         "click cancel to exit"),
                       QMessageBox:: Cancel);

          }
           else
           {
               QMessageBox::critical(nullptr,QObject::tr("not ok"),
                                    QObject::tr("try again.\n"
                                                "click cancel to exit."),QMessageBox::Cancel);
           }
      }


      void hafla::on_pushButton_modify_event_clicked()
      {
         int id=ui->lineEdit_id_event->text().toUInt();
         QString name=ui->lineEdit_name_event->text();
         QString type=ui->lineEdit_type_event->text();
         QString client=ui->lineEdit_clientevent->text();
         QDate date = ui->dateEdit_event->date();
         float cost=ui->lineEdit_cost_event->text().toInt();
         int guest=ui->lineEdit_number_event->text().toInt();
         QString id_emp=ui->lineEdit_idemp_event->text();


                   Events etmp(0,id_emp,name,type,client,date,cost,guest);
                bool test=etmp.modifier (id);

                if (test)

                {

                       ui->tableView_event->setModel(etmp.afficher());
                        ui->comboBox->setModel(etmp.afficher());

                    QMessageBox :: information (nullptr, QObject ::tr("OK"),

                                 QObject ::tr("modifier effectué\n"

                                              "click cancel to exit"),

                            QMessageBox:: Cancel);
            }

                else

                {

                    QMessageBox::critical(nullptr,QObject::tr("not ok"),

                                         QObject::tr("try again.\n"

                                                     "click cancel to exit."),QMessageBox::Cancel);

                }
      }

      void hafla::on_tableView_event_activated(const QModelIndex &index)
      {
          QString val=ui->tableView_event->model()->data(index).toString();

                      QSqlQuery query;

                      query.prepare("select * from EVENT where id_event='"+val+"'");
                      {
                          while(query.next())
                          {

                               ui->lineEdit_id_event->setText(query.value(1).toString());
                              ui->dateEdit_event->setDate(query.value(2).toDate());
                               ui->lineEdit_name_event->setText(query.value(3).toString());
                               ui->lineEdit_type_event->setText(query.value(4).toString());
                               ui->lineEdit_cost_event->setText(query.value(5).toString());
                               ui->lineEdit_number_event->setText(query.value(6).toString());



                          }
                      }
      }






      void hafla::on_TRI_NAME_clicked()
      {
           ui->tableView_event->setModel(etmp.tri_id());
      }

      void hafla::on_TRI_DATE_clicked()
      {
          ui->tableView_event->setModel(etmp.tri_date());
      }

      void hafla::on_TRI_TYPE_clicked()
      {
          ui->tableView_event->setModel(etmp.tri_type());
      }

     void hafla::on_pushButton_pdf_event_clicked()
      {
          QString strStream;
                  strStream = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
                      if (QFileInfo(strStream).suffix().isEmpty())
                          { strStream.append(".pdf"); }

                      QPrinter printer(QPrinter::PrinterResolution);
                      printer.setOutputFormat(QPrinter::PdfFormat);
                      printer.setPaperSize(QPrinter::A4);
                      printer.setOutputFileName(strStream);

                            QTextStream out(&strStream);

                            const int rowCount = ui->tableView_event->model()->rowCount();
                            const int columnCount = ui->tableView_event->model()->columnCount();
                            QString TT = QDateTime::currentDateTime().toString();
                            out <<"<html>\n"
                                  "<head>\n"
                                   "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                                << "<title>ERP - COMmANDE LIST<title>\n "
                                << "</head>\n"
                                "<body bgcolor=#ffffff link=#5000A0>\n"
                                   "<h1 style=\"text-align: center;\"><strong> "+TT+"</strong></h1>"
                                  +"<img src=C:C:\\Users\\MSI\\Desktop\\EVENTs\\pdf\\logo_projet />" //path
                                "<h1 style=\"text-align: center;\"><strong> ****LISTE DES evenement **** </strong></h1>"

                                "<table style=\"text-align: center; font-size: 10px;\" border=1>\n "
                                  "</br> </br>";
                            // headers
                            out << "<thead><tr bgcolor=#d6e5ff>";
                            for (int column = 0; column < columnCount; column++)
                                if (!ui->tableView_event->isColumnHidden(column))
                                    out << QString("<th>%1</th>").arg(ui->tableView_event->model()->headerData(column, Qt::Horizontal).toString());
                            out << "</tr></thead>\n";

                            // data table
                            for (int row = 0; row < rowCount; row++) {
                                out << "<tr>";
                                for (int column = 0; column < columnCount; column++)
                              {
                                    if (!ui->tableView_event->isColumnHidden(column)) {
                                        QString data =ui->tableView_event->model()->data(ui->tableView_event->model()->index(row, column)).toString().simplified();
                                        out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;")); //pas compriis
                                    }
                                }
                                out << "</tr>\n";
                            }
                            out <<  "</table>\n"
                                "</body>\n"
                                "</html>\n";

                            QTextDocument document;
                            document.setHtml(strStream);
                            document.print(&printer);
      }

      ///////statistique
     QVector<double> hafla::statistiques()
      {
          QSqlQuery q;
          QVector<double> stat(5);
          stat[0]=0;
          stat[1]=0;
          stat[2]=0;
          stat[3]=0;
          stat[4]=0;
          q.prepare("SELECT EVENT_COST FROM EVENT WHERE EVENT_COST<=10000");
          q.exec();
          while (q.next())
          {
              stat[0]++;

          }
          q.prepare("SELECT EVENT_COST FROM EVENT WHERE EVENT_COST>10000 and EVENT_COST<=20000");
          q.exec();
          while (q.next())
          {
              stat[1]++;

          }
          q.prepare("SELECT EVENT_COST FROM EVENT WHERE EVENT_COST>20000 and EVENT_COST<=30000");
          q.exec();
          while (q.next())
          {
              stat[2]++;

          }
          q.prepare("SELECT EVENT_COST FROM EVENT WHERE EVENT_COST>30000 and EVENT_COST<=40000");
          q.exec();
          while (q.next())
          {
              stat[3]++;

          }
          q.prepare("SELECT EVENT_COST FROM EVENT WHERE EVENT_COST>40000 and EVENT_COST<=50000 ");
          q.exec();
          while (q.next())
          {
              stat[4]++;

          }
          return stat;
      }

      void hafla::makePlot()
      {
          // prepare data:
          QVector<double> x3(5), y3(20);
          for (int i=0; i<x3.size(); ++i)
          {
            x3[i] = i+1;

          }
          for (int i=0; i<y3.size(); ++i)
          {
            y3[i] = i+1;

          }

          QCPBars *bars1 = new QCPBars(ui->customplot->xAxis, ui->customplot->yAxis);
          bars1->setWidth(2/(double)x3.size());
          bars1->setData(x3, hafla::statistiques());////fonction statistiques
          bars1->setPen(Qt::NoPen);
          bars1->setBrush(QColor(200, 40, 60, 170));
          ui->customplot->replot();

          // move bars above graphs and grid below bars:
          ui->customplot->addLayer("abovemain", ui->customplot->layer("main"), QCustomPlot::limAbove);
          ui->customplot->addLayer("belowmain", ui->customplot->layer("main"), QCustomPlot::limBelow);
          ui->customplot->xAxis->grid()->setLayer("belowmain");
          ui->customplot->yAxis->grid()->setLayer("belowmain");

          // set some pens, brushes and backgrounds:
          QVector<double> Ticks;
          Ticks<<1<<2<<3<<4<<5<<6<<7;//////
          QVector<QString> labels;
          labels<<"0-10M"<<"10M-20M"<<"20M-30M"<<"30M-40M"<<"40M-50M";////////
          QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
          textTicker->addTicks(Ticks,labels);
          ui->customplot->xAxis->setTicker(textTicker);
          ui->customplot->xAxis->setSubTicks(false);
          ui->customplot->xAxis->setTickLength(0,4);
          ui->customplot->xAxis->setBasePen(QPen(Qt::white, 1));
          ui->customplot->yAxis->setBasePen(QPen(Qt::white, 1));
          ui->customplot->xAxis->setTickPen(QPen(Qt::transparent, 1));
          ui->customplot->yAxis->setTickPen(QPen(Qt::white, 1));
          ui->customplot->xAxis->setSubTickPen(QPen(Qt::transparent, 1));
          ui->customplot->yAxis->setSubTickPen(QPen(Qt::transparent, 1));
          ui->customplot->xAxis->setTickLabelColor(Qt::white);
          ui->customplot->yAxis->setTickLabelColor(Qt::white);
          ui->customplot->xAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
          ui->customplot->yAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
          ui->customplot->xAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
          ui->customplot->yAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
          ui->customplot->xAxis->grid()->setSubGridVisible(true);
          ui->customplot->yAxis->grid()->setSubGridVisible(true);
          ui->customplot->xAxis->grid()->setZeroLinePen(Qt::NoPen);
          ui->customplot->yAxis->grid()->setZeroLinePen(Qt::NoPen);
          ui->customplot->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
          ui->customplot->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
          QLinearGradient plotGradient;
          plotGradient.setStart(0, 0);
          plotGradient.setFinalStop(0, 350);
          plotGradient.setColorAt(0, QColor(00, 50, 80));
          plotGradient.setColorAt(1, QColor(10, 20, 50));
          ui->customplot->setBackground(plotGradient);
          QLinearGradient axisRectGradient;
          axisRectGradient.setStart(0, 0);
          axisRectGradient.setFinalStop(0, 350);
          axisRectGradient.setColorAt(0, QColor(10, 50, 80));//
          axisRectGradient.setColorAt(1, QColor(0, 0, 30));
          ui->customplot->axisRect()->setBackground(axisRectGradient);

          ui->customplot->rescaleAxes();
          ui->customplot->xAxis->setRange(0, 7);
          ui->customplot->yAxis->setRange(0, 10);


      }

      void hafla::on_pushButton_statistic_event_clicked()
      {
          ui->customplot->clearPlottables();
          hafla::makePlot();
          hafla::makePlot();
      }



      void hafla::on_tableView_event_doubleClicked(const QModelIndex &index)
      {
          int id=ui->tableView_event->model()->data(ui->tableView_event->model()->index(ui->tableView_event->currentIndex().row(),0)).toInt();
          QString res = QString::number(id);
          ui->lineEdit_id_event->setText(res);
           QString nom;
           nom=ui->tableView_event->model()->data(ui->tableView_event->model()->index(ui->tableView_event->currentIndex().row(),8)).toString();
          ui->lineEdit_idemp_event->setText(nom);

          QString cap=ui->tableView_event->model()->data(ui->tableView_event->model()->index(ui->tableView_event->currentIndex().row(),1)).toString();

          ui->lineEdit_name_event->setText(cap);
         QString idm=ui->tableView_event->model()->data(ui->tableView_event->model()->index(ui->tableView_event->currentIndex().row(),3)).toString();
         ui->lineEdit_type_event->setText(idm);
         QString idma = ui->tableView_event->model()->data(ui->tableView_event->model()->index(ui->tableView_event->currentIndex().row(),4)).toString();
         ui->lineEdit_clientevent->setText(idma);

          float cost = ui->tableView_event->model()->data(ui->tableView_event->model()->index(ui->tableView_event->currentIndex().row(),5)).toFloat();
      QString res3 = QString::number(cost);
         ui->lineEdit_number_event->setText(res3);
         float guest = ui->tableView_event->model()->data(ui->tableView_event->model()->index(ui->tableView_event->currentIndex().row(),6)).toFloat();
      QString res4 = QString::number(guest);
        ui->lineEdit_cost_event->setText(res4);

      }
      void hafla::on_pushButtontop_event_2_clicked()
      {
          QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
              notifyIcon->show();


          if (etmp.alerte()<1000)
                      {
                          QString notif=QString::number(etmp.alerte())+" low priority events.\n""Click Ok to exit.";
                          notifyIcon->showMessage("Notification Salle ","low priority event",QSystemTrayIcon::Information,15000);
                          QMessageBox::warning(nullptr, QObject::tr("Alerte"),notif, QMessageBox::Ok);
                      }
              else QMessageBox::information(nullptr, QObject::tr("OK"), QObject::tr("event high priority\n""Click Ok to exit."), QMessageBox::Ok);
      }
      void hafla::on_pushButton_reduction_event_clicked()
      {
          int id = ui->comboBox->currentText().toInt();
          // Providing a seed value
              srand((unsigned) time(NULL));

              // Get a random number
              float random = rand() % 50;
          QLineEdit * e = new QLineEdit();
         e = ui->lineEdit_reduction;
         e->setText(QString::number(random)+"%");
         e->setStyleSheet("font: 80px");
         e->setReadOnly(true);
         QSqlQuery query;
         QString res = QString::number(id);
         QString res1 = QString::number(random);
         query.prepare("UPDATE EVENT SET reduction=:red where ID_EVENT=:id");
         query.bindValue(":id",res);
         query.bindValue(":red",res1);
         bool test  = query.exec();
         if (test)
         {
             QMessageBox::information(nullptr, QObject::tr("OK"), QObject::tr(" reduction modifié"), QMessageBox::Ok);
         }
             else
         {
             QMessageBox::critical(nullptr, QObject::tr("OK"), QObject::tr(" reduction non modifié !!"), QMessageBox::Ok);
          }

      }


      void hafla::on_search_event_textChanged(const QString &arg1)
      {
          ui->tableView_event->setModel(etmp.recherche(arg1));
      }
