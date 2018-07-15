/********************************************************************************
** Form generated from reading UI file 'list.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LIST_H
#define UI_LIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_list
{
public:

    void setupUi(QDialog *list)
    {
        if (list->objectName().isEmpty())
            list->setObjectName(QStringLiteral("list"));
        list->resize(400, 315);

        retranslateUi(list);

        QMetaObject::connectSlotsByName(list);
    } // setupUi

    void retranslateUi(QDialog *list)
    {
        list->setWindowTitle(QApplication::translate("list", "list", nullptr));
    } // retranslateUi

};

namespace Ui {
    class list: public Ui_list {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIST_H
