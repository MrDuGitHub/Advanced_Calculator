#ifndef NETWORK_H
#define NETWORK_H

#include <QObject>
#include <QThread>
#include <QTcpServer>
#include <QList>
#include "handle.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

class Network : public QObject
{
    Q_OBJECT
public:
    explicit Network(MainWindow* window,QObject *parent = 0);
    ~Network();

signals:

private slots:
    void newConnection();
    void join(QThread *thread);

private:
    QTcpServer *mServer;
    QList<QThread *> mThreadPool;
    MainWindow* window;
};

#endif // NETWORK_H
