#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    init();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::init()
{
    ui->lineEdit->setPlaceholderText("password...");
    ui->lineEdit->setEchoMode(QLineEdit::Password);
    ui->lineEdit->setReadOnly(false);
    ui->lineEdit->setClearButtonEnabled(true);
    ui->ButtonRegister->setEnabled(false);
    str_sql = "delete from user;";
    query.exec(str_sql);
    str_sql = "insert into user(name,pwd) values('admin123',123);";
    query.exec(str_sql);
    str_sql = "insert into user(name,pwd) values('user456',456);";
    query.exec(str_sql);
    str_sql = "insert into user(name,pwd) values('user123456',123456);";
    query.exec(str_sql);
    configWindow = new Form();
}

bool MainWindow::verify()
{
    QString pass=ui->lineEdit->text();
    ui->lineEdit->clear();
    query.exec(str_sql);
    str_sql = "select * from user";
    query.exec(str_sql);
    QString user;
    while(query.next()){
        if(!QString::compare(query.value(1).toString(),pass))
        {
            user = query.value(0).toString();
            if(!QString::compare(user,"admin123"))
            {
                QMessageBox::about(this,"User Verification","Welcome "+user+" !");
                ui->ButtonRegister->setEnabled(true);
            }
            else{
                QMessageBox::about(this,"User Verification","Welcome "+user+" !");
                ui->ButtonRegister->setEnabled(false);
            }
            ui->label->setText("Login as other user:");
            ui->lineEdit->setPlaceholderText("password...");
            return true;
        }
    }
    ui->label->setText("Try another Password:");
    QMessageBox::warning(this,"User Verification","Wrong Password!");
    ui->ButtonRegister->setEnabled(false);
    return false;
}
void MainWindow::on_ButtonEnter_clicked()
{
    verify();
}

void MainWindow::on_ButtonExit_clicked()
{
    QApplication* app;
    app->exit(0);
}

void MainWindow::on_ButtonClear_clicked()
{
    ui->lineEdit->clear();
}

void MainWindow::on_ButtonDelete_clicked()
{
    ui->lineEdit->backspace();
}

void MainWindow::on_Button0_clicked()
{
    ui->lineEdit->insert("0");
}

void MainWindow::on_Button1_clicked()
{
    ui->lineEdit->insert("1");
}

void MainWindow::on_Button2_clicked()
{
    ui->lineEdit->insert("2");
}

void MainWindow::on_Button3_clicked()
{
    ui->lineEdit->insert("3");
}

void MainWindow::on_Button4_clicked()
{
    ui->lineEdit->insert("4");
}

void MainWindow::on_Button5_clicked()
{
    ui->lineEdit->insert("5");
}

void MainWindow::on_Button6_clicked()
{
    ui->lineEdit->insert("6");
}

void MainWindow::on_Button7_clicked()
{
    ui->lineEdit->insert("7");
}

void MainWindow::on_Button8_clicked()
{
    ui->lineEdit->insert("8");
}

void MainWindow::on_Button9_clicked()
{
    ui->lineEdit->insert("9");
}

void MainWindow::on_ButtonRegister_clicked()
{
    //form *configWindow = new form;
    //configWindow->show();
    //configWindow.show();
    configWindow->show();
}
