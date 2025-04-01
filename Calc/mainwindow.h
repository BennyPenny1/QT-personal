#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btn_C_clicked();

    void on_btn_CE_clicked();

    void on_btn_back_clicked();

    void on_btn_dot_clicked();

    void on_btn_neg_clicked();

    void on_btn_plus_clicked();

    void on_btn_minus_clicked();

    void on_btn_mult_clicked();

    void on_btn_div_clicked();

    void on_btn_equal_clicked();

    void on_btn_0_clicked();

    void on_btn_1_clicked();

    void on_btn_2_clicked();

    void on_btn_3_clicked();

    void on_btn_4_clicked();

    void on_btn_5_clicked();

    void on_btn_6_clicked();

    void on_btn_7_clicked();

    void on_btn_8_clicked();

    void on_btn_9_clicked();

    void input(char c);

private:
    Ui::MainWindow *ui;

    std::string equation;
    std::vector<QString> back_log_vector;
    int back_log_lines = 0;
    std::string answer;
    QString back_log;
};
#endif // MAINWINDOW_H
