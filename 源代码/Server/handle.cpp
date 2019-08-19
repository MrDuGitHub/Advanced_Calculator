#include "handle.h"
#include "work.h"
#include <QThread>
#include <QDebug>
#include<QString>
#include<QByteArray>
#include<QDataStream>
#include <QTcpSocket>
#include<QHostAddress>

Handle::Handle(MainWindow* window,QTcpSocket *s, QObject *parent) : QObject(parent), mSocket(s)
{
    this->window=window;
}

void Handle::start()
{
    mBytesAvailable = 0;
    connect(mSocket, SIGNAL(disconnected()), this, SLOT(disconnect()));
    connect(mSocket, SIGNAL(readyRead()), this, SLOT(read()));
 //   qDebug() << "[HANDLE]" << QThread::currentThread() << "new connected.";
    window->ui->textEdit->insertPlainText("[HANDLE] new connected. IP:"+mSocket->peerAddress().toString());
    window->ui->textEdit->insertPlainText("\n");
    s=mSocket->peerAddress().toString();
}

void Handle::disconnect()
{
    window->ui->textEdit->insertPlainText("[HANDLE] "+s+" disconnected.\n");
 //   qDebug() << "[HANDLE]" << QThread::currentThread() << "disconnected.";
    emit finished(QThread::currentThread());
}

void Handle::read()
{
 //   qDebug()<<"提示 开始接受";
    QByteArray array=mSocket->readAll();
    QDataStream dts(&array,QIODevice::ReadOnly);
    QString data;
    dts>>data;
  //  qDebug()<<data;
    QString ans;
    int n;
    double d;
    if ((data.indexOf('.')!=-1)||(data.indexOf("root")!=-1)||(data.indexOf("log")!=-1)
            ||(data.indexOf("divide")!=-1)||(data.indexOf("pi")!=-1)||(data.indexOf("sin")!=-1)
            ||(data.indexOf("cos")!=-1)||(data.indexOf("tan")!=-1)||
            (data.indexOf("ln")!=-1))
       {
        d=work<long double>(data);
        ans.setNum(d);
    }
    else
    {
     n=work<long long>(data);
     ans.setNum(n);
    }
    window->ui->textEdit->insertPlainText("[INFO] received :"+data+"from"+mSocket->peerAddress().toString()+"\n");
 //   qDebug()<<ans;
    send(ans);
}

void Handle::send(QString s)
{
    QByteArray arr;
    QDataStream dts(&arr,QIODevice::WriteOnly);
    dts<<s;
    window->ui->textEdit->insertPlainText("发送成功: Send "+s+" to "+mSocket->peerAddress().toString()+"\n");
    bool n=mSocket->write(arr);
    mSocket->waitForBytesWritten();
 //   qDebug()<<"发送成功";

 //   qDebug()<<s;
}
