#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "employee.h"
#include <QModelIndex>


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


private:
    Ui::MainWindow *ui;
    employee Etmp;
};
#endif // MAINWINDOW_H
