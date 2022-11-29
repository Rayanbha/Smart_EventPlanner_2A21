#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "provider.h"
#include <QMessageBox>
//#include"map.h"
#include "ui_mainwindow.h"
//#include "statistique.h"
#include <QCompleter>
#include <QSqlQuery>
//#include "ui_map.h"



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
    void on_pushButton_add_provider_clicked();

    void on_pushButton_modify_provider_clicked();

    void on_pushButton_delete_providert_clicked();


        void on_pushButton_sort_providers_clicked();

        void on_recherche_clicked();

        void on_pushButton_Stat_clicked();

        void on_pushButton_add_provider_5_clicked();

        void on_pushButton_location_clicked();

private:
    Ui::MainWindow *ui;
    QCompleter * Model_Completer;
    QList<qreal> stat_budget();
    QList <QString> stat_bud();
    QSqlQuery qry;


    Provider ptmp ;
   // map *m;
};
#endif // MAINWINDOW_H
