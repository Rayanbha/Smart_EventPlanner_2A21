#include "dialog_stat.h"
#include "ui_dialog_stat.h"
#include "client.h"
#include "qcustomplot.h"
#include "mainwindow.h"

Dialog_stat::Dialog_stat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_stat)
{
    ui->setupUi(this);
    Dialog_stat::MakeStat();
}

Dialog_stat::~Dialog_stat()
{
    delete ui;
}


void Dialog_stat::statistiques(QVector<double>* ticks,QVector<QString> *labels)
{
    QSqlQuery qry;
    int i=0;
    qry.exec("SELECT event FROM client");
    while (qry.next())
    {
        QString event = qry.value(7).toString();
        i++;
        *ticks<<i;
        *labels <<event;
    }
}
void Dialog_stat::MakeStat()
{
    // Background
    QLinearGradient gradient(0, 0, 0, 400);
    gradient.setColorAt(0, QColor(100, 149, 237));
    ui->plot->setBackground(QBrush(gradient));
    QCPBars *A = new QCPBars(ui->plot->xAxis, ui->plot->yAxis);
    A->setAntialiased(false);
    A->setStackingGap(1);

    // Couleurs
    A->setName("Repartition des evenements selon event");
    A->setPen(QPen(QColor(0, 255, 255).lighter(120)));
    A->setBrush(QColor(0, 0, 255));

    // Axe des abscisses
    QVector<double> ticks;
    QVector<QString> labels;
    statistiques(&ticks,&labels);
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(ticks, labels);
    ui->plot->xAxis->setTicker(textTicker);
    ui->plot->xAxis->setTickLabelRotation(60);
    ui->plot->xAxis->setSubTicks(false);
    ui->plot->xAxis->setLabel("Event");
    ui->plot->xAxis->setTickLength(0, 4);
    ui->plot->xAxis->setRange(0, 8);
    ui->plot->xAxis->setBasePen(QPen(Qt::black));
    ui->plot->xAxis->setTickPen(QPen(Qt::black));
    ui->plot->xAxis->grid()->setVisible(true);
    ui->plot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
    ui->plot->xAxis->setTickLabelColor(Qt::black);
    ui->plot->xAxis->setLabelColor(Qt::black);

    // Axe des ordonnées
    ui->plot->yAxis->setRange(1990,2022);
    ui->plot->yAxis->setPadding(5);
    ui->plot->yAxis->setLabel("Year");
    ui->plot->yAxis->setBasePen(QPen(Qt::black));
    ui->plot->yAxis->setTickPen(QPen(Qt::black));
    ui->plot->yAxis->setSubTickPen(QPen(Qt::black));
    ui->plot->yAxis->grid()->setSubGridVisible(true);
    ui->plot->yAxis->setTickLabelColor(Qt::black);
    ui->plot->yAxis->setLabelColor(Qt::black);
    ui->plot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
    ui->plot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
    QVector<double> PlaceData;
    QSqlQuery q1("SELECT YEAR FROM client");
    while (q1.next())
    {
        int  nbr_fautee = q1.value(0).toInt();
        PlaceData<< nbr_fautee;
    }
    A->setData(ticks, PlaceData);
    ui->plot->legend->setVisible(true);
    ui->plot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
    ui->plot->legend->setBrush(QColor(255, 255, 255, 100));
    ui->plot->legend->setBorderPen(Qt::NoPen);
    QFont legendFont = font();
    legendFont.setPointSize(5);
    ui->plot->legend->setFont(legendFont);
    ui->plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
}

void Dialog_stat::on_pushButton_clicked()
{
    close();
}
