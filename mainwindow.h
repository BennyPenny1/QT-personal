#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void on_btn_clear_clicked();

    void on_btn_0_clicked();

    void on_btn_1_clicked();

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

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
