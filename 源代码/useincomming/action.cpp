#include<mainwindow.h>
#include "mainwindow.h"
#include "work.h"
#include "ui_mainwindow.h"
#include<QString>
#include<QByteArray>
#include<QDataStream>
#include<QMessageBox>
#include<qDebug>

void MainWindow::on_number_0_clicked()
{
    if (show_b) on_clear_entry_clicked();
    show_b=false;
    if(ui->monitor1->toPlainText() =="π")return;
    if (ui->monitor1->toPlainText() != tr("0"))
            ui->monitor1->textCursor().insertText("0");
    ui->monitor1->setAlignment(Qt::AlignRight);
}

void MainWindow::on_number_1_clicked()
{
    qDebug()<<show_b;
    if (show_b) on_clear_entry_clicked();    show_b=false;
     if(ui->monitor1->toPlainText() =="π")return;
    if (ui->monitor1->toPlainText() == tr("0"))
        ui->monitor1->setPlainText("");
    ui->monitor1->textCursor().insertText("1");
    ui->monitor1->setAlignment(Qt::AlignRight);
}


void MainWindow::on_number_2_clicked()
{
    if (show_b) on_clear_entry_clicked();show_b=false;
     if(ui->monitor1->toPlainText() =="π")return;
    if (ui->monitor1->toPlainText() == tr("0"))
        ui->monitor1->setPlainText("");
    ui->monitor1->textCursor().insertText("2");
    ui->monitor1->setAlignment(Qt::AlignRight);
}

void MainWindow::on_number_3_clicked()
{
    if (show_b) on_clear_entry_clicked();show_b=false;
     if(ui->monitor1->toPlainText() =="π")return;
    if (ui->monitor1->toPlainText() == tr("0"))
        ui->monitor1->setPlainText("");
    ui->monitor1->textCursor().insertText("3");
    ui->monitor1->setAlignment(Qt::AlignRight);
}

void MainWindow::on_number_4_clicked()
{
    if (show_b) on_clear_entry_clicked();show_b=false;
     if(ui->monitor1->toPlainText() =="π")return;
    if (ui->monitor1->toPlainText() == tr("0"))
        ui->monitor1->setPlainText("");
    ui->monitor1->textCursor().insertText("4");
    ui->monitor1->setAlignment(Qt::AlignRight);
}

void MainWindow::on_number_5_clicked()
{
    if (show_b) on_clear_entry_clicked();show_b=false;
     if(ui->monitor1->toPlainText() =="π")return;
    if (ui->monitor1->toPlainText() == tr("0"))
        ui->monitor1->setPlainText("");
    ui->monitor1->textCursor().insertText("5");
    ui->monitor1->setAlignment(Qt::AlignRight);
}

void MainWindow::on_number_6_clicked()
{
    if (show_b) on_clear_entry_clicked();show_b=false;
     if(ui->monitor1->toPlainText() =="π")return;
    if (ui->monitor1->toPlainText() == tr("0"))
        ui->monitor1->setPlainText("");
    ui->monitor1->textCursor().insertText("6");
    ui->monitor1->setAlignment(Qt::AlignRight);
}

void MainWindow::on_number_7_clicked()
{
    if (show_b) on_clear_entry_clicked();show_b=false;
     if(ui->monitor1->toPlainText() =="π")return;
    if (ui->monitor1->toPlainText() == tr("0"))
        ui->monitor1->setPlainText("");
    ui->monitor1->textCursor().insertText("7");
    ui->monitor1->setAlignment(Qt::AlignRight);
}

void MainWindow::on_number_8_clicked()
{
    if (show_b) on_clear_entry_clicked();show_b=false;
     if(ui->monitor1->toPlainText() =="π")return;
    if (ui->monitor1->toPlainText() == tr("0"))
        ui->monitor1->setPlainText("");
    ui->monitor1->textCursor().insertText("8");
    ui->monitor1->setAlignment(Qt::AlignRight);
}

