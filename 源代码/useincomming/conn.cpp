#include "conn.h"
#include "ui_conn.h"

Conn::Conn(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Conn)
{
    ui->setupUi(this);
}

Conn::~Conn()
{
    delete ui;
}
