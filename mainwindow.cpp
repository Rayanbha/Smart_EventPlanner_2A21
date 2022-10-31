#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     ui->tableView_provider->setModel(ptmp.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_add_provider_clicked()
{

       QString nom=ui->lineEdit_first_name_provider->text();
       QString prenom=ui->lineEdit_last_name_provider->text();
       QString type=ui->lineEdit_product_type_provider->text();
       QString adresse=ui->lineEdit_adress_provider->text();
       QString qualite=ui->lineEdit_quality_provider->text();
       float prix=ui->lineEdit_price_provider->text().toFloat();
       int num=ui->lineEdit_phone_provider->text().toInt();


       Provider p(0,nom ,prenom,type,adresse,num,prix,qualite );
       bool test=p.ajouter();
       if (test)
       {


           QMessageBox :: information (nullptr, QObject ::tr("OK"),
                        QObject ::tr("Ajout effectué\n"
                                     "click cancel to exit"),
                   QMessageBox:: Cancel);
           ui->tableView_provider->setModel(ptmp.afficher());

   }
       else
       {
           QMessageBox::critical(nullptr,QObject::tr("not ok"),
                                QObject::tr("try again.\n"
                                            "click cancel to exit."),QMessageBox::Cancel);
       }
}

void MainWindow::on_pushButton_modify_provider_clicked()
{
    QString id = ui->lineEdit_id_modify->text();
    QString nom=ui->lineEdit_first_name_provider->text();
    QString prenom=ui->lineEdit_last_name_provider->text();
    QString type=ui->lineEdit_product_type_provider->text();
    QString adresse=ui->lineEdit_adress_provider->text();
    QString qualite=ui->lineEdit_quality_provider->text();
    float prix=ui->lineEdit_price_provider->text().toFloat();
    int num=ui->lineEdit_phone_provider->text().toInt();

    Provider p(0,nom ,prenom,type,adresse,num,prix,qualite );
    bool test=p.modifier(id);
    if (test)
    {


        QMessageBox :: information (nullptr, QObject ::tr("OK"),
                     QObject ::tr("modification effectué\n"
                                  "click cancel to exit"),
                QMessageBox:: Cancel);
        ui->tableView_provider->setModel(ptmp.afficher());

}
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("not ok"),
                             QObject::tr("try again.\n"
                                         "click cancel to exit."),QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_delete_providert_clicked()
{
    QString id = ui->lineEdit_id_modify->text();

    bool test=ptmp.supprimer(id);
    if (test)
    {


        QMessageBox :: information (nullptr, QObject ::tr("OK"),
                     QObject ::tr("suppression effectué\n"
                                  "click cancel to exit"),
                QMessageBox:: Cancel);
        ui->tableView_provider->setModel(ptmp.afficher());

}
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("not ok"),
                             QObject::tr("try again.\n"
                                         "click cancel to exit."),QMessageBox::Cancel);
    }
}

void MainWindow::on_tableView_provider_activated(const QModelIndex &index)
{

}
