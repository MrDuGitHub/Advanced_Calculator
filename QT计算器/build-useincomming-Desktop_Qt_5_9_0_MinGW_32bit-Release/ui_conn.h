/********************************************************************************
** Form generated from reading UI file 'conn.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONN_H
#define UI_CONN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_Conn
{
public:
    QLabel *port;
    QTextEdit *IPtext;
    QLabel *IP;
    QTextEdit *porttext;
    QPushButton *connect_2;
    QPushButton *exit;

    void setupUi(QDialog *Conn)
    {
        if (Conn->objectName().isEmpty())
            Conn->setObjectName(QStringLiteral("Conn"));
        Conn->resize(400, 300);
        QIcon icon;
        icon.addFile(QStringLiteral(":/myImages/image/conn.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon.addFile(QStringLiteral(":/myImages/image/conn.png"), QSize(), QIcon::Normal, QIcon::On);
        icon.addFile(QStringLiteral("image/conn.png"), QSize(), QIcon::Disabled, QIcon::Off);
        icon.addFile(QStringLiteral(":/myImages/image/conn.png"), QSize(), QIcon::Disabled, QIcon::On);
        icon.addFile(QStringLiteral(":/myImages/image/conn.png"), QSize(), QIcon::Active, QIcon::Off);
        icon.addFile(QStringLiteral(":/myImages/image/conn.png"), QSize(), QIcon::Active, QIcon::On);
        icon.addFile(QStringLiteral(":/myImages/image/conn.png"), QSize(), QIcon::Selected, QIcon::Off);
        icon.addFile(QStringLiteral(":/myImages/image/conn.png"), QSize(), QIcon::Selected, QIcon::On);
        Conn->setWindowIcon(icon);
        port = new QLabel(Conn);
        port->setObjectName(QStringLiteral("port"));
        port->setGeometry(QRect(40, 140, 72, 31));
        QFont font;
        font.setPointSize(19);
        font.setBold(true);
        font.setWeight(75);
        port->setFont(font);
        IPtext = new QTextEdit(Conn);
        IPtext->setObjectName(QStringLiteral("IPtext"));
        IPtext->setGeometry(QRect(140, 60, 221, 31));
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setWeight(75);
        IPtext->setFont(font1);
        IP = new QLabel(Conn);
        IP->setObjectName(QStringLiteral("IP"));
        IP->setGeometry(QRect(50, 60, 81, 31));
        IP->setFont(font);
        porttext = new QTextEdit(Conn);
        porttext->setObjectName(QStringLiteral("porttext"));
        porttext->setGeometry(QRect(140, 140, 221, 31));
        porttext->setFont(font1);
        connect_2 = new QPushButton(Conn);
        connect_2->setObjectName(QStringLiteral("connect_2"));
        connect_2->setGeometry(QRect(80, 210, 71, 41));
        exit = new QPushButton(Conn);
        exit->setObjectName(QStringLiteral("exit"));
        exit->setGeometry(QRect(240, 210, 71, 41));

        retranslateUi(Conn);
        QObject::connect(exit, SIGNAL(clicked()), Conn, SLOT(close()));

        QMetaObject::connectSlotsByName(Conn);
    } // setupUi

    void retranslateUi(QDialog *Conn)
    {
        Conn->setWindowTitle(QApplication::translate("Conn", "Connect", Q_NULLPTR));
        port->setText(QApplication::translate("Conn", "\347\253\257\345\217\243", Q_NULLPTR));
        IP->setText(QApplication::translate("Conn", "IP", Q_NULLPTR));
        connect_2->setText(QApplication::translate("Conn", "\350\277\236\346\216\245", Q_NULLPTR));
        exit->setText(QApplication::translate("Conn", "\351\200\200\345\207\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Conn: public Ui_Conn {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONN_H
