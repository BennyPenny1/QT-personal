#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>

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
    for (int i = equation.size(); i > 0; i--)
    {
        if (equation[i] == '.')
        {
            return;
        }
        else if (equation[i] == '+' || equation[i] == '-' || equation[i] == '*' || equation[i] == '/')
        {
            break;
        }
    }
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
    answer = "";
    back_log_lines = 0;
    back_log_vector.clear();
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
    if (equation.size() == 0)
    {
        input('-');
    }
    else
    {
        for (int i = equation.size() - 1; i > 0; i--)
        {
            if (equation[i] == '+' || equation[i] == '/' || equation[i] == '*')
            {
                equation.insert(i+1, 1, '-');
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
}


void MainWindow::on_btn_plus_clicked()
{
    if (equation.size() > 0)
    {
        if (equation.back() == '+' ||  equation.back() == '*' || equation.back() == '/')
        {
            equation.pop_back();
            input('+');
        }
        else if (equation.back() == '-')
        {
            if (equation.size() < 2)
            {
                return;
            }
            else if (equation[equation.size() - 2] == '-' || equation[equation.size() - 2] == '+' ||  equation[equation.size() - 2] == '*' || equation[equation.size() - 2] == '/')
            {
                equation[equation.size() - 2] = '+';
                ui->display_text->setHtml(back_log + QString::fromStdString(equation));
            }
            else
            {
                equation.pop_back();
                input('+');
            }
        }
        else if (equation.back() == '.')
        {
            if (equation.size() < 2)
            {
                return;
            }
            else if (equation[equation.size() - 2] == '+' || equation[equation.size() - 2] == '*' || equation[equation.size() - 2] == '/')
            {
                equation[equation.size() - 2] = '+';
                ui->display_text->setHtml(back_log + QString::fromStdString(equation));
            }
            else if (equation[equation.size() - 2] == '-')
            {
                if (equation[equation.size() - 3] == '+' || equation[equation.size() - 3] == '-' || equation[equation.size() - 3] == '*' || equation[equation.size() - 3] == '/')
                {
                    equation[equation.size() - 3] = '+';
                    ui->display_text->setHtml(back_log + QString::fromStdString(equation));
                }
            }
        }
        else
        {
            input('+');
        }
    }
    else
    {
        equation += answer;
        input('+');
    }
}

void MainWindow::on_btn_minus_clicked()
{
    if (equation.size() > 0)
    {
        if (equation.back() == '+' ||  equation.back() == '*' || equation.back() == '/')
        {
            equation.pop_back();
            input('-');
        }


        else if (equation.back() == '-')
        {
            if (equation.size() < 2)
            {
                return;
            }
            else if (equation[equation.size() - 2] == '-' || equation[equation.size() - 2] == '+' ||  equation[equation.size() - 2] == '*' || equation[equation.size() - 2] == '/')
            {
                equation[equation.size() - 2] = '-';
                ui->display_text->setHtml(back_log + QString::fromStdString(equation));
            }
            else
            {
                equation.pop_back();
                input('-');
            }
        }
        else if (equation.back() == '.')
        {
            if (equation.size() < 2)
            {
                return;
            }
            else if (equation[equation.size() - 2] == '+' || equation[equation.size() - 2] == '*' || equation[equation.size() - 2] == '/')
            {
                equation[equation.size() - 2] = '+';
                ui->display_text->setHtml(back_log + QString::fromStdString(equation));
            }
            else if (equation[equation.size() - 2] == '-')
            {
                if (equation[equation.size() - 3] == '+' || equation[equation.size() - 3] == '-' || equation[equation.size() - 3] == '*' || equation[equation.size() - 3] == '/')
                {
                    equation[equation.size() - 3] = '+';
                    ui->display_text->setHtml(back_log + QString::fromStdString(equation));
                }
            }
        }
        else
        {
            input('-');
        }
    }
    else
    {
        equation += answer;
        input('-');
    }
}

void MainWindow::on_btn_mult_clicked()
{
    if (equation.size() > 0)
    {
        if (equation.back() == '+' ||  equation.back() == '*' || equation.back() == '/')
        {
            equation.erase(equation.size() - 1, 1);
            input('*');
        }
        else if (equation.back() == '-')
        {
            if (equation.size() < 2)
            {
                return;
            }
            else if (equation[equation.size() - 2] == '-' || equation[equation.size() - 2] == '+' ||  equation[equation.size() - 2] == '*' || equation[equation.size() - 2] == '/')
            {
                equation[equation.size() - 2] = '*';
                ui->display_text->setHtml(back_log + QString::fromStdString(equation));
            }
            else
            {
                equation.pop_back();
                input('*');
            }
        }
        else if (equation.back() == '.')
        {
            if (equation.size() < 2)
            {
                return;
            }
            else if (equation[equation.size() - 2] == '+' || equation[equation.size() - 2] == '*' || equation[equation.size() - 2] == '/')
            {
                equation[equation.size() - 2] = '+';
                ui->display_text->setHtml(back_log + QString::fromStdString(equation));
            }
            else if (equation[equation.size() - 2] == '-')
            {
                if (equation[equation.size() - 3] == '+' || equation[equation.size() - 3] == '-' || equation[equation.size() - 3] == '*' || equation[equation.size() - 3] == '/')
                {
                    equation[equation.size() - 3] = '+';
                    ui->display_text->setHtml(back_log + QString::fromStdString(equation));
                }
            }
        }
        else
        {
            input('*');
        }
    }
    else
    {
        equation += answer;
        input('*');
    }
}

void MainWindow::on_btn_div_clicked()
{
    if (equation.size() > 0)
    {
        if (equation.back() == '+' ||  equation.back() == '*' || equation.back() == '/')
        {
            equation.erase(equation.size() - 1, 1);
            input('/');
        }
        else if (equation.back() == '-')
        {
            if (equation.size() < 2)
            {
                return;
            }
            else if (equation[equation.size() - 2] == '-' || equation[equation.size() - 2] == '+' ||  equation[equation.size() - 2] == '*' || equation[equation.size() - 2] == '/')
            {
                equation[equation.size() - 2] = '/';
                ui->display_text->setHtml(back_log + QString::fromStdString(equation));
            }
            else
            {
                equation.pop_back();
                input('/');
            }
        }
        else if (equation.back() == '.')
        {
            if (equation.size() < 2)
            {
                return;
            }
            else if (equation[equation.size() - 2] == '+' || equation[equation.size() - 2] == '*' || equation[equation.size() - 2] == '/')
            {
                equation[equation.size() - 2] = '+';
                ui->display_text->setHtml(back_log + QString::fromStdString(equation));
            }
            else if (equation[equation.size() - 2] == '-')
            {
                if (equation[equation.size() - 3] == '+' || equation[equation.size() - 3] == '-' || equation[equation.size() - 3] == '*' || equation[equation.size() - 3] == '/')
                {
                    equation[equation.size() - 3] = '+';
                    ui->display_text->setHtml(back_log + QString::fromStdString(equation));
                }
            }
        }
        else
        {
            input('/');
        }
    }
    else
    {
        equation += answer;
        input('/');
    }
}



void MainWindow::on_btn_equal_clicked()
{
    if (equation.size() == 0)
    {
        equation += answer;
        ui->display_text->setHtml(back_log + QString::fromStdString(answer));
    }
    else if (equation.back() == '+'|| equation.back() == '-' || equation.back() == '*' || equation.back() == '/')
    {
        equation += answer;
        ui->display_text->setHtml(back_log + QString::fromStdString(equation));
        return;
    }
    else if (equation.back() == '.')
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
            else if (equation[i] == '+'|| equation[i] == '*' || equation[i] == '/')
            {
                numbers.push_back(std::stod(chunk));
                operators.push_back(equation[i]);
                /*std::cout << equation[i] << "\n";
                std::cout << chunk << "\n";*/
                chunk.clear();
            }
            else
            {
                chunk += equation[i];
            }
        }
        numbers.push_back(std::stod(chunk));

        /*std::cout << "numbers list: ";
        for (int i = 0; i < numbers.size(); i++){
            std::cout << i << ": " << numbers[i] << ", ";
        }
        std::cout << "\n";*/

        int it_adjst = 0; // iterator adjustment: when replacing numbers, throughs off iterator
        for (int i = 0; i < operators.size(); i++)
        {
            if (operators[i] == '/')
            {
                // std::cout << numbers[i] << operators[i] << numbers[i+1] << "= ";
                double temp_num = numbers[i - it_adjst] / numbers[i+1 - it_adjst];
                // std::cout << temp_num <<"\n";
                numbers.erase(numbers.begin() + i - it_adjst);
                numbers.erase(numbers.begin() + i - it_adjst);
                numbers.insert(numbers.begin() + i - it_adjst, temp_num);
                it_adjst++;
            }
            else if (operators[i] == '*')
            {
                // std::cout << numbers[i] << operators[i] << numbers[i+1] << "= ";
                double temp_num = numbers[i - it_adjst] * numbers[i+1 - it_adjst];
                // std::cout << temp_num <<"\n";
                numbers.erase(numbers.begin() + i - it_adjst);
                numbers.erase(numbers.begin() + i - it_adjst);
                numbers.insert(numbers.begin() + i - it_adjst, temp_num);
                it_adjst++;
            }
        }

        /*std::cout << "numbers after mult/div: ";
        for (int i = 0; i < numbers.size(); i++){
            std::cout << i << ": " << numbers[i] << ", ";
        }
        std::cout << "\n";*/

        for (int i = 0; i < operators.size(); i++)
        {
            if (operators[i] == '+')
            {
                // std::cout << numbers[0] << operators[i] << numbers[1] << "\n";
                double temp_num = numbers[0] + numbers[1];
                numbers.erase(numbers.begin());
                numbers.erase(numbers.begin());
                numbers.insert(numbers.begin(), temp_num);
            }
            else if (operators[i] == '-')
            {
                // std::cout << numbers[0] << operators[i] << numbers[1] << "\n";
                double temp_num = numbers[0] - numbers[1];
                numbers.erase(numbers.begin());
                numbers.erase(numbers.begin());
                numbers.insert(numbers.begin(), temp_num);
            }
        }
        QString clean = QString::number(numbers[0], 'g', 15);
        answer = clean.toStdString();
        back_log_vector.push_back(QString::fromStdString(equation) + "<div align='right'>" + QString::fromStdString(answer) + "</div><div align='left'></div>");
        back_log_lines += 1;
        qDebug() << back_log_lines << "\n";
        if (back_log_lines > 2)
        {
            back_log_vector.erase(back_log_vector.begin());
            back_log.clear();
            for (int i = 0; i < 2; i++)
            {
                back_log += back_log_vector[i];
            }
            back_log_lines -= 1;
        }
        else
        {
            back_log += QString::fromStdString(equation) + "<div align='right'>" + QString::fromStdString(answer) + "</div><div align='left'></div>";
        }
        ui->display_text->setHtml(back_log);
        equation.clear();
    }
}
