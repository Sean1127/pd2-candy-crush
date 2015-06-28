#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    int i, j;
    //create 100 rock
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            board[j][i] = genRock(i, j);
            board[j][i]->paint();
            connect(board[j][i],SIGNAL(selected(int, int)),this,SLOT(button_clicked(int, int)));
        }
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::game()
{
    score = 0;
    star = 0;
    //arrange();
}

void MainWindow::arrange()
{
    int i, j;
    //check, clean
    //drop
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 9; j++)
        {
            if (board[j + 1][i]->type == 0)
            {
                board[j + 1][i] = board[j][i];
                board[j][i]->type = 0;
            }
        }
    }
    //fill
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            if (board[j][i]->type == 0)
            {
                board[j][i]->type = 1;
                board[j][i]->color = rand()%4;
            }
        }
    }
}

bool MainWindow::neighbor(int x, int y)
{
    if (sqrt(pow((x - prex), 2) + pow((y - prey), 2)) == 1)
    {
        return true;
    } else {
        return false;
    }
}

Rock *MainWindow::genRock(int x, int y)
{
    int color = rand()%4;
    Rock *temp;
    temp = new Rock(this, x, y, color, 1);
    return temp;

}

void MainWindow::button_clicked(int x, int y)
{
    if (x == prex && y == prey)
    {
        if (board[prey][prex]->type == 1)
        {
            board[y][x]->type = 2;
        } else if (board[prey][prex]->type == 2) {
            board[y][x]->type = 1;
        }
    } else if (neighbor(x, y) == true && board[prey][prex]->type == 2) {
        int temp = board[y][x]->color;
        board[y][x]->color = board[prey][prex]->color;
        board[prey][prex]->color = temp;
        board[prey][prex]->type = 1;
    } else {
        board[prey][prex]->type = 1;
        board[y][x]->type = 2;
    }
    board[y][x]->paint();
    board[prey][prex]->paint();
    prex = x;
    prey = y;
}
