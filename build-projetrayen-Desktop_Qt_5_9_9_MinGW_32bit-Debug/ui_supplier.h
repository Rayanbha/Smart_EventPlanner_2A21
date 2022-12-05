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
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_supplier
{
public:
    QLabel *label;

    void setupUi(QDialog *supplier)
    {
        if (supplier->objectName().isEmpty())
            supplier->setObjectName(QStringLiteral("supplier"));
        supplier->resize(400, 300);
        label = new QLabel(supplier);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(120, 140, 56, 16));

        retranslateUi(supplier);

        QMetaObject::connectSlotsByName(supplier);
    } // setupUi

    void retranslateUi(QDialog *supplier)
    {
        supplier->setWindowTitle(QApplication::translate("supplier", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("supplier", "supplier", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class supplier: public Ui_supplier {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUPPLIER_H
