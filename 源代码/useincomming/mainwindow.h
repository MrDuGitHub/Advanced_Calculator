#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include "conn.h"
#include "help.h"

class QTcpSocket;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void reset();
    ~MainWindow();
private:
    QTcpSocket * socket;
    QString num="";
    int n=0;
    bool show_b=false;
    double mem=0;
private:
    Ui::MainWindow *ui;
    Conn c;
    Help h;
private:
    void connect_mode();
    void change(bool f);
    void attion();
    void show_ans(QString s);
    void save_h();
    void keyPressEvent(QKeyEvent* event);
private slots:
    void on_readyread();
    void on_conn();
    void on_discon();
    void send(QString s);
    void on_pushButton_4_clicked();
    void on_number_3_clicked();
    void on_number_0_clicked();
    void on_negate_clicked();
    void on_point_clicked();
    void on_equal_clicked();
    void on_number_1_clicked();
    void on_number_2_clicked();
    void on_number_4_clicked();
    void on_number_5_clicked();
    void on_number_6_clicked();
    void on_minus_clicked();
    void on_times_clicked();
    void on_number_9_clicked();
    void on_number_7_clicked();
    void on_number_8_clicked();
    void on_delete_2_clicked();
    void on_clear_entry_clicked();
    void on_clear_clicked();
    void on_plus_clicked();
    void on_divide_clicked();
    void on_reciprocal_clicked();
    void on_square_clicked();
    void on_radical_sign_clicked();
    void on_percent_clicked();
    void on_mem_clear_clicked();
    void on_mm_read_clicked();
    void on_mem_plus_clicked();
    void on_mem_minus_clicked();
    void on_memory_clicked();
    void on_history_clicked();
    void on_clear_2_clicked();
    void on_clear_3_clicked();
    void on_mem_save_clicked();
    void on_mode_clicked();
    void on_factorial_clicked();
    void on_pi_clicked();
    void on_power_ten_clicked();
    void on_power_y_clicked();
    void on_log_clicked();
    void on_GRD_clicked();
    void on_sin_clicked();
    void on_cos_clicked();
    void on_tan_clicked();
    void on_cube_clicked();
    void on_N_Reagan_clicked();
    void on_N_power_clicked();
    void on_ln_clicked();
    void on_sin_01_clicked();
    void on_cos_01_clicked();
    void on_tan_01_clicked();
    void on_sinh_clicked();
    void on_cosh_clicked();
    void on_tanh_clicked();
    void on_sinh_01_clicked();
    void on_cosh_01_clicked();
    void on_tanh_01_clicked();
    void on_Left_Pare_clicked();
    void on_Right_Pare_clicked();
    void on_Exp_clicked();
    void on_Mod_clicked();
    void on_dms_clicked();
    void on_deg_clicked();
    void on_F_E_clicked();
    void on_arrow_clicked();
    void on_arrow_2_clicked();
    void on_HYP_clicked();
    void on_pushButton_clicked();
    void on_HYP_2_clicked();
    void on_action_C_triggered();
    void toConn();
    void show_conn();
    void disconn();
    void show_help();
};

#endif // MAINWINDOW_H
