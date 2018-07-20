/********************************************************************************
** Form generated from reading UI file 'gameover.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEOVER_H
#define UI_GAMEOVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_gameover
{
public:
    QLabel *label;
    QPushButton *backbutton;
    QPushButton *restartbutton;

    void setupUi(QDialog *gameover)
    {
        if (gameover->objectName().isEmpty())
            gameover->setObjectName(QStringLiteral("gameover"));
        gameover->resize(400, 182);
        gameover->setAutoFillBackground(false);
        label = new QLabel(gameover);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 371, 81));
        label->setPixmap(QPixmap(QString::fromUtf8(":/start/image/over.png")));
        label->setScaledContents(true);
        backbutton = new QPushButton(gameover);
        backbutton->setObjectName(QStringLiteral("backbutton"));
        backbutton->setGeometry(QRect(280, 120, 101, 41));
        restartbutton = new QPushButton(gameover);
        restartbutton->setObjectName(QStringLiteral("restartbutton"));
        restartbutton->setGeometry(QRect(170, 120, 101, 41));

        retranslateUi(gameover);

        QMetaObject::connectSlotsByName(gameover);
    } // setupUi

    void retranslateUi(QDialog *gameover)
    {
        gameover->setWindowTitle(QApplication::translate("gameover", "gameover", nullptr));
        label->setText(QString());
        backbutton->setText(QString());
        restartbutton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class gameover: public Ui_gameover {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEOVER_H
