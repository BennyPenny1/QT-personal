#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::input(char c)
{
    equation += c;
    ui->display_text->setHtml(back_log + QString::fromStdString(equation));
}

void MainWindow::on_btn_0_clicked()
{
    input('0');
}
void MainWindow::on_btn_1_clicked()
{
    input('1');
}
void MainWindow::on_btn_2_clicked()
{
    input('2');
}
void MainWindow::on_btn_3_clicked()
{
   input('3');
}
void MainWindow::on_btn_4_clicked()
{
    input('4');
}
void MainWindow::on_btn_5_clicked()
{
    input('5');
}
void MainWindow::on_btn_6_clicked()
{
    input('6');
}
void MainWindow::on_btn_7_clicked()
{
    input('7');
}
void MainWindow::on_btn_8_clicked()
{
    input('8');
}
void MainWindow::on_btn_9_clicked()
{
    input('9');
}
void MainWindow::on_btn_dot_clicked()
{
    input('.');
}


void MainWindow::on_btn_C_clicked()
{
    equation = "";
    ui->display_text->setHtml(back_log + QString::fromStdString(equation));
}

void MainWindow::on_btn_CE_clicked()
{
    back_log.clear();
    equation = "";
    ui->display_text->setHtml(back_log + QString::fromStdString(equation));
}


void MainWindow::on_btn_back_clicked()
{
    if (equation.size() > 0)
    {
        equation.erase(equation.size() - 1, 1);
        ui->display_text->setHtml(back_log + QString::fromStdString(equation));
    }
}


void MainWindow::on_btn_neg_clicked()
{
    for (int i = equation.size() - 1; i >= 0; i--)
    {
        if (equation[i] == '+' || equation[i] == '/' || equation[i] == '*')
        {
            equation.insert(i, 1, '-');
            break;
        }
        else if (equation[i] == '-')
        {
            if (i == 0)
            {
                equation.erase(i, 1);
                break;
            }
            if (equation[i - 1] == '-' || equation[i] == '+' || equation[i] == '/' || equation[i] == '*')
            {
                equation.erase(i, 1);
                break;
            }
            else
            {
                equation.insert(i, 1, '-');
                break;
            }
        }
        if (i == 0)
        {
            equation.insert(i, 1, '-');
            break;
        }

    }
    ui->display_text->setHtml(back_log + QString::fromStdString(equation));

}


void MainWindow::on_btn_plus_clicked()
{
    if (equation.size() > 0)
    {
        if (equation[equation.size() - 1] == '+' || equation[equation.size() - 1] == '-' || equation[equation.size() - 1] == '*' || equation[equation.size() - 1] == '/')
        {
            equation.erase(equation.size() - 1, 1);
        }
        input('+');
    }
}

void MainWindow::on_btn_minus_clicked()
{
    if (equation.size() > 0)
    {
        if (equation[equation.size() - 1] == '+' || equation[equation.size() - 1] == '-' || equation[equation.size() - 1] == '*' || equation[equation.size() - 1] == '/')
        {
            equation.erase(equation.size() - 1, 1);
        }
        input('-');
    }
}

void MainWindow::on_btn_mult_clicked()
{
    if (equation.size() > 0)
    {
        if (equation[equation.size() - 1] == '+' || equation[equation.size() - 1] == '-' || equation[equation.size() - 1] == '*' || equation[equation.size() - 1] == '/')
        {
            equation.erase(equation.size() - 1, 1);
        }
        input('*');
    }
}

void MainWindow::on_btn_div_clicked()
{
    if (equation.size() > 0)
    {
        if (equation[equation.size() - 1] == '+' || equation[equation.size() - 1] == '-' || equation[equation.size() - 1] == '*' || equation[equation.size() - 1] == '/')
        {
            equation.erase(equation.size() - 1, 1);
        }
        input('/');
    }
}



void MainWindow::on_btn_equal_clicked()
{
    if (equation.size() == 0)
    {
        equation += answer;
    }
    else if (equation[equation.size() - 1] == '+'|| equation[equation.size() - 1] == '-' || equation[equation.size() - 1] == '*' || equation[equation.size() - 1] == '/')
    {
        return;
    }
    else
    {
        std::string chunk;
        std::vector<double> numbers;
        std::vector<char> operators;
        for (int i = 0; i < equation.size(); i++)
        {
            if (equation[i] == '-')
            {
                if (chunk.size() == 0)
                {
                    chunk += equation[i];
                }
                else
                {
                    numbers.push_back(std::stod(chunk));
                    operators.push_back('-');
                    chunk.clear();
                }
            }
            else if (equation[equation.size() - 1] == '+'|| equation[equation.size() - 1] == '*' || equation[equation.size() - 1] == '/')
            {
                numbers.push_back(std::stod(chunk));
                operators.push_back(equation[i]);
                chunk.clear();
            }
            else
            {
                chunk += equation[i];
            }
        }

        for (int i = 0; i < operators.size(); i++)
        {
            if (operators[i] == '/')
            {
                double temp_num = numbers[i] / numbers[i+1];
                numbers.erase(numbers.begin() + i);
                numbers.erase(numbers.begin() + i);
                numbers.insert(numbers.begin() + i, temp_num);
            }
            else if (operators[i] == '*')
            {
                double temp_num = numbers[i] * numbers[i+1];
                numbers.erase(numbers.begin() + i);
                numbers.erase(numbers.begin() + i);
                numbers.insert(numbers.begin() + i, temp_num);
            }
        }

        for (int i = 0; i < operators.size(); i++)
        {
            if (operators[i] == '+')
            {
                double temp_num = numbers[0] + numbers[1];
                numbers.erase(numbers.begin());
                numbers.erase(numbers.begin());
                numbers.insert(numbers.begin(), temp_num);
            }
            else if (operators[i] == '-')
            {
                double temp_num = numbers[0] - numbers[1];
                numbers.erase(numbers.begin());
                numbers.erase(numbers.begin());
                numbers.insert(numbers.begin(), temp_num);
            }
        }
        answer = std::to_string(numbers[0]);
        back_log += QString::fromStdString(equation) + "<br>";
        QString html = back_log + "<div align='right'>" + QString::fromStdString(answer) + "</div>";
        ui->display_text->setHtml(html);
    }
}
