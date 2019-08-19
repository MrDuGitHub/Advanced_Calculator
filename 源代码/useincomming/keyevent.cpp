#include"mainwindow.h"
#include"QKeyEvent"
#include "ui_mainwindow.h"
void MainWindow::keyPressEvent(QKeyEvent* event)
 {
    switch(event->key())
    {
    case Qt::Key_0:
        on_number_0_clicked();
        break;
    case Qt::Key_1:
        on_number_1_clicked();
        break;
    case Qt::Key_2:
        on_number_2_clicked();
        break;
    case Qt::Key_3:
        on_number_3_clicked();
        break;
    case Qt::Key_4:
        on_number_4_clicked();
        break;
    case Qt::Key_5:
        on_number_5_clicked();
        break;
    case Qt::Key_6:
        on_number_6_clicked();
        break;
    case Qt::Key_7:
        on_number_7_clicked();
        break;
    case Qt::Key_8:
        on_number_8_clicked();
        break;
    case Qt::Key_9:
        on_number_9_clicked();
        break;
    case Qt::Key_Plus:
        on_plus_clicked();
        break;
    case Qt::Key_Minus:
        on_minus_clicked();
        break;
    case Qt::Key_Asterisk:
        on_times_clicked();
        break;
    case Qt::Key_Slash:
        on_divide_clicked();
        break;
    case Qt::Key_Enter:
        on_equal_clicked();
        break;
    case Qt::Key_Return:
        on_equal_clicked();
        break;
    case Qt::Key_Period:
        on_point_clicked();
        break;
    case Qt::Key_Backspace:
        on_delete_2_clicked();
        break;
    case Qt::Key_Escape:
        on_clear_clicked();
        break;
    case Qt::Key_Delete:
        on_clear_entry_clicked();
        break;
    case Qt::Key_Q:
        on_square_clicked();
        break;
    case Qt::Key_F9:
        on_negate_clicked();
        break;
    case Qt::Key_Space:
        on_delete_2_clicked();
        break;
    case Qt::Key_R:
        on_reciprocal_clicked();
        break;
    case Qt::Key_E:
        on_Exp_clicked();
        break;
    case Qt::Key_T:
        ui->tan->click();
        ui->tanh->click();
        ui->tanh_01->click();
        ui->tan_01->click();
        break;
    case Qt::Key_S:
        ui->sin->click();
        ui->sinh->click();
        ui->sinh_01->click();
        ui->sin_01->click();
        break;
    case Qt::Key_C:
        ui->cos->click();
        ui->cosh->click();
        ui->cosh_01->click();
        ui->cos_01->click();
        break;
    case Qt::Key_Y:
        on_N_power_clicked();
        break;
    case Qt::Key_L:
        on_log_clicked();
        break;
    case Qt::Key_M:
        on_Mod_clicked();
        break;
    case Qt::Key_P:
        on_pi_clicked();
        break;
    case Qt::Key_N:
        on_ln_clicked();
        break;
    default:
       // qDebug("%x",event->key());
        break;
    }
 }
