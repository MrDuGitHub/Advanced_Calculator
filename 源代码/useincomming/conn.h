#ifndef CONN_H
#define CONN_H

#include <QDialog>

namespace Ui {
class Conn;
}

class Conn : public QDialog
{
    Q_OBJECT

public:
    explicit Conn(QWidget *parent = 0);
    ~Conn();

private slots:
  //  void on_connect_2_clicked();

public:
    Ui::Conn *ui;
};

#endif // CONNECT_H
