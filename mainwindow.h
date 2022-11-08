#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QMessageBox>
#include <events.h>

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


     void on_bt_search_clicked();

     void on_TRI_NAME_clicked();

     void on_TRI_DATE_clicked();

     void on_TRI_TYPE_clicked();

private:
    Ui::MainWindow *ui;
    Events etmp ;

};
#endif // MAINWINDOW_H
