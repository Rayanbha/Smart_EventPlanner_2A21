#ifndef SUPPLIER_H
#define SUPPLIER_H

#include <QDialog>
#include <QMainWindow>
#include "provider.h"
#include <QMessageBox>
//#include"map.h"
#include "ui_mainwindow.h"
//#include "statistique.h"
#include <QCompleter>
#include <QSqlQuery>
//#include "ui_map.h"

namespace Ui {
class supplier;
}

class supplier : public QDialog
{
    Q_OBJECT

public:
    explicit supplier(QWidget *parent = nullptr);
    ~supplier();

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
    Ui::supplier *ui;
    QCompleter * Model_Completer;
    QList<qreal> stat_budget();
    QList <QString> stat_bud();
    QSqlQuery qry;
    Provider ptmp ;
};

#endif // SUPPLIER_H
