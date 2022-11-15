#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QMessageBox>
#include <events.h>
#include <QFileDialog>
#include <QTextDocument>
#include <QPdfWriter>
#include <QPainter>
#include <QDesktopServices>
#include <QPrinter>
#include <QFileDialog>
#include <QTextDocument>
#include <QVector>
#include <QMessageBox>
#include <QLCDNumber>
#include <QFile>
#include <cstdlib>
#include <QDebug>
QT_BEGIN_NAMESPACE

namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_pushButton_add_event_clicked();
    void on_pushButton_delete_event_clicked();
     void on_pushButton_modify_event_clicked();

     void on_tableView_event_activated(const QModelIndex &index);

     void on_TRI_NAME_clicked();

     void on_TRI_DATE_clicked();

     void on_TRI_TYPE_clicked();

     void on_pushButton_pdf_event_clicked();
     ////stat
     QVector<double> statistiques();
     void makePlot();

     void on_pushButton_statistic_event_clicked();
    void on_tableView_event_doubleClicked(const QModelIndex &index);
       //  void on_tableView_event_clicked(const QModelIndex &index);
    void on_pushButtontop_event_2_clicked();

    void on_pushButton_reduction_event_clicked();
    void on_search_event_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    Events etmp ;

};
#endif // MAINWINDOW_H
