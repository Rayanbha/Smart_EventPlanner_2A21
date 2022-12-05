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
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_hafla
{
public:
    QLabel *label;

    void setupUi(QDialog *hafla)
    {
        if (hafla->objectName().isEmpty())
            hafla->setObjectName(QStringLiteral("hafla"));
        hafla->resize(400, 300);
        label = new QLabel(hafla);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(110, 200, 56, 16));

        retranslateUi(hafla);

        QMetaObject::connectSlotsByName(hafla);
    } // setupUi

    void retranslateUi(QDialog *hafla)
    {
        hafla->setWindowTitle(QApplication::translate("hafla", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("hafla", "hafla", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class hafla: public Ui_hafla {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HAFLA_H
