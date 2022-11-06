#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"client.h"


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
    void on_add_clicked();
    void on_delete_2_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_update_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_Search_clicked();

    void on_search_clicked();

    void on_Sort_clicked();

    void on_sort_clicked();

private:
    Ui::MainWindow *ui;
    client Etmp;
};
#endif // MAINWINDOW_H