void MainWindow::on_number_9_clicked()
{
    if (show_b) on_clear_entry_clicked();show_b=false;
     if(ui->monitor1->toPlainText() =="π")return;
    if (ui->monitor1->toPlainText() == tr("0"))
        ui->monitor1->setPlainText("");
    ui->monitor1->textCursor().insertText("9");
    ui->monitor1->setAlignment(Qt::AlignRight);
}

void MainWindow::on_negate_clicked()
{
     if(ui->monitor1->toPlainText() =="π")return;
    if (ui->monitor1->toPlainText()=="0") return;
    ui->monitor1->moveCursor(QTextCursor::Start);
    if (ui->monitor1->toPlainText().at(0) !='-')
        ui->monitor1->textCursor().insertText("-");
    else
    {
        num=ui->monitor1->toPlainText();
        num.remove(0,1);
        ui->monitor1->setPlainText(num);
    }
    ui->monitor1->moveCursor(QTextCursor::End);
    ui->monitor1->setAlignment(Qt::AlignRight);
}

void MainWindow::on_point_clicked()
{
    if (show_b) on_clear_entry_clicked();show_b=false;
     if(ui->monitor1->toPlainText() =="π")return;
    ui->monitor1->moveCursor(QTextCursor::End);
    if (ui->monitor1->toPlainText()=="0")
    {
        ui->monitor1->setPlainText("0.");
    }
    else
    if (ui->monitor1->toPlainText().indexOf(".",0)==-1)
        ui->monitor1->textCursor().insertText(".");
    ui->monitor1->moveCursor(QTextCursor::End);
    ui->monitor1->setAlignment(Qt::AlignRight);
}

void MainWindow::on_plus_clicked()
{
    num=work_num(ui->monitor1->toPlainText());
    if (num!="0")
    {
        if (ui->monitor0->toPlainText()!="0")
            ui->monitor0->setPlainText(ui->monitor0->toPlainText()+num+" + ");
        else
            ui->monitor0->setPlainText(num+" + ");
        ui->monitor0->setAlignment(Qt::AlignRight);
        on_clear_entry_clicked();
        ui->monitor0->moveCursor(QTextCursor::End);
    }
}

void MainWindow::on_minus_clicked()
{
    num=work_num(ui->monitor1->toPlainText());
    if (num!="0")
    {
        if (ui->monitor0->toPlainText()!="0")
            ui->monitor0->setPlainText(ui->monitor0->toPlainText()+num+" - ");
        else
            ui->monitor0->setPlainText(num+" - ");
        ui->monitor0->setAlignment(Qt::AlignRight);
        on_clear_entry_clicked();
        ui->monitor0->moveCursor(QTextCursor::End);
    }
}

void MainWindow::on_times_clicked()
{
    QChar c=QChar(0xFEFF00D7);
    num=work_num(ui->monitor1->toPlainText());
    if (num!="0")
    {
        if (ui->monitor0->toPlainText()!="0")
            ui->monitor0->setPlainText(ui->monitor0->toPlainText()+num+" "+c+" ");
        else
            ui->monitor0->setPlainText(num+" "+c+" ");
        ui->monitor0->setAlignment(Qt::AlignRight);
        on_clear_entry_clicked();
        ui->monitor0->moveCursor(QTextCursor::End);
    }
}


void MainWindow::on_divide_clicked()
{
    num=work_num(ui->monitor1->toPlainText());
    if (num!="0")
    {
        if (ui->monitor0->toPlainText()!="0")
            ui->monitor0->setPlainText(ui->monitor0->toPlainText()+num+" ÷ ");
        else
            ui->monitor0->setPlainText(num+" ÷ ");
        ui->monitor0->setAlignment(Qt::AlignRight);
        on_clear_entry_clicked();
        ui->monitor0->moveCursor(QTextCursor::End);
    }
}

void MainWindow::on_reciprocal_clicked()
{
    num=work_num(ui->monitor1->toPlainText());
    if (num!="0")
    {
       ui->monitor1->setPlainText("1/("+num+")");
    }
    ui->monitor1->setAlignment(Qt::AlignRight);
    ui->monitor1->moveCursor(QTextCursor::End);
}

