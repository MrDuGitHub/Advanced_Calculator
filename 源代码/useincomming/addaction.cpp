#include<mainwindow.h>
#include "mainwindow.h"
#include "work.h"
#include "ui_mainwindow.h"
#include<QString>
#include<QByteArray>
#include<QDataStream>
#include<QMessageBox>
#include<qDebug>

void MainWindow::on_factorial_clicked()
{
    bool f;
    num=work_num(ui->monitor1->toPlainText());
    int n=num.toInt(&f,10);
    if (!f) return;
    if (num!="")
    {
       ui->monitor1->setPlainText(""+num+"!");
    }
    ui->monitor1->setAlignment(Qt::AlignRight);
    ui->monitor1->moveCursor(QTextCursor::End);
}

void MainWindow::on_pi_clicked()
{  
    if (show_b) on_clear_entry_clicked();show_b=false;
    num=work_num(ui->monitor1->toPlainText());
    if (num=="0")
    {
       ui->monitor1->setPlainText("π");
    }
    ui->monitor1->setAlignment(Qt::AlignRight);
    ui->monitor1->moveCursor(QTextCursor::End);
}


void MainWindow::on_power_ten_clicked()
{
 //   qDebug()<<ui->monitor1->toPlainText();
    num=work_num(ui->monitor1->toPlainText());
    if (num!="0")
    {
       ui->monitor1->setPlainText("(10)^"+ui->monitor1->toPlainText());
    }
    else
       ui->monitor1->setPlainText("(10)^");
 //   qDebug()<<ui->monitor1->toPlainText();
    ui->monitor1->setAlignment(Qt::AlignRight);
    ui->monitor1->moveCursor(QTextCursor::End);
}

void MainWindow::on_power_y_clicked()
{
    num=work_num(ui->monitor1->toPlainText());
    if (num!="")
    {
       ui->monitor1->setPlainText("("+num+")^");
    }
    ui->monitor1->setAlignment(Qt::AlignRight);
    ui->monitor1->moveCursor(QTextCursor::End);
}

void MainWindow::on_log_clicked()
{
    num=work_num(ui->monitor1->toPlainText());
    if (num!="0")
    {
       ui->monitor1->setPlainText("log("+num+")");
    }
    ui->monitor1->setAlignment(Qt::AlignRight);
    ui->monitor1->moveCursor(QTextCursor::End);
}


void MainWindow::on_GRD_clicked()
{
     if (ui->GRD->text()=="RAD")
     {
         ui->GRD->setText("GRAD");
         return;
     }
     if (ui->GRD->text()=="DEG")
     {
         ui->GRD->setText("RAD");
         return;
     }
     if (ui->GRD->text()=="GRAD")
         ui->GRD->setText("DEG");
     return;
}

void MainWindow::on_sin_clicked()
{
    num=work_num(ui->monitor1->toPlainText());
    if (ui->GRD->text()=="RAD")
        ui->monitor1->setPlainText("sin("+num+")");
    if (ui->GRD->text()=="GRAD")
        ui->monitor1->setPlainText("sin₉("+num+")");
    if (ui->GRD->text()=="DEG")
        ui->monitor1->setPlainText("sin₀("+num+")");
    ui->monitor1->setAlignment(Qt::AlignRight);
    ui->monitor1->moveCursor(QTextCursor::End);
}

void MainWindow::on_cos_clicked()
{
    num=work_num(ui->monitor1->toPlainText());
    if (ui->GRD->text()=="RAD")
        ui->monitor1->setPlainText("cos("+num+")");
    if (ui->GRD->text()=="GRAD")
        ui->monitor1->setPlainText("cos₉("+num+")");
    if (ui->GRD->text()=="DEG")
        ui->monitor1->setPlainText("cos₀("+num+")");
    ui->monitor1->setAlignment(Qt::AlignRight);
    ui->monitor1->moveCursor(QTextCursor::End);
}

