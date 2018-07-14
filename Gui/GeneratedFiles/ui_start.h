/********************************************************************************
** Form generated from reading UI file 'start.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_START_H
#define UI_START_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_startClass
{
public:

    void setupUi(QDialog *startClass)
    {
        if (startClass->objectName().isEmpty())
            startClass->setObjectName(QStringLiteral("startClass"));
        startClass->resize(600, 400);

        retranslateUi(startClass);

        QMetaObject::connectSlotsByName(startClass);
    } // setupUi

    void retranslateUi(QDialog *startClass)
    {
        startClass->setWindowTitle(QApplication::translate("startClass", "start", nullptr));
    } // retranslateUi

};

namespace Ui {
    class startClass: public Ui_startClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_START_H
