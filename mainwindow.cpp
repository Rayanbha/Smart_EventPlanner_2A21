#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView_event->setModel(etmp.afficher());
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
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_add_event_clicked()
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

        }
            else
               { QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                            QObject::tr("ajout failed.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel); }
}
void MainWindow::on_pushButton_delete_event_clicked()
{
  QString id=ui->lineEdit_id_event->text();
     bool test=etmp.supprimer(id);
     if (test)
     {
         ui->tableView_event->setModel(etmp.afficher());
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


void MainWindow::on_pushButton_modify_event_clicked()
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
