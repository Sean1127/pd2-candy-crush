#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::game()
{
    score = 0;
    star = 0;
    int i, j, color;
    //create 100 rock
    srand(time(NULL));
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            color = rand()%4;
            board[j][i] = new Rock(this, i, j, color);
        }
    }
    arrange();
}

void MainWindow::arrange()
{
    check();
    clean();
    drop();
    fill();
}

bool MainWindow::check()
{

}

void MainWindow::clean()
{

}

void MainWindow::drop()
{

}

void MainWindow::fill()
{

}
