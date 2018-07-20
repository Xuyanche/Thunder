/********************************************************************************
** Form generated from reading UI file 'congratulation.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
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
        label->setGeometry(QRect(80, 40, 371, 131));
        label->setPixmap(QPixmap(QString::fromUtf8(":/start/image/victory.png")));
        label->setScaledContents(true);
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
        label->setText(QString());
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
