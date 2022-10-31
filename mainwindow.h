#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "provider.h"
#include <QMessageBox>

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

    void on_tableView_provider_activated(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    Provider ptmp ;
};
#endif // MAINWINDOW_H
