#ifndef HANDLE_H
#define HANDLE_H

#include <QObject>
#include <QTcpSocket>
#include "mainwindow.h"
#include "ui_mainwindow.h"

class Handle : public QObject
{
    Q_OBJECT
public:
    explicit Handle(MainWindow* window,QTcpSocket *s, QObject *parent = 0);

signals:
    void StrReceived(const QString &s);
    void finished(QThread *thread);

public slots:
    void start();

protected:

private slots:
    void disconnect();
    void read();

private:
    QTcpSocket *mSocket;
    qint64 mBytesAvailable;
    QString s;
public:
    void send(QString s);
    MainWindow* window;
};


#endif // HANDLE_H
