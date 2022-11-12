#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "employee.h"
#include <QModelIndex>
#include <QPainter>
#include <QDesktopServices>
#include <QPdfWriter>
#include <QUrl>
#include <QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts>
#include <QChartView>
#include <QLineSeries>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QTabWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_pushButton_ajouter_clicked();
    void on_pushButton_supprimer_clicked();
    void on_pushButton_modifier_clicked();
    void on_tableView1_activated(const QModelIndex &index);
    void on_pushButton_reset_clicked();
    void on_pushButton_search_clicked();
    void on_pushButton_sort_clicked();
    void on_pushButton_export_clicked();
  //  void on_pushButton_stat_clicked();


private:
    Ui::MainWindow *ui;
    employee Etmp;
};
#endif // MAINWINDOW_H