void MainWindow::on_tan_clicked()
{
    num=work_num(ui->monitor1->toPlainText());
    if (ui->GRD->text()=="RAD")
        ui->monitor1->setPlainText("tan("+num+")");
    if (ui->GRD->text()=="GRAD")
        ui->monitor1->setPlainText("tan₉("+num+")");
    if (ui->GRD->text()=="DEG")
        ui->monitor1->setPlainText("tan₀("+num+")");
    ui->monitor1->setAlignment(Qt::AlignRight);
    ui->monitor1->moveCursor(QTextCursor::End);
}


void MainWindow::on_cube_clicked()
{
    num=work_num(ui->monitor1->toPlainText());
    if (num!="0")
    {
       ui->monitor1->setPlainText("("+num+")³");
    }
    ui->monitor1->setAlignment(Qt::AlignRight);
    ui->monitor1->moveCursor(QTextCursor::End);
}

void MainWindow::on_N_power_clicked()
{
 //  qDebug()<<ui->monitor1->toPlainText();
    num=work_num(ui->monitor1->toPlainText());
    if (num!="0")
    {
       ui->monitor1->setPlainText("(e)^"+ui->monitor1->toPlainText());
    }
    else
       ui->monitor1->setPlainText("(e)^");
  //  qDebug()<<ui->monitor1->toPlainText();
    ui->monitor1->setAlignment(Qt::AlignRight);
    ui->monitor1->moveCursor(QTextCursor::End);
}

void MainWindow::on_ln_clicked()
{
    num=work_num(ui->monitor1->toPlainText());
    if (num!="0")
    {
       ui->monitor1->setPlainText("ln("+num+")");
    }
    ui->monitor1->setAlignment(Qt::AlignRight);
    ui->monitor1->moveCursor(QTextCursor::End);
}

void MainWindow::on_sin_01_clicked()
{
    num=work_num(ui->monitor1->toPlainText());
    if (ui->GRD->text()=="RAD")
        ui->monitor1->setPlainText("sin⁻¹("+num+")");
    if (ui->GRD->text()=="GRAD")
        ui->monitor1->setPlainText("sin⁻¹₉("+num+")");
    if (ui->GRD->text()=="DEG")
        ui->monitor1->setPlainText("sin⁻¹₀("+num+")");
    ui->monitor1->setAlignment(Qt::AlignRight);
    ui->monitor1->moveCursor(QTextCursor::End);
}


void MainWindow::on_cos_01_clicked()
{
    num=work_num(ui->monitor1->toPlainText());
    if (ui->GRD->text()=="RAD")
        ui->monitor1->setPlainText("cos⁻¹("+num+")");
    if (ui->GRD->text()=="GRAD")
        ui->monitor1->setPlainText("cos⁻¹₉("+num+")");
    if (ui->GRD->text()=="DEG")
        ui->monitor1->setPlainText("cos⁻¹₀("+num+")");
    ui->monitor1->setAlignment(Qt::AlignRight);
    ui->monitor1->moveCursor(QTextCursor::End);
}


void MainWindow::on_tan_01_clicked()
{
    num=work_num(ui->monitor1->toPlainText());
    if (ui->GRD->text()=="RAD")
        ui->monitor1->setPlainText("tan⁻¹("+num+")");
    if (ui->GRD->text()=="GRAD")
        ui->monitor1->setPlainText("tan⁻¹₉("+num+")");
    if (ui->GRD->text()=="DEG")
        ui->monitor1->setPlainText("tan⁻¹₀("+num+")");
    ui->monitor1->setAlignment(Qt::AlignRight);
    ui->monitor1->moveCursor(QTextCursor::End);
}

void MainWindow::on_sinh_clicked()
{
    num=work_num(ui->monitor1->toPlainText());
    ui->monitor1->setPlainText("sinh("+num+")");
    ui->monitor1->setAlignment(Qt::AlignRight);
    ui->monitor1->moveCursor(QTextCursor::End);
}

