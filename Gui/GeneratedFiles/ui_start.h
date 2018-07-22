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
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_startClass
{
public:
    QPushButton *startbutton;
    QLabel *tital;
    QPushButton *listbutton;
    QPushButton *peoplebutton;
    QPushButton *quitbutton;

    void setupUi(QDialog *startClass)
    {
        if (startClass->objectName().isEmpty())
            startClass->setObjectName(QStringLiteral("startClass"));
        startClass->resize(600, 400);
        startbutton = new QPushButton(startClass);
        startbutton->setObjectName(QStringLiteral("startbutton"));
        startbutton->setGeometry(QRect(230, 150, 151, 51));
        tital = new QLabel(startClass);
        tital->setObjectName(QStringLiteral("tital"));
        tital->setGeometry(QRect(170, 60, 271, 81));
        listbutton = new QPushButton(startClass);
        listbutton->setObjectName(QStringLiteral("listbutton"));
        listbutton->setGeometry(QRect(230, 200, 151, 51));
        peoplebutton = new QPushButton(startClass);
        peoplebutton->setObjectName(QStringLiteral("peoplebutton"));
        peoplebutton->setGeometry(QRect(230, 250, 151, 51));
        quitbutton = new QPushButton(startClass);
        quitbutton->setObjectName(QStringLiteral("quitbutton"));
        quitbutton->setGeometry(QRect(560, 0, 41, 41));

        retranslateUi(startClass);

        QMetaObject::connectSlotsByName(startClass);
    } // setupUi

    void retranslateUi(QDialog *startClass)
    {
        startClass->setWindowTitle(QApplication::translate("startClass", "start", nullptr));
        startbutton->setText(QString());
        tital->setText(QString());
        listbutton->setText(QString());
        peoplebutton->setText(QString());
        quitbutton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class startClass: public Ui_startClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_START_H
