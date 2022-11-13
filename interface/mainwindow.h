#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlQuery>
#include <QMessageBox>
#include "employee.h"
#include "client.h"
#include "supplier.h"
#include "hafla.h"
#include <QDialog>
#include <QSqlRecord>
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
    void on_pushButton_login_clicked();
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
