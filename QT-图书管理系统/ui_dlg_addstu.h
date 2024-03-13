/********************************************************************************
** Form generated from reading UI file 'dlg_addstu.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLG_ADDSTU_H
#define UI_DLG_ADDSTU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dlg_AddStu
{
public:
    QWidget *horizontalLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *btn_cancel;
    QPushButton *btn_save;
    QLabel *label_5;
    QLineEdit *le_phone;
    QLineEdit *le_sno;
    QLabel *label_4;
    QLabel *label_3;
    QLineEdit *le_name;
    QLineEdit *le_sex;
    QSpinBox *sb_age;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *Dlg_AddStu)
    {
        if (Dlg_AddStu->objectName().isEmpty())
            Dlg_AddStu->setObjectName(QStringLiteral("Dlg_AddStu"));
        Dlg_AddStu->resize(304, 310);
        horizontalLayoutWidget = new QWidget(Dlg_AddStu);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 220, 194, 71));
        gridLayout = new QGridLayout(horizontalLayoutWidget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        btn_cancel = new QPushButton(horizontalLayoutWidget);
        btn_cancel->setObjectName(QStringLiteral("btn_cancel"));

        gridLayout->addWidget(btn_cancel, 0, 0, 1, 1);

        btn_save = new QPushButton(horizontalLayoutWidget);
        btn_save->setObjectName(QStringLiteral("btn_save"));

        gridLayout->addWidget(btn_save, 0, 1, 1, 1);

        label_5 = new QLabel(Dlg_AddStu);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(11, 52, 30, 16));
        le_phone = new QLineEdit(Dlg_AddStu);
        le_phone->setObjectName(QStringLiteral("le_phone"));
        le_phone->setGeometry(QRect(11, 114, 259, 16));
        le_sno = new QLineEdit(Dlg_AddStu);
        le_sno->setObjectName(QStringLiteral("le_sno"));
        le_sno->setGeometry(QRect(11, 196, 259, 16));
        label_4 = new QLabel(Dlg_AddStu);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(11, 93, 30, 16));
        label_3 = new QLabel(Dlg_AddStu);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(11, 175, 30, 16));
        le_name = new QLineEdit(Dlg_AddStu);
        le_name->setObjectName(QStringLiteral("le_name"));
        le_name->setGeometry(QRect(11, 32, 259, 16));
        le_sex = new QLineEdit(Dlg_AddStu);
        le_sex->setObjectName(QStringLiteral("le_sex"));
        le_sex->setGeometry(QRect(11, 73, 259, 16));
        sb_age = new QSpinBox(Dlg_AddStu);
        sb_age->setObjectName(QStringLiteral("sb_age"));
        sb_age->setGeometry(QRect(11, 155, 41, 16));
        label = new QLabel(Dlg_AddStu);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(11, 11, 30, 16));
        label_2 = new QLabel(Dlg_AddStu);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(11, 134, 30, 16));

        retranslateUi(Dlg_AddStu);

        QMetaObject::connectSlotsByName(Dlg_AddStu);
    } // setupUi

    void retranslateUi(QDialog *Dlg_AddStu)
    {
        Dlg_AddStu->setWindowTitle(QApplication::translate("Dlg_AddStu", "\346\267\273\345\212\240\344\270\216\344\277\256\346\224\271", Q_NULLPTR));
        btn_cancel->setText(QApplication::translate("Dlg_AddStu", "\345\217\226\346\266\210", Q_NULLPTR));
        btn_save->setText(QApplication::translate("Dlg_AddStu", "\344\277\235\345\255\230", Q_NULLPTR));
        label_5->setText(QApplication::translate("Dlg_AddStu", "\346\200\247\345\210\253", Q_NULLPTR));
        label_4->setText(QApplication::translate("Dlg_AddStu", "\347\224\265\350\257\235", Q_NULLPTR));
        label_3->setText(QApplication::translate("Dlg_AddStu", "\345\255\246\345\217\267", Q_NULLPTR));
        label->setText(QApplication::translate("Dlg_AddStu", "\345\247\223\345\220\215", Q_NULLPTR));
        label_2->setText(QApplication::translate("Dlg_AddStu", "\345\271\264\351\276\204", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dlg_AddStu: public Ui_Dlg_AddStu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLG_ADDSTU_H