void MainWindow::on_square_clicked()
{
    num=work_num(ui->monitor1->toPlainText());
    if (num!="0")
    {
       ui->monitor1->setPlainText("("+num+")²");
    }
    ui->monitor1->setAlignment(Qt::AlignRight);
    ui->monitor1->moveCursor(QTextCursor::End);
}


void MainWindow::on_radical_sign_clicked()
{
    num=work_num(ui->monitor1->toPlainText());
    if (num!="0")
    {
       ui->monitor1->setPlainText("√("+num+")");
    }
    ui->monitor1->setAlignment(Qt::AlignRight);
    ui->monitor1->moveCursor(QTextCursor::End);
}

void MainWindow::on_percent_clicked()
{
    num=work_num(ui->monitor1->toPlainText());
    if (num!="0")
    {
       ui->monitor1->setPlainText(""+num+"%");
    }
    ui->monitor1->setAlignment(Qt::AlignRight);
    ui->monitor1->moveCursor(QTextCursor::End);
}

void MainWindow::on_delete_2_clicked()
{
      if (show_b) on_clear_entry_clicked();show_b=false;
      ui->monitor1->moveCursor(QTextCursor::End);
      if(ui->monitor1->textCursor().hasSelection())//如果有选中，则取消，以免受受影响
              ui->monitor1->textCursor().clearSelection();
      ui->monitor1->textCursor().deletePreviousChar();//删除前一个字符
      ui->monitor1->moveCursor(QTextCursor::End);
}

void MainWindow::on_clear_entry_clicked()
{
    qDebug()<<show_b;
     ui->monitor1->setPlainText("0");
     ui->monitor1->moveCursor(QTextCursor::End);
     ui->monitor1->setAlignment(Qt::AlignRight);
}

void MainWindow::on_clear_clicked()
{
    on_clear_entry_clicked();
    ui->monitor0->setPlainText("0");
    ui->monitor0->moveCursor(QTextCursor::End);
    ui->monitor0->setAlignment(Qt::AlignRight);
}

void MainWindow::on_equal_clicked()
{
    num=work_num(ui->monitor1->toPlainText());
    if (num!="0")
    {
        if (ui->monitor0->toPlainText()!="0")
        {
           QString tem=ui->monitor0->toPlainText()+num+" ";
           ui->monitor0->setPlainText(tem);
        }
        else
           ui->monitor0->setPlainText(num+" ");
        QString s=work_str(ui->monitor0->toPlainText());
        send(s);
        ui->monitor0->setAlignment(Qt::AlignRight);
        on_clear_entry_clicked();
        ui->monitor0->moveCursor(QTextCursor::End);
    }
    ui->monitor3->setAlignment(Qt::AlignRight);
}


void MainWindow::on_mem_clear_clicked()
{
    on_clear_3_clicked();
}

void MainWindow::on_mm_read_clicked()
{
    num.setNum(mem);
    ui->monitor1->setPlainText(num);
    ui->monitor1->moveCursor(QTextCursor::End);
    ui->monitor1->setAlignment(Qt::AlignRight);
}

void MainWindow::on_mem_plus_clicked()
{
    int tem;
    double tem0;
    qDebug()<<ui->monitor1->toPlainText();
    if (ui->monitor1->toPlainText().indexOf('.') == -1)
    {
        tem=ui->monitor1->toPlainText().toInt();
         mem+=tem;
         num.setNum(mem);
    }
    else
    {
         tem0=ui->monitor1->toPlainText().toDouble();
         mem+=tem0;
         qDebug()<<tem0<<mem;
         num.setNum(mem);
    }
    qDebug()<<num;
    ui->monitor2->setPlainText(num);
    ui->monitor2->moveCursor(QTextCursor::End);
    ui->monitor2->setAlignment(Qt::AlignRight);
}

