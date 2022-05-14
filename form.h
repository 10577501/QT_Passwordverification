#ifndef FORM_H
#define FORM_H
#include <QSqlQuery>
#include <QWidget>
#include <QLabel>
#include <QEvent>
#include <QtDebug>
#include <QKeyEvent>

#include <QMouseEvent>
#include <QToolButton>
#include <QMessageBox>
namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = 0);
    ~Form();
    bool eventFilter(QObject *watched, QEvent *event);

private slots:
    void on_ButtonRegister_clicked();

    void on_ButtonExit_clicked();

    void on_lineEditUsername_editingFinished();

    void on_lineEditPassword_editingFinished();

    void hide_widget();

    void show_widget();

private:
    Ui::Form *ui;
    QSqlQuery query;
    QString str_sql;
};

#endif // FORM_H
