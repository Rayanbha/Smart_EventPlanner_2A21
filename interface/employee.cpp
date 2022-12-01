#include "employee.h"
#include "ui_employee.h"


employee::employee(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::employee)
{

    ui->setupUi(this);
    ui->lineEdit_salary->setValidator(new QIntValidator(100,10000,this)); //salary should be between 100 and 10000
    QPixmap pix("C:/Qt/background");
    ui->label_pic->setPixmap(pix);
    QPixmap pix2("C:/Qt/background");
    ui->label_pic2->setPixmap(pix2);
    ui->tableView1->setModel(Etmp.afficher());
    //STATISTIQUES
    QSqlQuery q1,q2,q3,q4,q5;
    qreal tot=0,c1=0,c2=0,c3=0,c4=0;
    q1.prepare("SELECT * FROM employee");
    q1.exec();
    q2.prepare("SELECT * FROM employee WHERE departement='EM'");
    q2.exec();
    q3.prepare("SELECT * FROM employee WHERE departement='SM'");
    q3.exec();
    q4.prepare("SELECT * FROM employee WHERE departement='CM'");
    q4.exec();
    q5.prepare("SELECT * FROM employee WHERE departement='RH'");
    q5.exec();
    while (q1.next()){tot++;}
    while (q2.next()){c1++;}
    while (q3.next()){c2++;}
    while (q4.next()){c3++;}
    while (q5.next()){c4++;}

    QBarSet *set1 = new QBarSet("EM");
    QBarSet *set2 = new QBarSet("SM");
    QBarSet *set3 = new QBarSet("CM");
    QBarSet *set4 = new QBarSet("RH");
    *set1 << c1 ;
    *set2 << c2 ;
    *set3 << c3 ;
    *set4 << c4 ;
    QBarSeries *series = new QBarSeries();
    series->append(set1);
    series->append(set2);
    series->append(set3);
    series->append(set4);
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("STATISTIQUE");
    chart->setAnimationOptions(QChart::AllAnimations);
    QStringList categories;
    categories << "STATISTIQUE";
    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis->append(categories);
    chart->createDefaultAxes();
    chart->setAxisX(axis, series);
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setMinimumSize(281,311);
    chartView->setParent(ui->tableView2);
    QPalette pal = qApp->palette();
    qApp->setPalette(pal);


}



