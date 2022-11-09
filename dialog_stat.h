#ifndef DIALOG_STAT_H
#define DIALOG_STAT_H

#include <QDialog>
#include "QtPrintSupport"

namespace Ui {
class Dialog_stat;
}

class Dialog_stat : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_stat(QWidget *parent = nullptr);
    ~Dialog_stat();

private slots:

void on_pushButton_clicked();

private:
    Ui::Dialog_stat *ui;
    void MakeStat();
    void statistiques(QVector<double>* ticks,QVector<QString> *labels);
};

#endif // DIALOG_STAT_H
