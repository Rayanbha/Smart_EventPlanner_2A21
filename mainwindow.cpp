#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "map.h"
#include <QtCharts>
#include <QChartView>
#include<QDesktopServices>//class contient service mtaa lien google
#include<QUrl>//class tasnaa bih lurl
#include <QPieSeries>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     ui->tableView_provider->setModel(ptmp.afficher());
     ui->lineEdit_phone_provider->setValidator( new QIntValidator(0, 999999, this));
     QRegularExpression rx("^[A-Za-z]+$");//controle de saisie.

             QValidator *validator = new QRegularExpressionValidator(rx, this);
             ui->lineEdit_first_name_provider->setValidator(validator);
             ui->lineEdit_last_name_provider->setValidator(validator);
             ui->lineEdit_product_type_provider->setValidator(validator);
             ui->lineEdit_quality_provider->setValidator(validator);
             //this->setWindowTitle("MainWindow");
                 QPieSeries *series =new QPieSeries ;

                 QList<qreal> list= stat_budget();
                  QList<QString> list2=stat_bud();

                  for(int i=0 ;i<list.size();i++)
                  {
                       series->append(list2[i],list[i]);//les deux cercles

                  }
                  QChart *chart =new QChart;
                          chart->addSeries(series);//afficher
                          chart->setTitle("statistiques");
                           QChartView *chartview= new QChartView(chart);


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


       int num=ui->lineEdit_phone_provider->text().toInt();
float prix=ui->lineEdit_price_provider->text().toFloat();
QString qualite=ui->lineEdit_quality_provider->text();

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

void MainWindow::on_recherche_clicked()
{
    Provider ptmp;
           QString nom=ui->n->text();//saisie de lutilisateur du nom
               QString prenom=ui->p->text();//saisie de lutilisateur du prenom
                QString type=ui->t->text();//saisie de lutilisateur du type
                ui->tableView_provider->setModel(ptmp.rech(nom,prenom,type));
}

void MainWindow::on_pushButton_sort_providers_clicked()
{
    QString tri=ui->comboBox->currentText();//ce qui a choisi lutilisateur

                        if(tri=="nom"){
                      ui->tableView_provider->setModel(ptmp.ordre_name());}
                        else if(tri=="numero"){
                            ui->tableView_provider->setModel(ptmp.ordre_num());}

    }

/*void MainWindow::on_pushButton_clicked()
{
    m= new map;
    m->show();
}
*/

void MainWindow::on_pushButton_Stat_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
            model->setQuery("select * from FOURNISSEUR where prix < 100 ");
            float prix=model->rowCount();
            model->setQuery("select * from FOURNISSEUR where prix  between 100 and 1000 ");
            float prixx=model->rowCount();
            model->setQuery("select * from FOURNISSEUR where prix >1000 ");
            float prixxx=model->rowCount();
            float total=prix+prixx+prixxx;
            QString a=QString("moins de 100 DT "+QString::number((prix*100)/total,'f',2)+"%" );//bech ntal3ou pourcentage
            QString b=QString("entre 100 et 1000 DT "+QString::number((prixx*100)/total,'f',2)+"%" );
            QString c=QString("+1000 DT"+QString::number((prixxx*100)/total,'f',2)+"%" );
            QPieSeries *series = new QPieSeries();
            series->append(a,prix);
            series->append(b,prixx);
            series->append(c,prixxx);
                    if (prix!=0)
                    {QPieSlice *slice = series->slices().at(0);
                     slice->setLabelVisible();
                     slice->setPen(QPen());}
                    if ( prixx!=0)
                    {
                             // Add label, explode and define brush for 2nd slice
                             QPieSlice *slice1 = series->slices().at(1);
                             //slice1->setExploded();
                             slice1->setLabelVisible();
                    }
                    if(prixxx!=0)
                    {
                             // Add labels to rest of slices
                             QPieSlice *slice2 = series->slices().at(2);
                             //slice1->setExploded();
                             slice2->setLabelVisible();
                    }
                            // Create the chart widget
                            QChart *chart = new QChart();
                            // Add data to chart with title and hide legend
                            chart->addSeries(series);
                            chart->setTitle("Pourcentage Par Prix :Nombre Des Fournisseurs "+ QString::number(total));
                            chart->legend()->hide();
                            // Used to display the chart
                            QChartView *chartView = new QChartView(chart);
                            chartView->setRenderHint(QPainter::Antialiasing);
                            chartView->resize(1000,500);
                            chartView->show();
}

void MainWindow::on_pushButton_add_provider_5_clicked()
{
    QPdfWriter pdf("C:\\Users\\Hazem\\OneDrive\\Bureau\\Projet qt\\PDF_Fournisseurs.pdf");

       QPainter painter(&pdf); //tjib beha l .pdf
       int i = 4000;
              painter.setPen(Qt::red);
              painter.setFont(QFont("Time New Roman", 25));
              painter.drawText(3000,1400,"Liste Des Fournisseurs");
              painter.setPen(Qt::black);
              painter.setFont(QFont("Time New Roman", 15));
              painter.drawRect(100,3000,9400,500);
              painter.setFont(QFont("Time New Roman", 9));
              painter.drawText(400,3300,"id");
              painter.drawText(1350,3300,"Nom");
              painter.drawText(2200,3300,"Prenom");
              painter.drawText(3400,3300,"Type");
              painter.drawText(4400,3300,"Adress");
              painter.drawText(6200,3300,"numero téléphone");
              painter.drawText(7600,3300,"prix");
              painter.drawText(8500,3300,"qualité");
              painter.drawRect(100,3000,9400,9000);

              QSqlQuery query;
              query.prepare("select * from FOURNISSEUR");
              query.exec();
              while (query.next())
              {
                  painter.drawText(400,i,query.value(0).toString());
                  painter.drawText(1350,i,query.value(1).toString());
                  painter.drawText(2300,i,query.value(2).toString());
                  painter.drawText(3400,i,query.value(3).toString());
                  painter.drawText(4400,i,query.value(4).toString());
                  painter.drawText(6200,i,query.value(5).toString());
                  painter.drawText(7600,i,query.value(6).toString());
                  painter.drawText(8500,i,query.value(7).toString());

                 i = i + 350;
              }
              QMessageBox::information(this, QObject::tr("PDF Enregistré!"),
              QObject::tr("PDF Enregistré!.\n" "Click Cancel to exit."), QMessageBox::Cancel);
    }

void MainWindow::on_pushButton_location_clicked()//fonction
{
    QString link="https://www.google.com/maps/@36.8800893,10.1927418,14z";//thot lien lil fonction eli thb aaleha expl lien google
    QDesktopServices::openUrl(QUrl(link));//tasnaa objet type qrl wyekhou comme parametre lien eli snaaneh l 259 bch nestaaml url eli bch ykhalini
    //open url bch tekhou lobjet eli snaatou



}