void MainWindow::on_cosh_clicked()
{
    num=work_num(ui->monitor1->toPlainText());
    ui->monitor1->setPlainText("cosh("+num+")");
    ui->monitor1->setAlignment(Qt::AlignRight);
    ui->monitor1->moveCursor(QTextCursor::End);
}


void MainWindow::on_tanh_clicked()
{
    num=work_num(ui->monitor1->toPlainText());
    ui->monitor1->setPlainText("tanh("+num+")");
    ui->monitor1->setAlignment(Qt::AlignRight);
    ui->monitor1->moveCursor(QTextCursor::End);
}


void MainWindow::on_sinh_01_clicked()
{
    num=work_num(ui->monitor1->toPlainText());
    ui->monitor1->setPlainText("sinh⁻¹("+num+")");
    ui->monitor1->setAlignment(Qt::AlignRight);
    ui->monitor1->moveCursor(QTextCursor::End);
}


void MainWindow::on_cosh_01_clicked()
{
    num=work_num(ui->monitor1->toPlainText());
    ui->monitor1->setPlainText("cosh⁻¹("+num+")");
    ui->monitor1->setAlignment(Qt::AlignRight);
    ui->monitor1->moveCursor(QTextCursor::End);
}

void MainWindow::on_tanh_01_clicked()
{
    num=work_num(ui->monitor1->toPlainText());
    ui->monitor1->setPlainText("tanh⁻¹("+num+")");
    ui->monitor1->setAlignment(Qt::AlignRight);
    ui->monitor1->moveCursor(QTextCursor::End);
}

void MainWindow::on_arrow_clicked()
{
    ui->sqrt->setVisible(false);
    ui->square_2->setVisible(false);
    ui->power_ten->setVisible(false);
    ui->power_y->setVisible(false);
    ui->log->setVisible(false);
    ui->Exp->setVisible(false);
    ui->Mod->setVisible(false);
    ui->sin->setVisible(false);
    ui->cos->setVisible(false);
    ui->tan->setVisible(false);
    ui->sin_01->setVisible(false);
    ui->cos_01->setVisible(false);
    ui->tan_01->setVisible(false);
    if (ui->HYP->isVisible())
    {
        ui->sinh_01->setVisible(false);
        ui->cosh_01->setVisible(false);
        ui->tanh_01->setVisible(false);
        ui->sin_01->setVisible(true);
        ui->cos_01->setVisible(true);
        ui->tan_01->setVisible(true);

        ui->sin_01->setEnabled(true);
        ui->cos_01->setEnabled(true);
        ui->tan_01->setEnabled(true);
        ui->sinh->setEnabled(false);
        ui->cosh->setEnabled(false);
        ui->tanh->setEnabled(false);
        ui->sin->setEnabled(false);
        ui->cos->setEnabled(false);
        ui->tan->setEnabled(false);
        ui->sinh_01->setEnabled(false);
        ui->cosh_01->setEnabled(false);
        ui->tanh_01->setEnabled(false);

    }
    else
    {
        ui->sin_01->setVisible(false);
        ui->cos_01->setVisible(false);
        ui->tan_01->setVisible(false);
        ui->sinh_01->setVisible(true);
        ui->cosh_01->setVisible(true);
        ui->tanh_01->setVisible(true);

        ui->sinh_01->setEnabled(true);
        ui->cosh_01->setEnabled(true);
        ui->tanh_01->setEnabled(true);
        ui->sinh->setEnabled(false);
        ui->cosh->setEnabled(false);
        ui->tanh->setEnabled(false);
        ui->sin->setEnabled(false);
        ui->cos->setEnabled(false);
        ui->tan->setEnabled(false);
        ui->sinh_01->setEnabled(false);
        ui->cosh_01->setEnabled(false);
        ui->tanh_01->setEnabled(false);
    }
    ui->cube->setVisible(true);
    ui->reciprocal_2->setVisible(true);
    ui->N_power->setVisible(true);
    ui->N_Reagan->setVisible(true);
    ui->ln->setVisible(true);
    ui->dms->setVisible(true);
    ui->deg->setVisible(true);

    ui->arrow->setVisible(false);
    ui->arrow_2->setVisible(true);
}

