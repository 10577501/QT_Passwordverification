#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QSqlQuery>
#include <QMainWindow>
#include "form.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void init();
    bool verify();

private slots:
    void on_Button7_clicked();

    void on_ButtonEnter_clicked();

    void on_ButtonExit_clicked();

    void on_ButtonClear_clicked();

    void on_ButtonDelete_clicked();

    void on_Button0_clicked();

    void on_Button1_clicked();

    void on_Button2_clicked();

    void on_Button3_clicked();

    void on_Button4_clicked();

    void on_Button5_clicked();

    void on_Button6_clicked();

    void on_Button8_clicked();

    void on_Button9_clicked();

    void on_ButtonRegister_clicked();

private:
    Ui::MainWindow *ui;
    QSqlQuery query;
    QString str_sql;
    Form *configWindow;
};

#endif // MAINWINDOW_H