void MainWindow::on_mem_minus_clicked()
{
    int tem;
    double tem0;
    qDebug()<<ui->monitor1->toPlainText();
    if (ui->monitor1->toPlainText().indexOf('.') == -1)
    {
        tem=ui->monitor1->toPlainText().toInt();
         mem-=tem;
         num.setNum(mem);
    }
    else
    {
         tem0=ui->monitor1->toPlainText().toDouble();
         mem-=tem0;
         qDebug()<<tem0<<mem;
         num.setNum(mem);
    }
    num.setNum(mem);
    ui->monitor2->setPlainText(num);
    ui->monitor2->moveCursor(QTextCursor::End);
    ui->monitor2->setAlignment(Qt::AlignRight);
}


void MainWindow::on_mem_save_clicked()
{
    int tem;
    double tem0;
    if (mem==0)
        on_mem_plus_clicked();
    else
    {
        if (ui->monitor1->toPlainText().indexOf('.') == -1)
        {
            tem=ui->monitor1->toPlainText().toInt();
             mem=tem;
             num.setNum(mem);
        }
        else
        {
             tem0=ui->monitor1->toPlainText().toDouble();
             mem=tem0;
             qDebug()<<tem0<<mem;
             num.setNum(mem);
        }
        QString tem1=ui->monitor2->toPlainText();
        ui->mem_his->moveCursor(QTextCursor::Start);
        tem1="\n"+tem1+"\n";
        ui->mem_his->textCursor().insertText(tem1);
        ui->mem_his->moveCursor(QTextCursor::Start);
        ui->mem_his->setAlignment(Qt::AlignRight);
        ui->monitor2->setPlainText("");
        ui->monitor2->setPlainText(num);
        ui->monitor2->moveCursor(QTextCursor::Start);
        ui->monitor2->setAlignment(Qt::AlignRight);
    }
}

void MainWindow::save_h()
{
    QString s=ui->monitor0->toPlainText();
    ui->monitor3->setAlignment(Qt::AlignRight);
    QString tem="";
    if (ui->monitor3->toPlainText()=="尚无历史纪录")
        ui->monitor3->setPlainText("");
    ui->monitor3->moveCursor(QTextCursor::Start);
    tem=ui->monitor1->toPlainText()+"\n";
    ui->monitor3->textCursor().insertText(tem);
    ui->monitor3->moveCursor(QTextCursor::End);
    ui->monitor3->setAlignment(Qt::AlignRight);

    ui->monitor3->moveCursor(QTextCursor::Start);
    tem=ui->monitor0->toPlainText()+"=\n";
    ui->monitor3->textCursor().insertText(tem);
    ui->monitor3->moveCursor(QTextCursor::End);
    ui->monitor3->setAlignment(Qt::AlignRight);
    ui->monitor0->setPlainText("");
}

void MainWindow::on_memory_clicked()
{
    ui->monitor2->setVisible(true);
    ui->clear_3->setVisible(true);
    ui->monitor3->setVisible(false);
    ui->clear_2->setVisible(false);
    ui->mem_his->setVisible(true);
}

void MainWindow::on_history_clicked()
{
    ui->monitor3->setVisible(true);
    ui->clear_2->setVisible(true);
    ui->monitor2->setVisible(false);
    ui->clear_3->setVisible(false);
    ui->mem_his->setVisible(false);
}

void MainWindow::on_clear_2_clicked()
{
    ui->monitor3->clear();
    ui->monitor3->setPlainText("尚无历史纪录");
    ui->monitor3->moveCursor(QTextCursor::End);
    ui->monitor3->setAlignment(Qt::AlignLeft);
}

void MainWindow::on_clear_3_clicked()
{
    mem=0;
    ui->monitor2->clear();
    ui->monitor2->setPlainText("内存中没有内容");
    ui->monitor2->moveCursor(QTextCursor::End);
    ui->monitor2->setAlignment(Qt::AlignLeft);
    ui->mem_his->clear();
    ui->mem_his->setAlignment(Qt::AlignRight);
}
