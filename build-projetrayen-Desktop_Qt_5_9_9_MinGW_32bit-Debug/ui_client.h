/********************************************************************************
** Form generated from reading UI file 'client.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENT_H
#define UI_CLIENT_H

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
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_client
{
public:
    QTabWidget *Mail;
    QWidget *tab_5;
    QLabel *label;
    QLineEdit *lineEdit_FirstName;
    QLabel *label_2;
    QLineEdit *lineEdit_LastName;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineEdit_CIN;
    QLabel *label_5;
    QLineEdit *lineEdit_Email;
    QLabel *label_6;
    QComboBox *event;
    QTableView *tableView;
    QGroupBox *groupBox;
    QPushButton *add;
    QPushButton *update;
    QPushButton *delete_2;
    QPushButton *pushButton;
    QDateEdit *dateEdit;
    QGroupBox *groupBox_2;
    QPushButton *search;
    QLineEdit *CIN2;
    QRadioButton *CIN1;
    QRadioButton *FirstName1;
    QRadioButton *LastName1;
    QWidget *tab_6;
    QGroupBox *groupBox_3;
    QPushButton *sort;
    QRadioButton *radioButton_firstname;
    QRadioButton *radioButton_lastname;
    QRadioButton *radioButton_CIN;
    QPushButton *Stat;
    QTableView *tableView_2;
    QPushButton *Excel;
    QPushButton *Export;
    QWidget *tab;
    QLabel *label_8;
    QLabel *label_9;
    QLineEdit *rcpt;
    QLineEdit *password;
    QLineEdit *subject;
    QLabel *label_10;
    QLabel *label_11;
    QLineEdit *file;
    QPushButton *browse;
    QPushButton *Send;
    QLineEdit *msg;
    QLabel *label_12;

    void setupUi(QDialog *client)
    {
        if (client->objectName().isEmpty())
            client->setObjectName(QStringLiteral("client"));
        client->resize(943, 539);
        Mail = new QTabWidget(client);
        Mail->setObjectName(QStringLiteral("Mail"));
        Mail->setGeometry(QRect(20, 30, 901, 481));
        Mail->setTabPosition(QTabWidget::West);
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        label = new QLabel(tab_5);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 70, 71, 21));
        label->setStyleSheet(QStringLiteral("border-color: rgb(0, 0, 0);"));
        lineEdit_FirstName = new QLineEdit(tab_5);
        lineEdit_FirstName->setObjectName(QStringLiteral("lineEdit_FirstName"));
        lineEdit_FirstName->setGeometry(QRect(140, 70, 171, 21));
        lineEdit_FirstName->setAutoFillBackground(false);
        lineEdit_FirstName->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"alternate-background-color: rgb(255, 255, 255);"));
        label_2 = new QLabel(tab_5);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(50, 110, 71, 21));
        lineEdit_LastName = new QLineEdit(tab_5);
        lineEdit_LastName->setObjectName(QStringLiteral("lineEdit_LastName"));
        lineEdit_LastName->setGeometry(QRect(140, 110, 171, 21));
        lineEdit_LastName->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_3 = new QLabel(tab_5);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(50, 150, 71, 20));
        label_4 = new QLabel(tab_5);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(50, 190, 71, 20));
        lineEdit_CIN = new QLineEdit(tab_5);
        lineEdit_CIN->setObjectName(QStringLiteral("lineEdit_CIN"));
        lineEdit_CIN->setGeometry(QRect(140, 190, 171, 20));
        lineEdit_CIN->setAcceptDrops(true);
        lineEdit_CIN->setStyleSheet(QLatin1String("background:white;\n"
""));
        lineEdit_CIN->setMaxLength(8);
        label_5 = new QLabel(tab_5);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(50, 230, 71, 20));
        lineEdit_Email = new QLineEdit(tab_5);
        lineEdit_Email->setObjectName(QStringLiteral("lineEdit_Email"));
        lineEdit_Email->setGeometry(QRect(140, 230, 171, 21));
        lineEdit_Email->setStyleSheet(QStringLiteral("background:white;"));
        label_6 = new QLabel(tab_5);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(50, 270, 71, 21));
        label_6->setStyleSheet(QStringLiteral("border-color: rgb(0, 0, 0);"));
        event = new QComboBox(tab_5);
        event->setObjectName(QStringLiteral("event"));
        event->setGeometry(QRect(140, 270, 171, 22));
        event->setStyleSheet(QStringLiteral("background:white;"));
        event->setEditable(true);
        tableView = new QTableView(tab_5);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(330, 30, 531, 281));
        groupBox = new QGroupBox(tab_5);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 30, 311, 401));
        add = new QPushButton(groupBox);
        add->setObjectName(QStringLiteral("add"));
        add->setGeometry(QRect(180, 290, 91, 23));
        update = new QPushButton(groupBox);
        update->setObjectName(QStringLiteral("update"));
        update->setGeometry(QRect(50, 290, 91, 21));
        delete_2 = new QPushButton(groupBox);
        delete_2->setObjectName(QStringLiteral("delete_2"));
        delete_2->setGeometry(QRect(180, 320, 91, 23));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(50, 320, 91, 21));
        dateEdit = new QDateEdit(groupBox);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setGeometry(QRect(130, 120, 171, 22));
        dateEdit->setStyleSheet(QStringLiteral("background:white;"));
        groupBox_2 = new QGroupBox(tab_5);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(330, 330, 531, 101));
        search = new QPushButton(groupBox_2);
        search->setObjectName(QStringLiteral("search"));
        search->setGeometry(QRect(420, 50, 91, 21));
        CIN2 = new QLineEdit(groupBox_2);
        CIN2->setObjectName(QStringLiteral("CIN2"));
        CIN2->setGeometry(QRect(180, 50, 231, 20));
        CIN1 = new QRadioButton(groupBox_2);
        CIN1->setObjectName(QStringLiteral("CIN1"));
        CIN1->setGeometry(QRect(90, 20, 85, 20));
        FirstName1 = new QRadioButton(groupBox_2);
        FirstName1->setObjectName(QStringLiteral("FirstName1"));
        FirstName1->setGeometry(QRect(90, 50, 85, 20));
        LastName1 = new QRadioButton(groupBox_2);
        LastName1->setObjectName(QStringLiteral("LastName1"));
        LastName1->setGeometry(QRect(90, 80, 85, 20));
        Mail->addTab(tab_5, QString());
        groupBox->raise();
        label->raise();
        lineEdit_FirstName->raise();
        label_2->raise();
        lineEdit_LastName->raise();
        label_3->raise();
        label_4->raise();
        lineEdit_CIN->raise();
        label_5->raise();
        lineEdit_Email->raise();
        label_6->raise();
        event->raise();
        tableView->raise();
        groupBox_2->raise();
        tab_6 = new QWidget();
        tab_6->setObjectName(QStringLiteral("tab_6"));
        groupBox_3 = new QGroupBox(tab_6);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(30, 30, 231, 411));
        sort = new QPushButton(groupBox_3);
        sort->setObjectName(QStringLiteral("sort"));
        sort->setGeometry(QRect(20, 140, 75, 23));
        radioButton_firstname = new QRadioButton(groupBox_3);
        radioButton_firstname->setObjectName(QStringLiteral("radioButton_firstname"));
        radioButton_firstname->setGeometry(QRect(110, 90, 83, 18));
        radioButton_lastname = new QRadioButton(groupBox_3);
        radioButton_lastname->setObjectName(QStringLiteral("radioButton_lastname"));
        radioButton_lastname->setGeometry(QRect(110, 140, 83, 18));
        radioButton_CIN = new QRadioButton(groupBox_3);
        radioButton_CIN->setObjectName(QStringLiteral("radioButton_CIN"));
        radioButton_CIN->setGeometry(QRect(110, 190, 83, 18));
        radioButton_CIN->setStyleSheet(QStringLiteral(""));
        Stat = new QPushButton(groupBox_3);
        Stat->setObjectName(QStringLiteral("Stat"));
        Stat->setGeometry(QRect(70, 350, 91, 23));
        tableView_2 = new QTableView(tab_6);
        tableView_2->setObjectName(QStringLiteral("tableView_2"));
        tableView_2->setGeometry(QRect(270, 40, 591, 231));
        Excel = new QPushButton(tab_6);
        Excel->setObjectName(QStringLiteral("Excel"));
        Excel->setGeometry(QRect(310, 390, 91, 22));
        Export = new QPushButton(tab_6);
        Export->setObjectName(QStringLiteral("Export"));
        Export->setGeometry(QRect(420, 390, 91, 23));
        Mail->addTab(tab_6, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        label_8 = new QLabel(tab);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 10, 221, 16));
        label_9 = new QLabel(tab);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(610, 10, 171, 16));
        rcpt = new QLineEdit(tab);
        rcpt->setObjectName(QStringLiteral("rcpt"));
        rcpt->setGeometry(QRect(10, 30, 581, 21));
        rcpt->setStyleSheet(QLatin1String("background:white\n"
";"));
        password = new QLineEdit(tab);
        password->setObjectName(QStringLiteral("password"));
        password->setGeometry(QRect(610, 30, 251, 21));
        password->setStyleSheet(QStringLiteral("background:white;"));
        subject = new QLineEdit(tab);
        subject->setObjectName(QStringLiteral("subject"));
        subject->setGeometry(QRect(10, 80, 851, 21));
        subject->setStyleSheet(QStringLiteral("background:white;"));
        label_10 = new QLabel(tab);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(10, 60, 101, 16));
        label_11 = new QLabel(tab);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(10, 110, 121, 16));
        file = new QLineEdit(tab);
        file->setObjectName(QStringLiteral("file"));
        file->setGeometry(QRect(10, 130, 761, 21));
        file->setStyleSheet(QStringLiteral("background:white;"));
        browse = new QPushButton(tab);
        browse->setObjectName(QStringLiteral("browse"));
        browse->setGeometry(QRect(780, 130, 80, 22));
        Send = new QPushButton(tab);
        Send->setObjectName(QStringLiteral("Send"));
        Send->setGeometry(QRect(390, 420, 80, 22));
        msg = new QLineEdit(tab);
        msg->setObjectName(QStringLiteral("msg"));
        msg->setGeometry(QRect(10, 180, 861, 231));
        label_12 = new QLabel(tab);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(10, 160, 101, 16));
        Mail->addTab(tab, QString());

        retranslateUi(client);

        Mail->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(client);
    } // setupUi

    void retranslateUi(QDialog *client)
    {
        client->setWindowTitle(QApplication::translate("client", "Dialog", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        Mail->setToolTip(QApplication::translate("client", "<html><head/><body><p>Email</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        Mail->setWhatsThis(QApplication::translate("client", "<html><head/><body><p>Email<br/></p></body></html>", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        label->setText(QApplication::translate("client", "First Name", Q_NULLPTR));
        lineEdit_FirstName->setInputMask(QString());
        lineEdit_FirstName->setText(QString());
        lineEdit_FirstName->setPlaceholderText(QString());
        label_2->setText(QApplication::translate("client", "Last Name", Q_NULLPTR));
        label_3->setText(QApplication::translate("client", "Day of birth", Q_NULLPTR));
        label_4->setText(QApplication::translate("client", "     CIN", Q_NULLPTR));
        label_5->setText(QApplication::translate("client", "    E-Mail", Q_NULLPTR));
        label_6->setText(QApplication::translate("client", "Type of Event", Q_NULLPTR));
        event->clear();
        event->insertItems(0, QStringList()
         << QApplication::translate("client", "Wedding", Q_NULLPTR)
         << QApplication::translate("client", "Party", Q_NULLPTR)
         << QApplication::translate("client", "Birthday", Q_NULLPTR)
         << QApplication::translate("client", "Bachelor Party", Q_NULLPTR)
        );
        event->setCurrentText(QApplication::translate("client", "Wedding", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("client", "Client ", Q_NULLPTR));
        add->setText(QApplication::translate("client", "Add", Q_NULLPTR));
        update->setText(QApplication::translate("client", "Update", Q_NULLPTR));
        delete_2->setText(QApplication::translate("client", "Delete", Q_NULLPTR));
        pushButton->setText(QApplication::translate("client", "Cancel", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("client", "Search", Q_NULLPTR));
        search->setText(QApplication::translate("client", "Search", Q_NULLPTR));
        CIN1->setText(QApplication::translate("client", "CIN", Q_NULLPTR));
        FirstName1->setText(QApplication::translate("client", "First Name", Q_NULLPTR));
        LastName1->setText(QApplication::translate("client", "Last Name", Q_NULLPTR));
        Mail->setTabText(Mail->indexOf(tab_5), QApplication::translate("client", "Gestion Client", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("client", "GroupBox", Q_NULLPTR));
        sort->setText(QApplication::translate("client", "Sort", Q_NULLPTR));
        radioButton_firstname->setText(QApplication::translate("client", "First Name", Q_NULLPTR));
        radioButton_lastname->setText(QApplication::translate("client", "Last Name", Q_NULLPTR));
        radioButton_CIN->setText(QApplication::translate("client", "CIN", Q_NULLPTR));
        Stat->setText(QApplication::translate("client", "Statistiques", Q_NULLPTR));
        Excel->setText(QApplication::translate("client", "Excel", Q_NULLPTR));
        Export->setText(QApplication::translate("client", "Export", Q_NULLPTR));
        Mail->setTabText(Mail->indexOf(tab_6), QApplication::translate("client", "Information", Q_NULLPTR));
        label_8->setText(QApplication::translate("client", "Email", Q_NULLPTR));
        label_9->setText(QApplication::translate("client", "Password", Q_NULLPTR));
        label_10->setText(QApplication::translate("client", "Subject", Q_NULLPTR));
        label_11->setText(QApplication::translate("client", "attachment", Q_NULLPTR));
        browse->setText(QApplication::translate("client", "Browse", Q_NULLPTR));
        Send->setText(QApplication::translate("client", "Send", Q_NULLPTR));
        label_12->setText(QApplication::translate("client", "Content", Q_NULLPTR));
        Mail->setTabText(Mail->indexOf(tab), QApplication::translate("client", "Email", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class client: public Ui_client {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENT_H