employee::~employee()
{
    delete ui;
}
employe::employe(){}
employe::employe(QString ID_emp,QString departement,QString first_name,QString password,QString last_name,QString ID_chef,int salary)
{
this->ID_emp=ID_emp;
this->departement=departement;
this->first_name=first_name;
this->password=password;
this->last_name=last_name;
this->ID_chef=ID_chef;
this->salary=salary;
}
bool employe::ajouter()
{
   QSqlQuery query;
   QString res = QString::number(salary);
   query.prepare("insert into employee (ID_emp,departement,first_name,password,last_name,ID_chef,salary)" "values (:ID_emp, :departement, :first_name, :password, :last_name, :ID_chef, :salary)");
   query.bindValue(":ID_emp", ID_emp);
   query.bindValue(":departement", departement);
   query.bindValue(":first_name", first_name);
   query.bindValue(":password", password);
   query.bindValue(":last_name", last_name);
   query.bindValue(":ID_chef", ID_chef);
   query.bindValue(":salary", res);
   return query.exec();
}
QSqlQueryModel * employe::afficher()
{
QSqlQueryModel * model=new QSqlQueryModel();
model->setQuery("select * from employee");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID emp"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("departement"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("first name"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("password"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("last name"));
model->setHeaderData(5,Qt::Horizontal,QObject::tr("salary"));
model->setHeaderData(6,Qt::Horizontal,QObject::tr("ID chef"));

return model;
}
bool employe::supprimer(QString ID_emp)
{
QSqlQuery query;
query.prepare("Delete from  employee where ID_emp= :id");
query.bindValue(":id",ID_emp);
return query.exec();
}
bool employe::modifier(QString ID_emp)
{
QSqlQuery query;
QString res = QString::number(salary);
query.prepare("update employee set departement='"+departement+"', first_name='"+first_name+"', last_name='"+last_name+"', password='"+password+"', salary='"+res+"', ID_chef='"+ID_chef+"'where ID_emp='"+ID_emp+"'");
query.bindValue(":departement", departement);
query.bindValue(":first_name", first_name);
query.bindValue(":password", password);
query.bindValue(":last_name", last_name);
query.bindValue(":ID_chef", ID_chef);
query.bindValue(":salary", res);
return query.exec();

}
QSqlQueryModel * employe::searchID(QString ID_emp)
{
 QSqlQueryModel * model=new QSqlQueryModel();
 model->setQuery("select * from employee where ID_emp like '"+ID_emp+"%'");
 model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID emp"));
 model->setHeaderData(1,Qt::Horizontal,QObject::tr("departement"));
 model->setHeaderData(2,Qt::Horizontal,QObject::tr("first name"));
 model->setHeaderData(3,Qt::Horizontal,QObject::tr("password"));
 model->setHeaderData(4,Qt::Horizontal,QObject::tr("last name"));
 model->setHeaderData(5,Qt::Horizontal,QObject::tr("salary"));
 model->setHeaderData(6,Qt::Horizontal,QObject::tr("ID chef"));
 return model;
}
QSqlQueryModel * employe::searchF(QString first_name)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from employee where first_name like '"+first_name+"%'");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID emp"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("departement"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("first name"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("password"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("last name"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("salary"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("ID chef"));
    return model;
}
QSqlQueryModel * employe::searchL(QString last_name)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from employee where last_name like '"+last_name+"%'");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID emp"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("departement"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("first name"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("password"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("last name"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("salary"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("ID chef"));
    return model;
}
QSqlQueryModel * employe::sort_Lastn()
{

    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from employee order by Last_name");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID emp"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("departement"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("first name"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("password"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("last name"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("salary"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("ID chef"));

    return model;

}
QSqlQueryModel * employe::sort_firstn()
{

    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from employee order by first_name");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID emp"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("departement"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("first name"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("password"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("last name"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("salary"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("ID chef"));

    return model;

}
QSqlQueryModel * employe::sort_salary()
{

    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from employee order by salary");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID emp"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("departement"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("first name"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("password"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("last name"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("salary"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("ID chef"));

    return model;
}
void employee::on_pushButton_ajouter_clicked()
{
   QString ID_emp=ui->lineEdit_ID->text();
   QString first_name=ui->lineEdit_first->text();
   QString last_name=ui->lineEdit_last->text();
   QString password=ui->lineEdit_password->text();
   QString departement=ui->box->currentText();
   QString ID_chef=ui->lineEdit_chef->text();
   int salary=ui->lineEdit_salary->text().toInt();
   if(!ID_emp.isEmpty()&&!first_name.isEmpty()&&!last_name.isEmpty()&&!password.isEmpty()&&!ID_chef.isEmpty())
   {
   if(ID_emp.length()<11&&ID_emp.length()>5&&first_name.length()<16&&last_name.length()<16&&password.length()<13&&ID_chef.length()<11&&ID_chef.length()>5&&departement.length()<3)
    {
   employe e(ID_emp, departement, first_name, password, last_name, ID_chef, salary);
   bool test=e.ajouter();
     if(test)
     {
         ui->tableView1->setModel(Etmp.afficher());
//STATISTIQUES
         QSqlQuery q1,q2,q3,q4,q5;
         qreal tot=0,c1=0,c2=0,c3=0,c4=0;
         q1.prepare("SELECT * FROM employee");
         q1.exec();
         q2.prepare("SELECT * FROM employee WHERE departement='EM'");
         q2.exec();
         q3.prepare("SELECT * FROM employee WHERE departement='SM'");
         q3.exec();
         q4.prepare("SELECT * FROM employee WHERE departement='CM'");
         q4.exec();
         q5.prepare("SELECT * FROM employee WHERE departement='RH'");
         q5.exec();
         while (q1.next()){tot++;}
         while (q2.next()){c1++;}
         while (q3.next()){c2++;}
         while (q4.next()){c3++;}
         while (q5.next()){c4++;}

         QBarSet *set1 = new QBarSet("EM");
         QBarSet *set2 = new QBarSet("SM");
         QBarSet *set3 = new QBarSet("CM");
         QBarSet *set4 = new QBarSet("RH");
         *set1 << c1 ;
         *set2 << c2 ;
         *set3 << c3 ;
         *set4 << c4 ;
         QBarSeries *series = new QBarSeries();
         series->append(set1);
         series->append(set2);
         series->append(set3);
         series->append(set4);
         QChart *chart = new QChart();
         chart->addSeries(series);
         chart->setTitle("STATISTIQUE");
         chart->setAnimationOptions(QChart::AllAnimations);
         QStringList categories;
         categories << "STATISTIQUE";
         QBarCategoryAxis *axis = new QBarCategoryAxis();
         axis->append(categories);
         chart->createDefaultAxes();
         chart->setAxisX(axis, series);
         chart->legend()->setVisible(true);
         chart->legend()->setAlignment(Qt::AlignBottom);
         QChartView *chartView = new QChartView(chart);
         chartView->setRenderHint(QPainter::Antialiasing);
         chartView->setMinimumSize(281,311);
         chartView->setParent(ui->tableView2);
         QPalette pal = qApp->palette();
         qApp->setPalette(pal);


      QMessageBox::information(nullptr,QObject::tr("add completed"),
                               QObject::tr("add completed \n"
                                           "Click Cancel to exit."),QMessageBox::Cancel);
     }
     else
         QMessageBox::critical(nullptr,QObject::tr("add not completed"),
                               QObject::tr("add not completed \n"
                                           "Click Cancel to exit."),QMessageBox::Cancel);
   }
   else
       QMessageBox::critical(nullptr,QObject::tr("add not completed"),
                             QObject::tr("condition not respected  \n"
                                         "Click Cancel to exit."),QMessageBox::Cancel);
}
   else
       QMessageBox::critical(nullptr,QObject::tr("add not completed"),
                             QObject::tr("must fill all the informations \n"
                                         "Click Cancel to exit."),QMessageBox::Cancel);
}
void employee::on_pushButton_supprimer_clicked()
{
   QString ID_emp=ui->lineEdit_ID->text();

   bool test1=Etmp.supprimer(ID_emp);
     if(test1)
     {

         ui->tableView1->setModel(Etmp.afficher());
         //STATISTIQUES
         QSqlQuery q1,q2,q3,q4,q5;
         qreal tot=0,c1=0,c2=0,c3=0,c4=0;
         q1.prepare("SELECT * FROM employee");
         q1.exec();
         q2.prepare("SELECT * FROM employee WHERE departement='EM'");
         q2.exec();
         q3.prepare("SELECT * FROM employee WHERE departement='SM'");
         q3.exec();
         q4.prepare("SELECT * FROM employee WHERE departement='CM'");
         q4.exec();
         q5.prepare("SELECT * FROM employee WHERE departement='RH'");
         q5.exec();
         while (q1.next()){tot++;}
         while (q2.next()){c1++;}
         while (q3.next()){c2++;}
         while (q4.next()){c3++;}
         while (q5.next()){c4++;}

         QBarSet *set1 = new QBarSet("EM");
         QBarSet *set2 = new QBarSet("SM");
         QBarSet *set3 = new QBarSet("CM");
         QBarSet *set4 = new QBarSet("RH");
         *set1 << c1 ;
         *set2 << c2 ;
         *set3 << c3 ;
         *set4 << c4 ;
         QBarSeries *series = new QBarSeries();
         series->append(set1);
         series->append(set2);
         series->append(set3);
         series->append(set4);
         QChart *chart = new QChart();
         chart->addSeries(series);
         chart->setTitle("STATISTIQUE");
         chart->setAnimationOptions(QChart::AllAnimations);
         QStringList categories;
         categories << "STATISTIQUE";
         QBarCategoryAxis *axis = new QBarCategoryAxis();
         axis->append(categories);
         chart->createDefaultAxes();
         chart->setAxisX(axis, series);
         chart->legend()->setVisible(true);
         chart->legend()->setAlignment(Qt::AlignBottom);
         QChartView *chartView = new QChartView(chart);
         chartView->setRenderHint(QPainter::Antialiasing);
         chartView->setMinimumSize(281,311);
         chartView->setParent(ui->tableView2);
         QPalette pal = qApp->palette();
         qApp->setPalette(pal);



      QMessageBox::information(nullptr,QObject::tr("delete completed"),
                               QObject::tr("delete completed \n"
                                           "Click Cancel to exit."),QMessageBox::Cancel);
     }
     else
         QMessageBox::critical(nullptr,QObject::tr("delete not completed"),
                               QObject::tr("delete not completed \n"
                                           "Click Cancel to exit."),QMessageBox::Cancel);

}
void employee::on_tableView1_activated(const QModelIndex &index)
{
 QString val=ui->tableView1->model()->data(index).toString();
 QSqlQuery qry;
 qry.prepare("select * from employee where ID_emp='"+val+"'");
 if(qry.exec())
 {
  while(qry.next())
  {
   ui->lineEdit_ID->setText(qry.value(0).toString());
   ui->lineEdit_first->setText(qry.value(2).toString());
   ui->lineEdit_last->setText(qry.value(4).toString());
   ui->lineEdit_password->setText(qry.value(3).toString());
   ui->box->setCurrentText(qry.value(1).toString());
   ui->lineEdit_salary->setText(qry.value(5).toString());
   ui->lineEdit_chef->setText(qry.value(6).toString());
  }
 }
 else
 {
  QMessageBox::critical(this,tr("error::"),qry.lastError().text());
 }
}
void employee::on_pushButton_modifier_clicked()
{


    QString ID_emp=ui->lineEdit_ID->text();
    QString first_name=ui->lineEdit_first->text();
    QString last_name=ui->lineEdit_last->text();
    QString password=ui->lineEdit_password->text();
    QString departement=ui->box->currentText();
    QString ID_chef=ui->lineEdit_chef->text();
    int salary=ui->lineEdit_salary->text().toInt();
    QString res = QString::number(salary);
    if(!ID_emp.isEmpty()&&!first_name.isEmpty()&&!last_name.isEmpty()&&!password.isEmpty()&&!ID_chef.isEmpty())
    {
    if(ID_emp.length()<11&&ID_emp.length()>5&&first_name.length()<16&&last_name.length()<16&&password.length()<13&&ID_chef.length()<11&&ID_chef.length()>5)
     {
    employe e1(ID_emp, departement, first_name, password, last_name, ID_chef, salary);
    bool test2=e1.modifier(ID_emp);
      if(test2)
      {

          ui->tableView1->setModel(Etmp.afficher());
          //STATISTIQUES
          QSqlQuery q1,q2,q3,q4,q5;
          qreal tot=0,c1=0,c2=0,c3=0,c4=0;
          q1.prepare("SELECT * FROM employee");
          q1.exec();
          q2.prepare("SELECT * FROM employee WHERE departement='EM'");
          q2.exec();
          q3.prepare("SELECT * FROM employee WHERE departement='SM'");
          q3.exec();
          q4.prepare("SELECT * FROM employee WHERE departement='CM'");
          q4.exec();
          q5.prepare("SELECT * FROM employee WHERE departement='RH'");
          q5.exec();
          while (q1.next()){tot++;}
          while (q2.next()){c1++;}
          while (q3.next()){c2++;}
          while (q4.next()){c3++;}
          while (q5.next()){c4++;}

          QBarSet *set1 = new QBarSet("EM");
          QBarSet *set2 = new QBarSet("SM");
          QBarSet *set3 = new QBarSet("CM");
          QBarSet *set4 = new QBarSet("RH");
          *set1 << c1 ;
          *set2 << c2 ;
          *set3 << c3 ;
          *set4 << c4 ;
          QBarSeries *series = new QBarSeries();
          series->append(set1);
          series->append(set2);
          series->append(set3);
          series->append(set4);
          QChart *chart = new QChart();
          chart->addSeries(series);
          chart->setTitle("STATISTIQUE");
          chart->setAnimationOptions(QChart::AllAnimations);
          QStringList categories;
          categories << "STATISTIQUE";
          QBarCategoryAxis *axis = new QBarCategoryAxis();
          axis->append(categories);
          chart->createDefaultAxes();
          chart->setAxisX(axis, series);
          chart->legend()->setVisible(true);
          chart->legend()->setAlignment(Qt::AlignBottom);
          QChartView *chartView = new QChartView(chart);
          chartView->setRenderHint(QPainter::Antialiasing);
          chartView->setMinimumSize(281,311);
          chartView->setParent(ui->tableView2);
          QPalette pal = qApp->palette();
          qApp->setPalette(pal);



       QMessageBox::information(nullptr,QObject::tr("update completed"),
                                QObject::tr("update completed \n"
                                            "Click Cancel to exit."),QMessageBox::Cancel);
      }
      else
          QMessageBox::critical(nullptr,QObject::tr("update not completed"),
                                QObject::tr("update not completed \n"
                                            "Click Cancel to exit."),QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr,QObject::tr("update not completed"),
                              QObject::tr("condition not respected \n"
                                          "Click Cancel to exit."),QMessageBox::Cancel);
    }
        else
            QMessageBox::critical(nullptr,QObject::tr("update not completed"),
                                  QObject::tr("must fill all the informations \n"
                                              "Click Cancel to exit."),QMessageBox::Cancel);
}

void employee::on_pushButton_reset_clicked()
{
    ui->lineEdit_ID->setText("211JMT");
    ui->lineEdit_first->setText(nullptr);
    ui->lineEdit_last->setText(nullptr);
    ui->lineEdit_password->setText(nullptr);
    ui->box->setCurrentText("");
    ui->lineEdit_salary->setText(nullptr);
    ui->lineEdit_chef->setText("211JMT");
}

void employee::on_pushButton_search_clicked()
{

            if (ui->radioButton_first2->isChecked())
            {
                QString first_name = ui->lineEdit_search->text();
                        ui->tableView1->setModel(Etmp.searchF(first_name));
            }
            else if(ui->radioButton_last2->isChecked())
            {
                QString last_name = ui->lineEdit_search->text();
                        ui->tableView1->setModel(Etmp.searchL(last_name));
            }
            else if(ui->radioButton_ID->isChecked())
            {
                QString ID_emp = ui->lineEdit_search->text();

                        ui->tableView1->setModel(Etmp.searchID(ID_emp));
            }
}
void employee::on_pushButton_sort_clicked()
{
    if (ui->radioButton_first->isChecked())
    {
       ui->tableView1->setModel(Etmp.sort_firstn());
    }
    else if(ui->radioButton_last->isChecked())
    {
       ui->tableView1->setModel(Etmp.sort_Lastn());
    }
    else if(ui->radioButton_salary->isChecked())
    {
       ui->tableView1->setModel(Etmp.sort_salary());
    }
}
void employee::on_pushButton_export_clicked()
{
    QPdfWriter pdf("C:/Users/Rayen/Desktop/Esprit 2A21/projetQT/employee.pdf");

                         QPainter painter(&pdf);

                         int i = 4000;


                         painter.drawText(4000,1500,"LISTE DES EMPLOYES");
                         painter.setPen(Qt::red);
                         painter.setFont(QFont("Arial", 50));
                         painter.drawRect(3800,1200,1700,500);
                         painter.drawRect(0,3000,9600,500);
                         painter.setPen(Qt::black);
                         painter.setFont(QFont("Arial", 9));
                         painter.drawText(500,3300,"ID");
                         painter.drawText(1500,3300,"DEPARTEMENT");
                         painter.drawText(3500,3300,"FIRST NAME");
                         painter.drawText(5000,3300,"PASSWORD");
                         painter.drawText(6500,3300,"LAST NAME");
                         painter.drawText(8000,3300,"SALARY");


                         QSqlQuery query;
                         query.prepare("select * from employee");
                         query.exec();
                         while (query.next())
                         {
                             painter.drawText(500,i,query.value(0).toString());
                             painter.drawText(1800,i,query.value(1).toString());
                             painter.drawText(3500,i,query.value(2).toString());
                             painter.drawText(5000,i,query.value(3).toString());
                             painter.drawText(6500,i,query.value(4).toString());
                             painter.drawText(8000,i,query.value(5).toString());


                             i = i +500;
                         }

                         int reponse = QMessageBox::question(this, "PDF exported", "see the PDF now ?", QMessageBox::Yes |  QMessageBox::No);
                         if (reponse == QMessageBox::Yes)
                         {
                             QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/Rayen/Desktop/Esprit 2A21/projetQT/employee.pdf"));

                             painter.end();
                         }
                         if (reponse == QMessageBox::No)
                         {
                             painter.end();
                         }
}


//messagerie (chat Box)
/*void employee::on_pushButton_send_clicked()
{
    QString MSG=ui->lineEdit_send->text();
   // message m(MSG);
    bool test5=m.sendmsg();
      if(test5)
      {
      ui->chatbox->setModel(m.affichermsg());
      ui->lineEdit_send->clear();
      ui->lineEdit_send->setText("from 211JMT:");
      }
}*/
