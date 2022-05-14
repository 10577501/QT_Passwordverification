#include "form.h"
#include "ui_form.h"
#include <QApplication>

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    ui->lineEditUsername->installEventFilter(this);
    ui->lineEditPassword->installEventFilter(this);
    ui->widget->hide();

    ui->lineEditUsername->setPlaceholderText("username...");
    ui->lineEditPassword->setPlaceholderText("password...");
    ui->lineEditPassword->setEchoMode(QLineEdit::PasswordEchoOnEdit);
    ui->lineEditUsername->setClearButtonEnabled(true);
    ui->lineEditPassword->setClearButtonEnabled(true);

}
void Form::hide_widget()
{
    ui->widget->hide();
}
void Form::show_widget()
{
    ui->widget->show();
}
bool Form::eventFilter(QObject *watched, QEvent *event)
{

    if ( (watched == ui->lineEditUsername) && (event->type() == QEvent::MouseButtonPress) )
    {
        show_widget();
        ui->lineEditUsername->setFocus();
    }
    else if ( (watched == ui->lineEditPassword) && (event->type() == QEvent::MouseButtonPress) )
    {
        show_widget();
        ui->lineEditPassword->setFocus();
    }

    return QWidget::eventFilter(watched,event);
}
void Form::on_ButtonRegister_clicked()
{
    QString username=ui->lineEditUsername->text();
    QString password=ui->lineEditPassword->text();
    if(username.isEmpty())
    {
        ui->label->setText("Please enter username!");
    }else if(password==0)
    {
        ui->label->setText("Please enter password!");
    }else
    {
        str_sql = "insert into user(name,pwd) values('"+username+"',"+password+");";
        //ui->label->setText(str_sql);
        query.exec(str_sql);
        this->close();
    }
}

void Form::on_ButtonExit_clicked()
{
    this->close();
}

void Form::on_lineEditUsername_editingFinished()
{
    hide_widget();
}

void Form::on_lineEditPassword_editingFinished()
{
    hide_widget();
}
Form::~Form()
{
    delete ui;
}
