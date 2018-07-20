/********************************************************************************
** Form generated from reading UI file 'congratulation.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONGRATULATION_H
#define UI_CONGRATULATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_congratulation
{
public:
    QLabel *label;
    QPushButton *quitbutton;
    QPushButton *backbutton;
    QPushButton *restartbutton;

    void setupUi(QDialog *congratulation)
    {
        if (congratulation->objectName().isEmpty())
            congratulation->setObjectName(QStringLiteral("congratulation"));
        congratulation->resize(604, 300);
        label = new QLabel(congratulation);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 30, 511, 91));
        quitbutton = new QPushButton(congratulation);
        quitbutton->setObjectName(QStringLiteral("quitbutton"));
        quitbutton->setGeometry(QRect(450, 210, 131, 51));
        backbutton = new QPushButton(congratulation);
        backbutton->setObjectName(QStringLiteral("backbutton"));
        backbutton->setGeometry(QRect(300, 210, 131, 51));
        restartbutton = new QPushButton(congratulation);
        restartbutton->setObjectName(QStringLiteral("restartbutton"));
        restartbutton->setGeometry(QRect(150, 210, 131, 51));

        retranslateUi(congratulation);

        QMetaObject::connectSlotsByName(congratulation);
    } // setupUi

    void retranslateUi(QDialog *congratulation)
    {
        congratulation->setWindowTitle(QApplication::translate("congratulation", "congratulation", nullptr));
        label->setText(QApplication::translate("congratulation", "<html><head/><body><p><span style=\" font-size:28pt; font-weight:600; color:#550000;\">congratulations\357\274\201you win!</span></p></body></html>", nullptr));
        quitbutton->setText(QString());
        backbutton->setText(QString());
        restartbutton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class congratulation: public Ui_congratulation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONGRATULATION_H
