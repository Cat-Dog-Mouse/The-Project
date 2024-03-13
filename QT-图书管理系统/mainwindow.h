#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "login.h"
#include "stusql.h"
//#include "page_longin.h"
#include <dlg_addstu.h>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
   // virtual void keyPressEvent(QKeyEvent *event);

private slots:
    void on_bt_main_exit_clicked();

    void on_btn_simlation_clicked();

    void on_btn_add_clicked();

    void on_btn_clear_clicked();
    void on_btn_refresh_clicked();

    void on_btn_delete_clicked();

    void on_btn_update_clicked();

    void on_btn_search_clicked();

private:
    void updateTable();

private:
    Ui::MainWindow *ui;
    login m_dlgLogin;
    stuSql *m_ptrStuSql;
    Dlg_AddStu  m_dlgAddStu;
};
#endif // MAINWINDOW_H
