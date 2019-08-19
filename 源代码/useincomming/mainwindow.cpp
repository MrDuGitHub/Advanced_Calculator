#include "mainwindow.h"
#include "work.h"
#include "ui_mainwindow.h"
#include "conn.h"
#include "ui_conn.h"
#include "conn.h"
#include "ui_conn.h"
#include<QTcpSocket>
#include<QHostAddress>
#include<QString>
#include<QByteArray>
#include<QDataStream>
#include<QMessageBox>
#include<qDebug>
#include<qpalette>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->monitor0->setAlignment(Qt::AlignRight);
    ui->monitor1->setAlignment(Qt::AlignRight);
    ui->monitor2->setAlignment(Qt::AlignLeft);
    ui->monitor3->setAlignment(Qt::AlignLeft);

    this->grabKeyboard();
    this->setWindowOpacity(0.95);
    this->setWindowTitle("高级计算器");
    this->setWindowIcon(QIcon(":/myImages/image/Icon.png"));
    ui->clear_2->setIcon(QIcon(":/myImages/image/clear.png"));
    ui->clear_3->setIcon(QIcon(":/myImages/image/clear.png"));
    connect(ui->action_C,SIGNAL(triggered()),this,SLOT(show_conn()));
    connect(ui->action_D,SIGNAL(triggered()),this,SLOT(disconn()));
    connect(c.ui->connect_2,SIGNAL(clicked()),this,SLOT(toConn()));
    connect(ui->action_H,SIGNAL(triggered()),this,SLOT(show_help()));
    connect_mode();
    reset();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::send(QString s)
{
    QByteArray arr;
 //   qDebug()<<s;
    QDataStream dts(&arr,QIODevice::WriteOnly);
    dts<<s;
    bool n=this->socket->write(arr);
    this->socket->waitForBytesWritten();
  //  qDebug()<<"发送成功";
}

void MainWindow::on_readyread()
{
 //   qDebug()<<"提示 开始接受";
    QByteArray array=this->socket->readAll();
    QDataStream dts(&array,QIODevice::ReadOnly);
    QString data;
    dts>>data;
    show_ans(data);
}

void MainWindow::on_conn()
{
    QMessageBox::about(this,"提示","连接成功");
}

void MainWindow::on_discon()
{
 //  qDebug()<<"与服务器断开连接！";
    QMessageBox::about(this,"提示","与服务器断开连接！");
}

void MainWindow::on_pushButton_4_clicked()
{}

void MainWindow::attion()
{
    QMessageBox::about(this,"提示","该功能尚未完成");
}

void MainWindow::show_ans(QString s)
{
    ui->monitor1->setPlainText("");
    ui->monitor1->setPlainText(s);
    ui->monitor1->setAlignment(Qt::AlignRight);
    save_h();
    show_b=true;
}

void MainWindow::on_action_C_triggered()
{
   this->releaseKeyboard();
   c.show();
}

void MainWindow::show_conn()
{
    this->releaseKeyboard();
    c.show();
}

void MainWindow::show_help()
{
    h.show();
}

void MainWindow::disconn()
{
    this->socket->close();
}

void MainWindow::toConn()
{
    QString IP=c.ui->IPtext->toPlainText();
    int PORT=c.ui->porttext->toPlainText().toInt();
    this->socket=new QTcpSocket(this);
    this->socket->connectToHost(IP,PORT);
  //  this->socket->connectToHost(QHostAddress::LocalHost,520);//"192.168.1.225"
    connect(this->socket,SIGNAL(connected()),this,SLOT(on_conn()));
    connect(this->socket,SIGNAL(readyRead()),this,SLOT(on_readyread()));
    this->connect(this->socket,SIGNAL(disconnected()),this,SLOT(on_discon()));
    this->socket->waitForBytesWritten();
    c.close();
    this->grabKeyboard();
}
