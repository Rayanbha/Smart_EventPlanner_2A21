#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include<QtCharts/QPieSeries>
#include<QtCharts/QPieSlice>
#include<QtCharts/QChartView>


QT_CHARTS_USE_NAMESPACE

int main(int argc, char *argv[])
{
  //  QPieSeries *series= new QPieSeries();
    //series->append("")

    QApplication a(argc, argv);

    Connection c;
    bool test=c.createconnect();
   MainWindow w;
    if(test)
    {w.show();
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);



    return a.exec();
}
