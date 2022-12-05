/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFrame *frame;
    QLabel *label;
    QLineEdit *lineEdit_Username;
    QLineEdit *lineEdit_Password;
    QPushButton *pushButton_login;
    QLabel *label_2;
    QLabel *label_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(389, 501);
        MainWindow->setStyleSheet(QLatin1String("*\n"
"{\n"
"background-image: url(:/new/prefix1/img/cool-background.png);\n"
"}\n"
"QFrame\n"
"{\n"
"background:#728FCE	;\n"
"border-radius:15px;\n"
"}\n"
"#pushButton\n"
"{\n"
"background:#2B547E	;\n"
"border-radius:30px;\n"
"color:white;\n"
"}\n"
"QToolButton\n"
"{\n"
"background:transparent;\n"
"border-radius:50px;\n"
"}\n"
"\n"
"QLineEdit\n"
"{\n"
"background:transparent;\n"
"border:none;\n"
"color:#717072;\n"
"border-bottom:1px solid #717072;\n"
"}\n"
"QLabel\n"
"{\n"
"color:white;\n"
"\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 391, 451));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(140, 0, 121, 61));
        QFont font;
        font.setFamily(QStringLiteral("Segoe UI"));
        font.setPointSize(27);
        font.setBold(false);
        font.setItalic(true);
        font.setWeight(50);
        label->setFont(font);
        lineEdit_Username = new QLineEdit(frame);
        lineEdit_Username->setObjectName(QStringLiteral("lineEdit_Username"));
        lineEdit_Username->setGeometry(QRect(40, 140, 321, 41));
        QFont font1;
        font1.setFamily(QStringLiteral("Rockwell Condensed"));
        font1.setPointSize(24);
        lineEdit_Username->setFont(font1);
        lineEdit_Password = new QLineEdit(frame);
        lineEdit_Password->setObjectName(QStringLiteral("lineEdit_Password"));
        lineEdit_Password->setGeometry(QRect(40, 260, 321, 41));
        QFont font2;
        font2.setFamily(QStringLiteral("Rockwell Condensed"));
        font2.setPointSize(25);
        lineEdit_Password->setFont(font2);
        lineEdit_Password->setEchoMode(QLineEdit::Password);
        pushButton_login = new QPushButton(frame);
        pushButton_login->setObjectName(QStringLiteral("pushButton_login"));
        pushButton_login->setGeometry(QRect(20, 330, 351, 71));
        QFont font3;
        font3.setFamily(QStringLiteral("Segoe UI"));
        font3.setPointSize(20);
        font3.setBold(false);
        font3.setItalic(true);
        font3.setWeight(50);
        pushButton_login->setFont(font3);
        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 90, 191, 41));
        label_2->setFont(font2);
        label_3 = new QLabel(frame);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(40, 210, 131, 31));
        label_3->setFont(font2);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 389, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Login", Q_NULLPTR));
        lineEdit_Username->setText(QString());
        lineEdit_Password->setText(QString());
        pushButton_login->setText(QApplication::translate("MainWindow", "Login", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "UserName", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Password", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
