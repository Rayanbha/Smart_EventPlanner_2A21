/********************************************************************************
** Form generated from reading UI file 'employee.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMPLOYEE_H
#define UI_EMPLOYEE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_employee
{
public:
    QTabWidget *Tabwidget;
    QWidget *RH_manager;
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *lineEdit_first;
    QLineEdit *lineEdit_last;
    QLineEdit *lineEdit_ID;
    QLineEdit *lineEdit_password;
    QLineEdit *lineEdit_salary;
    QPushButton *pushButton_ajouter;
    QPushButton *pushButton_reset;
    QLabel *label_7;
    QPushButton *pushButton_modifier;
    QPushButton *pushButton_supprimer;
    QLabel *label_8;
    QLineEdit *lineEdit_chef;
    QComboBox *box;
    QTableView *tableView1;
    QLabel *label_pic;
    QGroupBox *groupBox_3;
    QLineEdit *lineEdit_search;
    QPushButton *pushButton_search;
    QPushButton *pushButton_sort;
    QRadioButton *radioButton_first;
    QRadioButton *radioButton_last;
    QRadioButton *radioButton_salary;
    QRadioButton *radioButton_ID;
    QRadioButton *radioButton_first2;
    QRadioButton *radioButton_last2;
    QPushButton *pushButton_export;
    QWidget *RH_employees;
    QLabel *label_pic2;
    QTableView *tableView2;
    QGroupBox *groupBox_2;
    QPushButton *pushButton_send;
    QLineEdit *lineEdit_send;
    QListView *chatbox;

    void setupUi(QDialog *employee)
    {
        if (employee->objectName().isEmpty())
            employee->setObjectName(QStringLiteral("employee"));
        employee->resize(928, 576);
        Tabwidget = new QTabWidget(employee);
        Tabwidget->setObjectName(QStringLiteral("Tabwidget"));
        Tabwidget->setGeometry(QRect(0, 0, 931, 581));
        RH_manager = new QWidget();
        RH_manager->setObjectName(QStringLiteral("RH_manager"));
        groupBox = new QGroupBox(RH_manager);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 50, 391, 441));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 50, 71, 21));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 90, 71, 21));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 130, 61, 21));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(30, 170, 56, 21));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(30, 210, 81, 21));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(30, 250, 56, 21));
        lineEdit_first = new QLineEdit(groupBox);
        lineEdit_first->setObjectName(QStringLiteral("lineEdit_first"));
        lineEdit_first->setGeometry(QRect(160, 50, 171, 22));
        lineEdit_first->setMaxLength(15);
        lineEdit_last = new QLineEdit(groupBox);
        lineEdit_last->setObjectName(QStringLiteral("lineEdit_last"));
        lineEdit_last->setGeometry(QRect(160, 90, 171, 22));
        lineEdit_last->setMaxLength(15);
        lineEdit_ID = new QLineEdit(groupBox);
        lineEdit_ID->setObjectName(QStringLiteral("lineEdit_ID"));
        lineEdit_ID->setGeometry(QRect(160, 130, 171, 22));
        lineEdit_ID->setMaxLength(10);
        lineEdit_password = new QLineEdit(groupBox);
        lineEdit_password->setObjectName(QStringLiteral("lineEdit_password"));
        lineEdit_password->setGeometry(QRect(160, 170, 171, 22));
        lineEdit_salary = new QLineEdit(groupBox);
        lineEdit_salary->setObjectName(QStringLiteral("lineEdit_salary"));
        lineEdit_salary->setGeometry(QRect(160, 250, 171, 22));
        pushButton_ajouter = new QPushButton(groupBox);
        pushButton_ajouter->setObjectName(QStringLiteral("pushButton_ajouter"));
        pushButton_ajouter->setGeometry(QRect(200, 360, 171, 28));
        pushButton_reset = new QPushButton(groupBox);
        pushButton_reset->setObjectName(QStringLiteral("pushButton_reset"));
        pushButton_reset->setGeometry(QRect(10, 360, 161, 28));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(340, 250, 31, 21));
        pushButton_modifier = new QPushButton(groupBox);
        pushButton_modifier->setObjectName(QStringLiteral("pushButton_modifier"));
        pushButton_modifier->setGeometry(QRect(10, 400, 161, 28));
        pushButton_supprimer = new QPushButton(groupBox);
        pushButton_supprimer->setObjectName(QStringLiteral("pushButton_supprimer"));
        pushButton_supprimer->setGeometry(QRect(200, 400, 171, 28));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(30, 290, 56, 16));
        lineEdit_chef = new QLineEdit(groupBox);
        lineEdit_chef->setObjectName(QStringLiteral("lineEdit_chef"));
        lineEdit_chef->setGeometry(QRect(160, 290, 171, 22));
        lineEdit_chef->setMaxLength(10);
        box = new QComboBox(groupBox);
        box->setObjectName(QStringLiteral("box"));
        box->setGeometry(QRect(160, 210, 171, 22));
        box->setEditable(true);
        label->raise();
        label_2->raise();
        label_3->raise();
        label_4->raise();
        label_5->raise();
        label_6->raise();
        lineEdit_first->raise();
        lineEdit_last->raise();
        lineEdit_ID->raise();
        lineEdit_password->raise();
        lineEdit_salary->raise();
        pushButton_ajouter->raise();
        pushButton_reset->raise();
        label_7->raise();
        label_8->raise();
        lineEdit_chef->raise();
        pushButton_supprimer->raise();
        pushButton_modifier->raise();
        box->raise();
        tableView1 = new QTableView(RH_manager);
        tableView1->setObjectName(QStringLiteral("tableView1"));
        tableView1->setGeometry(QRect(430, 50, 451, 221));
        label_pic = new QLabel(RH_manager);
        label_pic->setObjectName(QStringLiteral("label_pic"));
        label_pic->setGeometry(QRect(0, 0, 931, 551));
        groupBox_3 = new QGroupBox(RH_manager);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(430, 290, 451, 201));
        lineEdit_search = new QLineEdit(groupBox_3);
        lineEdit_search->setObjectName(QStringLiteral("lineEdit_search"));
        lineEdit_search->setGeometry(QRect(20, 40, 241, 31));
        pushButton_search = new QPushButton(groupBox_3);
        pushButton_search->setObjectName(QStringLiteral("pushButton_search"));
        pushButton_search->setGeometry(QRect(300, 40, 121, 28));
        pushButton_sort = new QPushButton(groupBox_3);
        pushButton_sort->setObjectName(QStringLiteral("pushButton_sort"));
        pushButton_sort->setGeometry(QRect(30, 130, 131, 28));
        radioButton_first = new QRadioButton(groupBox_3);
        radioButton_first->setObjectName(QStringLiteral("radioButton_first"));
        radioButton_first->setGeometry(QRect(170, 100, 97, 20));
        radioButton_last = new QRadioButton(groupBox_3);
        radioButton_last->setObjectName(QStringLiteral("radioButton_last"));
        radioButton_last->setGeometry(QRect(170, 130, 97, 20));
        radioButton_salary = new QRadioButton(groupBox_3);
        radioButton_salary->setObjectName(QStringLiteral("radioButton_salary"));
        radioButton_salary->setGeometry(QRect(170, 160, 97, 20));
        radioButton_ID = new QRadioButton(groupBox_3);
        radioButton_ID->setObjectName(QStringLiteral("radioButton_ID"));
        radioButton_ID->setGeometry(QRect(310, 100, 97, 20));
        radioButton_first2 = new QRadioButton(groupBox_3);
        radioButton_first2->setObjectName(QStringLiteral("radioButton_first2"));
        radioButton_first2->setGeometry(QRect(310, 130, 97, 20));
        radioButton_last2 = new QRadioButton(groupBox_3);
        radioButton_last2->setObjectName(QStringLiteral("radioButton_last2"));
        radioButton_last2->setGeometry(QRect(310, 160, 97, 20));
        pushButton_export = new QPushButton(RH_manager);
        pushButton_export->setObjectName(QStringLiteral("pushButton_export"));
        pushButton_export->setGeometry(QRect(780, 10, 93, 28));
        Tabwidget->addTab(RH_manager, QString());
        label_pic->raise();
        groupBox->raise();
        tableView1->raise();
        groupBox_3->raise();
        pushButton_export->raise();
        RH_employees = new QWidget();
        RH_employees->setObjectName(QStringLiteral("RH_employees"));
        label_pic2 = new QLabel(RH_employees);
        label_pic2->setObjectName(QStringLiteral("label_pic2"));
        label_pic2->setGeometry(QRect(0, 0, 921, 551));
        tableView2 = new QTableView(RH_employees);
        tableView2->setObjectName(QStringLiteral("tableView2"));
        tableView2->setGeometry(QRect(20, 20, 281, 311));
        groupBox_2 = new QGroupBox(RH_employees);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(310, 410, 601, 111));
        pushButton_send = new QPushButton(groupBox_2);
        pushButton_send->setObjectName(QStringLiteral("pushButton_send"));
        pushButton_send->setGeometry(QRect(240, 70, 121, 28));
        lineEdit_send = new QLineEdit(groupBox_2);
        lineEdit_send->setObjectName(QStringLiteral("lineEdit_send"));
        lineEdit_send->setGeometry(QRect(10, 20, 571, 31));
        chatbox = new QListView(RH_employees);
        chatbox->setObjectName(QStringLiteral("chatbox"));
        chatbox->setGeometry(QRect(310, 20, 591, 381));
        Tabwidget->addTab(RH_employees, QString());

        retranslateUi(employee);

        Tabwidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(employee);
    } // setupUi

    void retranslateUi(QDialog *employee)
    {
        employee->setWindowTitle(QApplication::translate("employee", "Dialog", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("employee", "employee's information", Q_NULLPTR));
        label->setText(QApplication::translate("employee", "first name", Q_NULLPTR));
        label_2->setText(QApplication::translate("employee", "last name", Q_NULLPTR));
        label_3->setText(QApplication::translate("employee", "secret ID", Q_NULLPTR));
        label_4->setText(QApplication::translate("employee", "password", Q_NULLPTR));
        label_5->setText(QApplication::translate("employee", "departement", Q_NULLPTR));
        label_6->setText(QApplication::translate("employee", "salary", Q_NULLPTR));
        lineEdit_first->setInputMask(QString());
        lineEdit_first->setText(QString());
        lineEdit_first->setPlaceholderText(QApplication::translate("employee", "entre 1 et 15 lettres", Q_NULLPTR));
        lineEdit_last->setPlaceholderText(QApplication::translate("employee", "entre 1 et 15 lettres", Q_NULLPTR));
        lineEdit_ID->setText(QApplication::translate("employee", "211JMT", Q_NULLPTR));
        lineEdit_ID->setPlaceholderText(QApplication::translate("employee", "211JMT....", Q_NULLPTR));
        lineEdit_password->setPlaceholderText(QApplication::translate("employee", "entre 5 et 12 ", Q_NULLPTR));
        lineEdit_salary->setPlaceholderText(QApplication::translate("employee", "salaire en chiffre ", Q_NULLPTR));
        pushButton_ajouter->setText(QApplication::translate("employee", "Add", Q_NULLPTR));
        pushButton_reset->setText(QApplication::translate("employee", "reset", Q_NULLPTR));
        label_7->setText(QApplication::translate("employee", "dt", Q_NULLPTR));
        pushButton_modifier->setText(QApplication::translate("employee", "update", Q_NULLPTR));
        pushButton_supprimer->setText(QApplication::translate("employee", "delete", Q_NULLPTR));
        label_8->setText(QApplication::translate("employee", "ID chef", Q_NULLPTR));
        lineEdit_chef->setText(QApplication::translate("employee", "211JMT", Q_NULLPTR));
        lineEdit_chef->setPlaceholderText(QApplication::translate("employee", "211JMT...", Q_NULLPTR));
        box->clear();
        box->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("employee", "RH", Q_NULLPTR)
         << QApplication::translate("employee", "CM", Q_NULLPTR)
         << QApplication::translate("employee", "SM", Q_NULLPTR)
         << QApplication::translate("employee", "EM", Q_NULLPTR)
        );
        box->setCurrentText(QString());
        label_pic->setText(QString());
        groupBox_3->setTitle(QApplication::translate("employee", "search and sort", Q_NULLPTR));
        pushButton_search->setText(QApplication::translate("employee", "search", Q_NULLPTR));
        pushButton_sort->setText(QApplication::translate("employee", "sort", Q_NULLPTR));
        radioButton_first->setText(QApplication::translate("employee", "first name", Q_NULLPTR));
        radioButton_last->setText(QApplication::translate("employee", "last name", Q_NULLPTR));
        radioButton_salary->setText(QApplication::translate("employee", "salary", Q_NULLPTR));
        radioButton_ID->setText(QApplication::translate("employee", "ID", Q_NULLPTR));
        radioButton_first2->setText(QApplication::translate("employee", "First name", Q_NULLPTR));
        radioButton_last2->setText(QApplication::translate("employee", "Last name", Q_NULLPTR));
        pushButton_export->setText(QApplication::translate("employee", "Export", Q_NULLPTR));
        Tabwidget->setTabText(Tabwidget->indexOf(RH_manager), QApplication::translate("employee", "RH_manager", Q_NULLPTR));
        label_pic2->setText(QString());
        groupBox_2->setTitle(QApplication::translate("employee", "controle", Q_NULLPTR));
        pushButton_send->setText(QApplication::translate("employee", "send message", Q_NULLPTR));
        lineEdit_send->setText(QApplication::translate("employee", "from ", Q_NULLPTR));
        lineEdit_send->setPlaceholderText(QString());
        Tabwidget->setTabText(Tabwidget->indexOf(RH_employees), QApplication::translate("employee", "messagerie", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class employee: public Ui_employee {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMPLOYEE_H
