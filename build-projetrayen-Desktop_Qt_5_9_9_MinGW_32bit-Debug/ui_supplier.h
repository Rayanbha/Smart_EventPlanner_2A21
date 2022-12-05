/********************************************************************************
** Form generated from reading UI file 'supplier.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUPPLIER_H
#define UI_SUPPLIER_H

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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_supplier
{
public:
    QTabWidget *tabWidget_provider;
    QWidget *tab;
    QGroupBox *groupBox;
    QTableView *tableView_provider;
    QPushButton *pushButton_modify_provider;
    QPushButton *pushButton_location;
    QGroupBox *groupBox_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineEdit_last_name_provider;
    QLineEdit *lineEdit_product_type_provider;
    QLineEdit *lineEdit_adress_provider;
    QLabel *label_8;
    QLineEdit *lineEdit_first_name_provider;
    QLineEdit *lineEdit_phone_provider;
    QLabel *label_10;
    QLabel *label_11;
    QLineEdit *lineEdit_price_provider;
    QLineEdit *lineEdit_quality_provider;
    QComboBox *comboBox;
    QLabel *label_6;
    QPushButton *pushButton_Stat;
    QLabel *label_5;
    QPushButton *recherche;
    QLabel *label_7;
    QLabel *label_12;
    QLineEdit *p;
    QPushButton *pushButton_delete_providert;
    QPushButton *pushButton_add_provider;
    QPushButton *pushButton_add_provider_5;
    QLineEdit *t;
    QLineEdit *n;
    QLineEdit *lineEdit_id_modify;
    QPushButton *pushButton_sort_providers;

    void setupUi(QDialog *supplier)
    {
        if (supplier->objectName().isEmpty())
            supplier->setObjectName(QStringLiteral("supplier"));
        supplier->resize(1219, 690);
        tabWidget_provider = new QTabWidget(supplier);
        tabWidget_provider->setObjectName(QStringLiteral("tabWidget_provider"));
        tabWidget_provider->setGeometry(QRect(0, 10, 1201, 691));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 1171, 651));
        groupBox->setStyleSheet(QLatin1String("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 178, 102, 255), stop:0.55 rgba(235, 148, 61, 255), stop:0.98 rgba(0, 0, 0, 255), stop:1 rgba(0, 0, 0, 0));\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 174, 216, 255), stop:1 rgba(255, 255, 255, 255));"));
        tableView_provider = new QTableView(groupBox);
        tableView_provider->setObjectName(QStringLiteral("tableView_provider"));
        tableView_provider->setGeometry(QRect(330, 150, 781, 351));
        tableView_provider->setStyleSheet(QLatin1String("background-color: rgb(211, 253, 255);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(85, 255, 255, 0), stop:1 rgba(255, 255, 255, 255));"));
        pushButton_modify_provider = new QPushButton(groupBox);
        pushButton_modify_provider->setObjectName(QStringLiteral("pushButton_modify_provider"));
        pushButton_modify_provider->setGeometry(QRect(410, 530, 131, 23));
        pushButton_modify_provider->setStyleSheet(QLatin1String("font: 8pt \"Cascadia Code\";\n"
"font: 10pt \"Cascadia Code\";"));
        pushButton_location = new QPushButton(groupBox);
        pushButton_location->setObjectName(QStringLiteral("pushButton_location"));
        pushButton_location->setGeometry(QRect(650, 510, 211, 71));
        pushButton_location->setStyleSheet(QLatin1String("font: 8pt \"Cascadia Code\";\n"
"font: 10pt \"Cascadia Code\";"));
        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(50, 90, 261, 401));
        groupBox_2->setStyleSheet(QLatin1String("font: 8pt \"Cascadia Code\";\n"
"background-color: rgb(211, 253, 255);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(85, 255, 255, 0), stop:1 rgba(255, 255, 255, 255));\n"
"font: 10pt \"Cascadia Code\";"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(1, 108, 111, 19));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(1, 155, 118, 19));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(1, 202, 63, 19));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(1, 249, 164, 19));
        lineEdit_last_name_provider = new QLineEdit(groupBox_2);
        lineEdit_last_name_provider->setObjectName(QStringLiteral("lineEdit_last_name_provider"));
        lineEdit_last_name_provider->setGeometry(QRect(130, 110, 121, 25));
        lineEdit_last_name_provider->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        lineEdit_product_type_provider = new QLineEdit(groupBox_2);
        lineEdit_product_type_provider->setObjectName(QStringLiteral("lineEdit_product_type_provider"));
        lineEdit_product_type_provider->setGeometry(QRect(130, 150, 121, 25));
        lineEdit_product_type_provider->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        lineEdit_adress_provider = new QLineEdit(groupBox_2);
        lineEdit_adress_provider->setObjectName(QStringLiteral("lineEdit_adress_provider"));
        lineEdit_adress_provider->setGeometry(QRect(130, 200, 121, 25));
        lineEdit_adress_provider->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(1, 61, 111, 19));
        lineEdit_first_name_provider = new QLineEdit(groupBox_2);
        lineEdit_first_name_provider->setObjectName(QStringLiteral("lineEdit_first_name_provider"));
        lineEdit_first_name_provider->setGeometry(QRect(130, 60, 121, 25));
        lineEdit_first_name_provider->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        lineEdit_phone_provider = new QLineEdit(groupBox_2);
        lineEdit_phone_provider->setObjectName(QStringLiteral("lineEdit_phone_provider"));
        lineEdit_phone_provider->setGeometry(QRect(170, 250, 81, 25));
        lineEdit_phone_provider->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(10, 290, 111, 19));
        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(10, 330, 111, 19));
        lineEdit_price_provider = new QLineEdit(groupBox_2);
        lineEdit_price_provider->setObjectName(QStringLiteral("lineEdit_price_provider"));
        lineEdit_price_provider->setGeometry(QRect(140, 290, 81, 25));
        lineEdit_price_provider->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        lineEdit_quality_provider = new QLineEdit(groupBox_2);
        lineEdit_quality_provider->setObjectName(QStringLiteral("lineEdit_quality_provider"));
        lineEdit_quality_provider->setGeometry(QRect(140, 330, 111, 25));
        lineEdit_quality_provider->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        comboBox = new QComboBox(groupBox);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(860, 80, 73, 22));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(500, 80, 56, 16));
        pushButton_Stat = new QPushButton(groupBox);
        pushButton_Stat->setObjectName(QStringLiteral("pushButton_Stat"));
        pushButton_Stat->setGeometry(QRect(930, 520, 140, 40));
        pushButton_Stat->setStyleSheet(QLatin1String("font: 8pt \"Cascadia Code\";\n"
"font: 10pt \"Cascadia Code\";"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(180, 500, 31, 16));
        label_5->setLayoutDirection(Qt::RightToLeft);
        recherche = new QPushButton(groupBox);
        recherche->setObjectName(QStringLiteral("recherche"));
        recherche->setGeometry(QRect(720, 70, 131, 41));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(490, 30, 56, 16));
        label_12 = new QLabel(groupBox);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(490, 120, 56, 16));
        p = new QLineEdit(groupBox);
        p->setObjectName(QStringLiteral("p"));
        p->setGeometry(QRect(570, 120, 113, 22));
        pushButton_delete_providert = new QPushButton(groupBox);
        pushButton_delete_providert->setObjectName(QStringLiteral("pushButton_delete_providert"));
        pushButton_delete_providert->setGeometry(QRect(410, 570, 121, 23));
        pushButton_delete_providert->setStyleSheet(QLatin1String("font: 8pt \"Cascadia Code\";\n"
"font: 10pt \"Cascadia Code\";"));
        pushButton_add_provider = new QPushButton(groupBox);
        pushButton_add_provider->setObjectName(QStringLiteral("pushButton_add_provider"));
        pushButton_add_provider->setGeometry(QRect(50, 500, 101, 23));
        pushButton_add_provider->setStyleSheet(QLatin1String("font: 8pt \"Cascadia Code\";\n"
"font: 10pt \"Cascadia Code\";"));
        pushButton_add_provider_5 = new QPushButton(groupBox);
        pushButton_add_provider_5->setObjectName(QStringLiteral("pushButton_add_provider_5"));
        pushButton_add_provider_5->setGeometry(QRect(880, 580, 101, 23));
        pushButton_add_provider_5->setStyleSheet(QLatin1String("font: 8pt \"Cascadia Code\";\n"
"font: 10pt \"Cascadia Code\";"));
        t = new QLineEdit(groupBox);
        t->setObjectName(QStringLiteral("t"));
        t->setGeometry(QRect(570, 30, 113, 22));
        n = new QLineEdit(groupBox);
        n->setObjectName(QStringLiteral("n"));
        n->setGeometry(QRect(570, 80, 113, 20));
        n->setStyleSheet(QLatin1String("selection-color: rgb(255, 255, 255);\n"
"background-color: rgb(255, 255, 255);"));
        lineEdit_id_modify = new QLineEdit(groupBox);
        lineEdit_id_modify->setObjectName(QStringLiteral("lineEdit_id_modify"));
        lineEdit_id_modify->setGeometry(QRect(240, 510, 113, 22));
        pushButton_sort_providers = new QPushButton(groupBox);
        pushButton_sort_providers->setObjectName(QStringLiteral("pushButton_sort_providers"));
        pushButton_sort_providers->setGeometry(QRect(950, 80, 91, 23));
        pushButton_sort_providers->setStyleSheet(QLatin1String("font: 8pt \"Cascadia Code\";\n"
"font: 10pt \"Cascadia Code\";"));
        tabWidget_provider->addTab(tab, QString());

        retranslateUi(supplier);

        tabWidget_provider->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(supplier);
    } // setupUi

    void retranslateUi(QDialog *supplier)
    {
        supplier->setWindowTitle(QApplication::translate("supplier", "Dialog", Q_NULLPTR));
        groupBox->setTitle(QString());
        pushButton_modify_provider->setText(QApplication::translate("supplier", "Modify provider", Q_NULLPTR));
        pushButton_location->setText(QApplication::translate("supplier", "location of closest provider", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("supplier", "Providers Manager", Q_NULLPTR));
        label->setStyleSheet(QApplication::translate("supplier", "font: 8pt \"Cascadia Code\";\n"
"font: 10pt \"Cascadia Code\";", Q_NULLPTR));
        label->setText(QApplication::translate("supplier", "Last name", Q_NULLPTR));
        label_2->setStyleSheet(QApplication::translate("supplier", "font: 8pt \"Cascadia Code\";\n"
"font: 10pt \"Cascadia Code\";", Q_NULLPTR));
        label_2->setText(QApplication::translate("supplier", "Product type", Q_NULLPTR));
        label_3->setStyleSheet(QApplication::translate("supplier", "font: 8pt \"Cascadia Code\";\n"
"font: 10pt \"Cascadia Code\";", Q_NULLPTR));
        label_3->setText(QApplication::translate("supplier", "Adress", Q_NULLPTR));
        label_4->setStyleSheet(QApplication::translate("supplier", "font: 8pt \"Cascadia Code\";\n"
"font: 10pt \"Cascadia Code\";", Q_NULLPTR));
        label_4->setText(QApplication::translate("supplier", "Phone number", Q_NULLPTR));
        label_8->setText(QApplication::translate("supplier", "First name", Q_NULLPTR));
        label_10->setText(QApplication::translate("supplier", "Price", Q_NULLPTR));
        label_11->setText(QApplication::translate("supplier", "Quality", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("supplier", "nom", Q_NULLPTR)
         << QApplication::translate("supplier", "numero", Q_NULLPTR)
        );
        label_6->setText(QApplication::translate("supplier", "nom", Q_NULLPTR));
        pushButton_Stat->setText(QApplication::translate("supplier", "Statistique", Q_NULLPTR));
        label_5->setText(QApplication::translate("supplier", "Id ", Q_NULLPTR));
        recherche->setText(QApplication::translate("supplier", "recherche", Q_NULLPTR));
        label_7->setText(QApplication::translate("supplier", "type", Q_NULLPTR));
        label_12->setText(QApplication::translate("supplier", "prenom", Q_NULLPTR));
        pushButton_delete_providert->setText(QApplication::translate("supplier", "Delete provider", Q_NULLPTR));
        pushButton_add_provider->setText(QApplication::translate("supplier", "Add provider", Q_NULLPTR));
        pushButton_add_provider_5->setText(QApplication::translate("supplier", "export pdf", Q_NULLPTR));
        pushButton_sort_providers->setText(QApplication::translate("supplier", "Sort", Q_NULLPTR));
        tabWidget_provider->setTabText(tabWidget_provider->indexOf(tab), QApplication::translate("supplier", "Provider Manager", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class supplier: public Ui_supplier {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUPPLIER_H