void MainWindow::on_arrow_2_clicked()
{
    ui->sqrt->setVisible(true);
    ui->square_2->setVisible(true);
    ui->power_ten->setVisible(true);
    ui->power_y->setVisible(true);
    ui->log->setVisible(true);
    ui->Exp->setVisible(true);
    ui->Mod->setVisible(true);
    ui->sin_01->setVisible(false);
    ui->cos_01->setVisible(false);
    ui->tan_01->setVisible(false);
    ui->sinh_01->setVisible(false);
    ui->cosh_01->setVisible(false);
    ui->tanh_01->setVisible(false);
    if (ui->HYP->isVisible())
    {
        ui->sin->setVisible(true);
        ui->cos->setVisible(true);
        ui->tan->setVisible(true);
        ui->sinh->setVisible(false);
        ui->cosh->setVisible(false);
        ui->tanh->setVisible(false);

        ui->sin->setEnabled(true);
        ui->cos->setEnabled(true);
        ui->tan->setEnabled(true);
        ui->sinh->setEnabled(false);
        ui->cosh->setEnabled(false);
        ui->tanh->setEnabled(false);
        ui->sin_01->setEnabled(false);
        ui->cos_01->setEnabled(false);
        ui->tan_01->setEnabled(false);
        ui->sinh_01->setEnabled(false);
        ui->cosh_01->setEnabled(false);
        ui->tanh_01->setEnabled(false);
    }
    else
    {
        ui->sinh->setVisible(true);
        ui->cosh->setVisible(true);
        ui->tanh->setVisible(true);
        ui->sin->setVisible(false);
        ui->cos->setVisible(false);
        ui->tan->setVisible(false);

        ui->sinh->setEnabled(true);
        ui->cosh->setEnabled(true);
        ui->tanh->setEnabled(true);
        ui->sin->setEnabled(false);
        ui->cos->setEnabled(false);
        ui->tan->setEnabled(false);
        ui->sin_01->setEnabled(false);
        ui->cos_01->setEnabled(false);
        ui->tan_01->setEnabled(false);
        ui->sinh_01->setEnabled(false);
        ui->cosh_01->setEnabled(false);
        ui->tanh_01->setEnabled(false);
    }
    ui->cube->setVisible(false);
    ui->reciprocal_2->setVisible(false);
    ui->N_power->setVisible(false);
    ui->N_Reagan->setVisible(false);
    ui->ln->setVisible(false);
    ui->dms->setVisible(false);
    ui->deg->setVisible(false);

    ui->arrow_2->setVisible(false);
    ui->arrow->setVisible(true);
}

void MainWindow::on_HYP_clicked()
{
    if (ui->arrow->isVisible())
    {
        ui->sin->setVisible(false);
        ui->cos->setVisible(false);
        ui->tan->setVisible(false);
        ui->sinh->setVisible(true);
        ui->cosh->setVisible(true);
        ui->tanh->setVisible(true);

        ui->sinh->setEnabled(true);
        ui->cosh->setEnabled(true);
        ui->tanh->setEnabled(true);
        ui->sin_01->setEnabled(false);
        ui->cos_01->setEnabled(false);
        ui->tan_01->setEnabled(false);
        ui->sin_01->setEnabled(false);
        ui->cos_01->setEnabled(false);
        ui->tan_01->setEnabled(false);
        ui->sinh_01->setEnabled(false);
        ui->cosh_01->setEnabled(false);
        ui->tanh_01->setEnabled(false);

    }
    else
    {
        ui->sin_01->setVisible(false);
        ui->cos_01->setVisible(false);
        ui->tan_01->setVisible(false);
        ui->sinh_01->setVisible(true);
        ui->cosh_01->setVisible(true);
        ui->tanh_01->setVisible(true);

        ui->sinh_01->setEnabled(true);
        ui->cosh_01->setEnabled(true);
        ui->tanh_01->setEnabled(true);
        ui->sinh->setEnabled(false);
        ui->cosh->setEnabled(false);
        ui->tanh->setEnabled(false);
        ui->sin_01->setEnabled(false);
        ui->cos_01->setEnabled(false);
        ui->tan_01->setEnabled(false);
        ui->sin->setEnabled(false);
        ui->cos->setEnabled(false);
        ui->tan->setEnabled(false);
    }

    ui->HYP->setVisible(false);
    ui->HYP_2->setVisible(true);
}


