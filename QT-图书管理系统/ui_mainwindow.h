/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *stackedWidget;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QCheckBox *checkBox;
    QLineEdit *le_search;
    QLabel *lb_cnt;
    QPushButton *btn_search;
    QPushButton *btn_add;
    QPushButton *btn_update;
    QPushButton *btn_delete;
    QTableWidget *tableWidget_2;
    QLabel *label_3;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *Vertical;
    QLabel *label_admin;
    QLabel *label;
    QPushButton *bt_main_exit;
    QPushButton *btn_clear;
    QPushButton *btn_refresh;
    QPushButton *btn_simlation;
    QTreeWidget *treeWidget;
    QStatusBar *statusbar;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(907, 656);
        QFont font;
        font.setFamily(QStringLiteral("Agency FB"));
        font.setPointSize(7);
        MainWindow->setFont(font);
        QIcon icon;
        icon.addFile(QStringLiteral(":/Image/icon.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QStringLiteral(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        centralwidget->setStyleSheet(QStringLiteral(""));
        stackedWidget = new QWidget(centralwidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(220, 210, 681, 411));
        stackedWidget->setStyleSheet(QStringLiteral("background-color: rgb(105, 183, 255);"));
        verticalLayoutWidget_4 = new QWidget(stackedWidget);
        verticalLayoutWidget_4->setObjectName(QStringLiteral("verticalLayoutWidget_4"));
        verticalLayoutWidget_4->setGeometry(QRect(0, 0, 681, 411));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        checkBox = new QCheckBox(verticalLayoutWidget_4);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        horizontalLayout->addWidget(checkBox);

        le_search = new QLineEdit(verticalLayoutWidget_4);
        le_search->setObjectName(QStringLiteral("le_search"));

        horizontalLayout->addWidget(le_search);

        lb_cnt = new QLabel(verticalLayoutWidget_4);
        lb_cnt->setObjectName(QStringLiteral("lb_cnt"));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        lb_cnt->setFont(font1);

        horizontalLayout->addWidget(lb_cnt);

        btn_search = new QPushButton(verticalLayoutWidget_4);
        btn_search->setObjectName(QStringLiteral("btn_search"));
        QFont font2;
        font2.setBold(true);
        font2.setWeight(75);
        btn_search->setFont(font2);

        horizontalLayout->addWidget(btn_search);

        btn_add = new QPushButton(verticalLayoutWidget_4);
        btn_add->setObjectName(QStringLiteral("btn_add"));
        btn_add->setFont(font2);

        horizontalLayout->addWidget(btn_add);

        btn_update = new QPushButton(verticalLayoutWidget_4);
        btn_update->setObjectName(QStringLiteral("btn_update"));
        btn_update->setFont(font2);

        horizontalLayout->addWidget(btn_update);

        btn_delete = new QPushButton(verticalLayoutWidget_4);
        btn_delete->setObjectName(QStringLiteral("btn_delete"));
        btn_delete->setFont(font2);

        horizontalLayout->addWidget(btn_delete);


        verticalLayout_3->addLayout(horizontalLayout);

        tableWidget_2 = new QTableWidget(verticalLayoutWidget_4);
        tableWidget_2->setObjectName(QStringLiteral("tableWidget_2"));
        tableWidget_2->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
        tableWidget_2->setLineWidth(2);
        tableWidget_2->setMidLineWidth(2);
        tableWidget_2->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidget_2->horizontalHeader()->setStretchLastSection(true);
        tableWidget_2->verticalHeader()->setCascadingSectionResizes(false);

        verticalLayout_3->addWidget(tableWidget_2);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(0, 0, 731, 211));
        QFont font3;
        font3.setFamily(QStringLiteral("Microsoft YaHei"));
        font3.setPointSize(20);
        font3.setBold(false);
        font3.setWeight(50);
        label_3->setFont(font3);
        label_3->setToolTipDuration(-6);
        label_3->setStyleSheet(QLatin1String("border-image: url(:/Image_2/image_login.png);\n"
""));
        label_3->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(740, 0, 161, 201));
        Vertical = new QVBoxLayout(verticalLayoutWidget);
        Vertical->setSpacing(0);
        Vertical->setObjectName(QStringLiteral("Vertical"));
        Vertical->setContentsMargins(0, 0, 0, 0);
        label_admin = new QLabel(verticalLayoutWidget);
        label_admin->setObjectName(QStringLiteral("label_admin"));
        QFont font4;
        font4.setFamily(QStringLiteral("Agency FB"));
        font4.setPointSize(18);
        label_admin->setFont(font4);
        label_admin->setStyleSheet(QStringLiteral("background-color: rgb(171, 191, 255);"));
        label_admin->setAlignment(Qt::AlignCenter);

        Vertical->addWidget(label_admin);

        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QStringLiteral("border-image: url(:/Image/icon.jpg);"));

        Vertical->addWidget(label);

        bt_main_exit = new QPushButton(verticalLayoutWidget);
        bt_main_exit->setObjectName(QStringLiteral("bt_main_exit"));
        bt_main_exit->setMinimumSize(QSize(50, 50));
        bt_main_exit->setSizeIncrement(QSize(20, 20));
        QFont font5;
        font5.setPointSize(20);
        bt_main_exit->setFont(font5);
        bt_main_exit->setStyleSheet(QStringLiteral("background-color: rgb(183, 224, 255);"));
        bt_main_exit->setIconSize(QSize(400, 400));

        Vertical->addWidget(bt_main_exit);

        btn_clear = new QPushButton(verticalLayoutWidget);
        btn_clear->setObjectName(QStringLiteral("btn_clear"));

        Vertical->addWidget(btn_clear);

        btn_refresh = new QPushButton(verticalLayoutWidget);
        btn_refresh->setObjectName(QStringLiteral("btn_refresh"));

        Vertical->addWidget(btn_refresh);

        btn_simlation = new QPushButton(verticalLayoutWidget);
        btn_simlation->setObjectName(QStringLiteral("btn_simlation"));

        Vertical->addWidget(btn_simlation);

        treeWidget = new QTreeWidget(centralwidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->setGeometry(QRect(0, 210, 221, 411));
        treeWidget->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        treeWidget->header()->setVisible(false);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 907, 26));
        MainWindow->setMenuBar(menubar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\345\233\276\344\271\246\347\256\241\347\220\206\347\263\273\347\273\237", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        MainWindow->setToolTip(QApplication::translate("MainWindow", "\345\233\276\344\271\246\347\256\241\347\220\206\347\263\273\347\273\237", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        checkBox->setText(QApplication::translate("MainWindow", "\345\205\250\351\200\211", Q_NULLPTR));
        le_search->setText(QString());
        lb_cnt->setText(QApplication::translate("MainWindow", "\346\225\260\346\215\256\346\225\260\351\207\217", Q_NULLPTR));
        btn_search->setText(QApplication::translate("MainWindow", "\346\220\234\347\264\242", Q_NULLPTR));
        btn_add->setText(QApplication::translate("MainWindow", "\345\242\236\345\212\240", Q_NULLPTR));
        btn_update->setText(QApplication::translate("MainWindow", "\344\277\256\346\224\271", Q_NULLPTR));
        btn_delete->setText(QApplication::translate("MainWindow", "\345\210\240\351\231\244", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        tableWidget_2->setToolTip(QApplication::translate("MainWindow", "\345\233\276\344\271\246\347\256\241\347\220\206\347\263\273\347\273\237", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_3->setText(QApplication::translate("MainWindow", " \345\233\276\344\271\246\347\256\241\347\220\206\347\263\273\347\273\237", Q_NULLPTR));
        label_admin->setText(QApplication::translate("MainWindow", "\347\224\250\346\210\267\345\220\215:admin", Q_NULLPTR));
        label->setText(QString());
        bt_main_exit->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", Q_NULLPTR));
        btn_clear->setText(QApplication::translate("MainWindow", "\346\270\205\347\251\272\345\255\246\347\224\237\350\241\250", Q_NULLPTR));
        btn_refresh->setText(QApplication::translate("MainWindow", "\345\210\267\346\226\260", Q_NULLPTR));
        btn_simlation->setText(QApplication::translate("MainWindow", "\346\250\241\346\213\237\346\265\213\350\257\225", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
