#include "network.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QNetworkInterface>

Network::Network(MainWindow* window,QObject *parent) : QObject(parent)
{
    this->window=window;
    mServer = new QTcpServer(this);
    if(!mServer->listen(QHostAddress::Any, 520))
    {
        window->ui->textEdit->insertPlainText("Cannot listen on port 520\n");
     //  qDebug("Cannot listen on port 12333!");
    }
     //  qFatal("Cannot listen on port 12333!");
    connect(mServer, SIGNAL(newConnection()), this, SLOT(newConnection()));
    window->ui->textEdit->insertPlainText("[INFO] Server started at Port 520");
    window->ui->textEdit->insertPlainText("\n");
   // qDebug() << "[INFO] Server started...";
}

Network::~Network()
{
    qDebug() << "[INFO] Stopping the server...";
    window->ui->textEdit->insertPlainText("[INFO] Stopping the server...");
    window->ui->textEdit->insertPlainText("\n");
    for(auto &thread : mThreadPool)  {
        thread->quit();
        thread->wait();
        qDebug() << "[HANDLE]" << thread->objectName() << "deleted.";
        delete thread;
    }
}

void Network::newConnection()
{
    QThread *handleThread = new QThread(this);
    mThreadPool.append(handleThread);
    QTcpSocket *socket = mServer->nextPendingConnection();
    connect(handleThread, SIGNAL(finished()), socket, SLOT(deleteLater()));
    Handle *handle = new Handle(window,socket);
    connect(handleThread, SIGNAL(started()), handle, SLOT(start()));
    connect(handleThread, SIGNAL(finished()), handle, SLOT(deleteLater()));
    connect(handle, SIGNAL(finished(QThread*)), this, SLOT(join(QThread*)));
    handle->moveToThread(handleThread);
    handleThread->start();
}

void Network::join(QThread *thread)
{
    thread->quit();
    thread->wait();
    mThreadPool.removeAll(thread);
    qDebug() << "[HANDLE]" << thread << "deleted.";
  //  window->ui->textEdit->insertPlainText(qDebug() << "[HANDLE]" <<this->mSocket<< "deleted.");
    delete thread;
}