void MainWindow::on_HYP_2_clicked()
{
    if (ui->arrow->isVisible())
    {
        ui->sin->setVisible(true);
        ui->cos->setVisible(true);
        ui->tan->setVisible(true);
        ui->sinh->setVisible(false);
        ui->cosh->setVisible(false);
        ui->tanh->setVisible(false);

        ui->sin->setEnabled(true);
        ui->cos->setEnabled(true);
        ui->tan->setEnabled(true);
        ui->sinh->setEnabled(false);
        ui->cosh->setEnabled(false);
        ui->tanh->setEnabled(false);
        ui->sin_01->setEnabled(false);
        ui->cos_01->setEnabled(false);
        ui->tan_01->setEnabled(false);
        ui->sinh_01->setEnabled(false);
        ui->cosh_01->setEnabled(false);
        ui->tanh_01->setEnabled(false);
    }
    else
    {
        ui->sin_01->setVisible(true);
        ui->cos_01->setVisible(true);
        ui->tan_01->setVisible(true);
        ui->sinh_01->setVisible(false);
        ui->cosh_01->setVisible(false);
        ui->tanh_01->setVisible(false);

        ui->sin_01->setEnabled(true);
        ui->cos_01->setEnabled(true);
        ui->tan_01->setEnabled(true);
        ui->sinh->setEnabled(false);
        ui->cosh->setEnabled(false);
        ui->tanh->setEnabled(false);
        ui->sin->setEnabled(false);
        ui->cos->setEnabled(false);
        ui->tan->setEnabled(false);
        ui->sinh_01->setEnabled(false);
        ui->cosh_01->setEnabled(false);
        ui->tanh_01->setEnabled(false);
    }
    ui->HYP->setVisible(true);
    ui->HYP_2->setVisible(false);
}
void MainWindow::on_pushButton_clicked()
{

}

void MainWindow::on_Left_Pare_clicked()
{
    attion();
    if (ui->monitor1->toPlainText()!="0")
    {
          return;
    }
    else
    {
          ui->monitor0->setPlainText(ui->monitor0->toPlainText()+" ( ");
    }
    ui->monitor0->setAlignment(Qt::AlignRight);
}

void MainWindow::on_Right_Pare_clicked()
{
    attion();
    if (ui->monitor1->toPlainText()=="0")
    {
          return;
    }
    else
    {
          ui->monitor0->setPlainText(ui->monitor0->toPlainText()+ui->monitor1->toPlainText()+" ");
          ui->monitor1->setPlainText(")");
    }
    ui->monitor0->setAlignment(Qt::AlignRight);
    ui->monitor1->setAlignment(Qt::AlignRight);
}

void MainWindow::on_Exp_clicked()
{
    attion();
}

void MainWindow::on_Mod_clicked()
{
    num=work_num(ui->monitor1->toPlainText());
    if (num!="0")
    {
        if (ui->monitor0->toPlainText()!="0")
            ui->monitor0->setPlainText(ui->monitor0->toPlainText()+num+" Mod ");
        else
            ui->monitor0->setPlainText(num+" Mod ");
        ui->monitor0->setAlignment(Qt::AlignRight);
        on_clear_entry_clicked();
        ui->monitor0->moveCursor(QTextCursor::End);
    }
}

void MainWindow::on_N_Reagan_clicked()
{
    attion();
}

void MainWindow::on_dms_clicked()
{
     attion();
}

void MainWindow::on_deg_clicked()
{
    attion();
}

void MainWindow::on_F_E_clicked()
{
    attion();
}
