#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"arduino.h"
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
#include <QPixmap>
#include<QMessageBox>
#include<string>
#include<iostream>
#include<QComboBox>
#include<QRadioButton>
#include<QPdfWriter>
#include<QDesktopServices>
#include<QFileDialog>


#include<QDialog>
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
    void update_label();   // slot permettant la mise à jour du label état de la lampe 1,
    // ce slot est lancé à chaque réception d'un message de Arduino

    void on_pushButton_login_clicked();
private:
    Ui::MainWindow *ui;
    QByteArray data; // variable contenant les données reçues

    Arduino A; // objet temporaire
};
#endif // MAINWINDOW_H
