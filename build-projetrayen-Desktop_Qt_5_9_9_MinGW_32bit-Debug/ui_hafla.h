/********************************************************************************
** Form generated from reading UI file 'hafla.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HAFLA_H
#define UI_HAFLA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_hafla
{
public:
    QTabWidget *tabWidget;
    QWidget *mainwindow;
    QPushButton *TRI_TYPE;
    QLabel *label_10;
    QPushButton *TRI_DATE;
    QLabel *label_7;
    QPushButton *pushButtontop_event_2;
    QPushButton *pushButton_pdf_event;
    QPushButton *pushButton_add_event;
    QTableView *tableView_event;
    QPushButton *TRI_NAME;
    QPushButton *pushButton_delete_event;
    QLineEdit *search_event;
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *lineEdit_name_event;
    QLineEdit *lineEdit_type_event;
    QLineEdit *lineEdit_clientevent;
    QLineEdit *lineEdit_cost_event;
    QLineEdit *lineEdit_number_event;
    QLabel *label_6;
    QDateEdit *dateEdit_event;
    QLabel *label_8;
    QLineEdit *lineEdit_idemp_event;
    QLineEdit *lineEdit_id_event;
    QLabel *label_9;
    QPushButton *pushButton_modify_event;
    QLabel *label_bg;
    QWidget *Statistics;
    QCustomPlot *customplot;
    QPushButton *pushButton_statistic_event;
    QWidget *tab;
    QPushButton *pushButton_reduction_event;
    QLineEdit *lineEdit_reduction;
    QComboBox *comboBox;
    QLabel *label_11;

    void setupUi(QDialog *hafla)
    {
        if (hafla->objectName().isEmpty())
            hafla->setObjectName(QStringLiteral("hafla"));
        hafla->resize(1385, 775);
        tabWidget = new QTabWidget(hafla);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 30, 1221, 771));
        tabWidget->setStyleSheet(QStringLiteral("background-image: url(:/img/310794473_421202606625675_5261566836712753251_n.png);"));
        mainwindow = new QWidget();
        mainwindow->setObjectName(QStringLiteral("mainwindow"));
        TRI_TYPE = new QPushButton(mainwindow);
        TRI_TYPE->setObjectName(QStringLiteral("TRI_TYPE"));
        TRI_TYPE->setGeometry(QRect(850, 110, 75, 23));
        label_10 = new QLabel(mainwindow);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(760, 110, 71, 21));
        label_10->setStyleSheet(QStringLiteral("background-color: rgb(0, 255, 255);"));
        TRI_DATE = new QPushButton(mainwindow);
        TRI_DATE->setObjectName(QStringLiteral("TRI_DATE"));
        TRI_DATE->setGeometry(QRect(850, 140, 75, 23));
        label_7 = new QLabel(mainwindow);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(450, 110, 101, 20));
        label_7->setStyleSheet(QLatin1String("font: 8pt \"Cascadia Code\";\n"
"font: 10pt \"Cascadia Code\";"));
        pushButtontop_event_2 = new QPushButton(mainwindow);
        pushButtontop_event_2->setObjectName(QStringLiteral("pushButtontop_event_2"));
        pushButtontop_event_2->setGeometry(QRect(610, 540, 241, 23));
        pushButtontop_event_2->setStyleSheet(QLatin1String("font: 8pt \"Cascadia Code\";\n"
"font: 10pt \"Cascadia Code\";"));
        pushButton_pdf_event = new QPushButton(mainwindow);
        pushButton_pdf_event->setObjectName(QStringLiteral("pushButton_pdf_event"));
        pushButton_pdf_event->setGeometry(QRect(890, 540, 151, 23));
        pushButton_pdf_event->setStyleSheet(QLatin1String("font: 8pt \"Cascadia Code\";\n"
"font: 10pt \"Cascadia Code\";"));
        pushButton_add_event = new QPushButton(mainwindow);
        pushButton_add_event->setObjectName(QStringLiteral("pushButton_add_event"));
        pushButton_add_event->setGeometry(QRect(30, 540, 91, 23));
        pushButton_add_event->setStyleSheet(QLatin1String("font: 8pt \"Cascadia Code\";\n"
"font: 10pt \"Cascadia Code\";"));
        tableView_event = new QTableView(mainwindow);
        tableView_event->setObjectName(QStringLiteral("tableView_event"));
        tableView_event->setGeometry(QRect(410, 170, 771, 361));
        tableView_event->setStyleSheet(QLatin1String("background-color: rgb(211, 253, 255);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(85, 255, 255, 0), stop:1 rgba(255, 255, 255, 255));"));
        TRI_NAME = new QPushButton(mainwindow);
        TRI_NAME->setObjectName(QStringLiteral("TRI_NAME"));
        TRI_NAME->setGeometry(QRect(850, 80, 75, 23));
        pushButton_delete_event = new QPushButton(mainwindow);
        pushButton_delete_event->setObjectName(QStringLiteral("pushButton_delete_event"));
        pushButton_delete_event->setGeometry(QRect(410, 540, 121, 23));
        pushButton_delete_event->setStyleSheet(QLatin1String("font: 8pt \"Cascadia Code\";\n"
"font: 10pt \"Cascadia Code\";"));
        search_event = new QLineEdit(mainwindow);
        search_event->setObjectName(QStringLiteral("search_event"));
        search_event->setGeometry(QRect(580, 110, 113, 20));
        search_event->setStyleSheet(QLatin1String("selection-color: rgb(255, 255, 255);\n"
"background-color: rgb(255, 255, 255);"));
        groupBox = new QGroupBox(mainwindow);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(30, 160, 361, 371));
        groupBox->setStyleSheet(QLatin1String("font: 8pt \"Cascadia Code\";\n"
"background-color: rgb(211, 253, 255);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(85, 255, 255, 0), stop:1 rgba(255, 255, 255, 255));\n"
"font: 10pt \"Cascadia Code\";"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 110, 101, 16));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(50, 160, 101, 16));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(50, 210, 101, 16));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(50, 260, 101, 16));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(50, 300, 101, 16));
        lineEdit_name_event = new QLineEdit(groupBox);
        lineEdit_name_event->setObjectName(QStringLiteral("lineEdit_name_event"));
        lineEdit_name_event->setGeometry(QRect(180, 110, 113, 20));
        lineEdit_name_event->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        lineEdit_type_event = new QLineEdit(groupBox);
        lineEdit_type_event->setObjectName(QStringLiteral("lineEdit_type_event"));
        lineEdit_type_event->setGeometry(QRect(180, 160, 113, 20));
        lineEdit_type_event->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        lineEdit_clientevent = new QLineEdit(groupBox);
        lineEdit_clientevent->setObjectName(QStringLiteral("lineEdit_clientevent"));
        lineEdit_clientevent->setGeometry(QRect(180, 210, 113, 16));
        lineEdit_clientevent->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        lineEdit_cost_event = new QLineEdit(groupBox);
        lineEdit_cost_event->setObjectName(QStringLiteral("lineEdit_cost_event"));
        lineEdit_cost_event->setGeometry(QRect(180, 300, 113, 20));
        lineEdit_cost_event->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"background-color: rgb(255, 255, 255);"));
        lineEdit_number_event = new QLineEdit(groupBox);
        lineEdit_number_event->setObjectName(QStringLiteral("lineEdit_number_event"));
        lineEdit_number_event->setGeometry(QRect(180, 340, 113, 20));
        lineEdit_number_event->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"selection-background-color: rgb(255, 255, 127);"));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(50, 340, 111, 20));
        dateEdit_event = new QDateEdit(groupBox);
        dateEdit_event->setObjectName(QStringLiteral("dateEdit_event"));
        dateEdit_event->setGeometry(QRect(180, 260, 110, 22));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(50, 60, 91, 16));
        lineEdit_idemp_event = new QLineEdit(groupBox);
        lineEdit_idemp_event->setObjectName(QStringLiteral("lineEdit_idemp_event"));
        lineEdit_idemp_event->setGeometry(QRect(180, 60, 113, 20));
        lineEdit_idemp_event->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        lineEdit_id_event = new QLineEdit(groupBox);
        lineEdit_id_event->setObjectName(QStringLiteral("lineEdit_id_event"));
        lineEdit_id_event->setGeometry(QRect(180, 20, 113, 20));
        lineEdit_id_event->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(50, 20, 91, 16));
        pushButton_modify_event = new QPushButton(mainwindow);
        pushButton_modify_event->setObjectName(QStringLiteral("pushButton_modify_event"));
        pushButton_modify_event->setGeometry(QRect(310, 540, 75, 23));
        label_bg = new QLabel(mainwindow);
        label_bg->setObjectName(QStringLiteral("label_bg"));
        label_bg->setGeometry(QRect(0, 0, 1211, 611));
        tabWidget->addTab(mainwindow, QString());
        label_bg->raise();
        TRI_TYPE->raise();
        label_10->raise();
        TRI_DATE->raise();
        label_7->raise();
        pushButtontop_event_2->raise();
        pushButton_pdf_event->raise();
        pushButton_add_event->raise();
        tableView_event->raise();
        TRI_NAME->raise();
        pushButton_delete_event->raise();
        search_event->raise();
        groupBox->raise();
        pushButton_modify_event->raise();
        Statistics = new QWidget();
        Statistics->setObjectName(QStringLiteral("Statistics"));
        customplot = new QCustomPlot(Statistics);
        customplot->setObjectName(QStringLiteral("customplot"));
        customplot->setGeometry(QRect(110, 90, 981, 421));
        pushButton_statistic_event = new QPushButton(Statistics);
        pushButton_statistic_event->setObjectName(QStringLiteral("pushButton_statistic_event"));
        pushButton_statistic_event->setGeometry(QRect(110, 50, 101, 23));
        pushButton_statistic_event->setStyleSheet(QLatin1String("font: 8pt \"Cascadia Code\";\n"
"font: 10pt \"Cascadia Code\";"));
        tabWidget->addTab(Statistics, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        pushButton_reduction_event = new QPushButton(tab);
        pushButton_reduction_event->setObjectName(QStringLiteral("pushButton_reduction_event"));
        pushButton_reduction_event->setGeometry(QRect(510, 120, 121, 23));
        pushButton_reduction_event->setStyleSheet(QLatin1String("font: 8pt \"Cascadia Code\";\n"
"font: 10pt \"Cascadia Code\";"));
        lineEdit_reduction = new QLineEdit(tab);
        lineEdit_reduction->setObjectName(QStringLiteral("lineEdit_reduction"));
        lineEdit_reduction->setGeometry(QRect(470, 190, 211, 221));
        comboBox = new QComboBox(tab);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(170, 120, 62, 22));
        label_11 = new QLabel(tab);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(180, 80, 91, 16));
        tabWidget->addTab(tab, QString());

        retranslateUi(hafla);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(hafla);
    } // setupUi

    void retranslateUi(QDialog *hafla)
    {
        hafla->setWindowTitle(QApplication::translate("hafla", "Dialog", Q_NULLPTR));
        TRI_TYPE->setText(QApplication::translate("hafla", "TYPE", Q_NULLPTR));
        label_10->setText(QApplication::translate("hafla", "      Sort", Q_NULLPTR));
        TRI_DATE->setText(QApplication::translate("hafla", "DATE", Q_NULLPTR));
        label_7->setText(QApplication::translate("hafla", "Search event", Q_NULLPTR));
        pushButtontop_event_2->setText(QApplication::translate("hafla", "low priority events alert", Q_NULLPTR));
        pushButton_pdf_event->setText(QApplication::translate("hafla", "Export PDF", Q_NULLPTR));
        pushButton_add_event->setText(QApplication::translate("hafla", "Add event", Q_NULLPTR));
        TRI_NAME->setText(QApplication::translate("hafla", "ID", Q_NULLPTR));
        pushButton_delete_event->setText(QApplication::translate("hafla", "Delete event", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("hafla", "Event Manager", Q_NULLPTR));
        label->setStyleSheet(QApplication::translate("hafla", "font: 8pt \"Cascadia Code\";\n"
"font: 10pt \"Cascadia Code\";", Q_NULLPTR));
        label->setText(QApplication::translate("hafla", "Event name", Q_NULLPTR));
        label_2->setStyleSheet(QApplication::translate("hafla", "font: 8pt \"Cascadia Code\";\n"
"font: 10pt \"Cascadia Code\";", Q_NULLPTR));
        label_2->setText(QApplication::translate("hafla", "Event type", Q_NULLPTR));
        label_3->setStyleSheet(QApplication::translate("hafla", "font: 8pt \"Cascadia Code\";\n"
"font: 10pt \"Cascadia Code\";", Q_NULLPTR));
        label_3->setText(QApplication::translate("hafla", "Client", Q_NULLPTR));
        label_4->setStyleSheet(QApplication::translate("hafla", "font: 8pt \"Cascadia Code\";\n"
"font: 10pt \"Cascadia Code\";", Q_NULLPTR));
        label_4->setText(QApplication::translate("hafla", "Date", Q_NULLPTR));
        label_5->setStyleSheet(QApplication::translate("hafla", "font: 8pt \"Cascadia Code\";\n"
"font: 10pt \"Cascadia Code\";", Q_NULLPTR));
        label_5->setText(QApplication::translate("hafla", "Cost", Q_NULLPTR));
        label_6->setStyleSheet(QApplication::translate("hafla", "font: 8pt \"Cascadia Code\";\n"
"font: 10pt \"Cascadia Code\";", Q_NULLPTR));
        label_6->setText(QApplication::translate("hafla", "Guests number", Q_NULLPTR));
        label_8->setText(QApplication::translate("hafla", "ID Employe", Q_NULLPTR));
        label_9->setText(QApplication::translate("hafla", "ID event", Q_NULLPTR));
        pushButton_modify_event->setText(QApplication::translate("hafla", "modify event", Q_NULLPTR));
        label_bg->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(mainwindow), QApplication::translate("hafla", "MainWindow", Q_NULLPTR));
        pushButton_statistic_event->setText(QApplication::translate("hafla", "Statistics", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(Statistics), QApplication::translate("hafla", "Statistics", Q_NULLPTR));
        pushButton_reduction_event->setText(QApplication::translate("hafla", "Reduction", Q_NULLPTR));
        label_11->setText(QApplication::translate("hafla", "choose event id", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("hafla", "LUCKY REDUCTION", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class hafla: public Ui_hafla {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HAFLA_H
