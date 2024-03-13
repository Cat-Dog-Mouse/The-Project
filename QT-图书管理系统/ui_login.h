/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_login
{
public:
    QGridLayout *gridLayout;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QLineEdit *le_username;
    QPushButton *bt_login;
    QPushButton *bt_exit;
    QFrame *frame_2;
    QLineEdit *le_password;
    QLabel *lb_password;
    QLabel *lb_username;
    QLabel *label_3;

    void setupUi(QWidget *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName(QStringLiteral("login"));
        login->resize(409, 273);
        login->setMinimumSize(QSize(400, 200));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Image/icon.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        login->setWindowIcon(icon);
        login->setLayoutDirection(Qt::LeftToRight);
        login->setAutoFillBackground(false);
        login->setStyleSheet(QStringLiteral(""));
        gridLayout = new QGridLayout(login);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(login);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setStyleSheet(QLatin1String("#frame{\n"
"	border-image: url(:/Image_2/image_main.png);\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        le_username = new QLineEdit(frame);
        le_username->setObjectName(QStringLiteral("le_username"));
        le_username->setEnabled(true);
        le_username->setStyleSheet(QLatin1String("QLineEdit{border:2px;min-height:22;border-radius:6;\n"
"}"));

        gridLayout_2->addWidget(le_username, 9, 1, 1, 2);

        bt_login = new QPushButton(frame);
        bt_login->setObjectName(QStringLiteral("bt_login"));
        bt_login->setMinimumSize(QSize(150, 30));
        bt_login->setMaximumSize(QSize(300, 300));
        QFont font;
        font.setFamily(QStringLiteral("Agency FB"));
        font.setPointSize(11);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        bt_login->setFont(font);
        bt_login->setStyleSheet(QLatin1String("QPushButton{\n"
"	border-radius:6;\n"
"	font: 11pt \"Agency FB\";\n"
"	background-color: #63c2aa;\n"
"	color: rgb(8, 8, 8);\n"
"}\n"
"\n"
""));
        bt_login->setCheckable(false);

        gridLayout_2->addWidget(bt_login, 14, 0, 1, 1);

        bt_exit = new QPushButton(frame);
        bt_exit->setObjectName(QStringLiteral("bt_exit"));
        bt_exit->setMinimumSize(QSize(150, 30));
        QFont font1;
        font1.setFamily(QStringLiteral("Agency FB"));
        font1.setPointSize(11);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setUnderline(false);
        font1.setWeight(50);
        bt_exit->setFont(font1);
        bt_exit->setStyleSheet(QLatin1String("QPushButton{\n"
"	border-radius:6;\n"
"	font: 11pt \"Agency FB\";\n"
"	background-color: #63c2aa;\n"
"	color: rgb(8, 8, 8);\n"
"}\n"
""));

        gridLayout_2->addWidget(bt_exit, 14, 2, 1, 1);

        frame_2 = new QFrame(frame);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);

        gridLayout_2->addWidget(frame_2, 1, 0, 1, 1);

        le_password = new QLineEdit(frame);
        le_password->setObjectName(QStringLiteral("le_password"));
        le_password->setStyleSheet(QLatin1String("QLineEdit{border:2px;min-height:22;border-radius:6;\n"
"	border-color: #2f3441\n"
"}"));
        le_password->setEchoMode(QLineEdit::Password);

        gridLayout_2->addWidget(le_password, 8, 1, 1, 2);

        lb_password = new QLabel(frame);
        lb_password->setObjectName(QStringLiteral("lb_password"));
        QFont font2;
        font2.setFamily(QStringLiteral("Agency FB"));
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setUnderline(true);
        font2.setWeight(75);
        lb_password->setFont(font2);
        lb_password->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        lb_password->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(lb_password, 9, 0, 1, 1);

        lb_username = new QLabel(frame);
        lb_username->setObjectName(QStringLiteral("lb_username"));
        lb_username->setFont(font2);
        lb_username->setStyleSheet(QLatin1String("color: rgb(52, 52, 52);\n"
""));
        lb_username->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(lb_username, 8, 0, 1, 1);

        label_3 = new QLabel(frame);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(150, 30));
        label_3->setMaximumSize(QSize(200, 30));
        QFont font3;
        font3.setFamily(QStringLiteral("Agency FB"));
        font3.setPointSize(16);
        font3.setBold(true);
        font3.setWeight(75);
        label_3->setFont(font3);
        label_3->setScaledContents(false);
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_3, 0, 0, 1, 2);


        gridLayout->addWidget(frame, 2, 0, 1, 1);


        retranslateUi(login);

        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QWidget *login)
    {
        login->setWindowTitle(QApplication::translate("login", "login", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        login->setToolTip(QApplication::translate("login", "\347\231\273\345\275\225\347\252\227\345\217\243", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_ACCESSIBILITY
        frame->setAccessibleName(QApplication::translate("login", "<html><head/><body><p><br/></p></body></html>", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        le_username->setText(QString());
        le_username->setPlaceholderText(QApplication::translate("login", "\350\257\267\350\276\223\345\205\245", Q_NULLPTR));
        bt_login->setText(QApplication::translate("login", "\347\231\273\345\275\225", Q_NULLPTR));
        bt_exit->setText(QApplication::translate("login", "\351\200\200\345\207\272", Q_NULLPTR));
        le_password->setInputMask(QString());
        le_password->setText(QString());
        le_password->setPlaceholderText(QApplication::translate("login", "\350\257\267\350\276\223\345\205\245", Q_NULLPTR));
        lb_password->setText(QApplication::translate("login", "\345\257\206\347\240\201", Q_NULLPTR));
        lb_username->setText(QApplication::translate("login", "\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        label_3->setText(QApplication::translate("login", "\345\233\276\344\271\246\347\256\241\347\220\206\347\263\273\347\273\237", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
