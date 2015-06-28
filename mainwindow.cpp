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
            connect(board[j][i],SIGNAL(signal(int,int)),this,SLOT(button_clicked(int, int)));
        }
    }
    prex = 1;
    prey = 1;
    step = 15;
    movement++;
}

MainWindow::~MainWindow()
{
    emit quit(star, score);
    delete ui;
}

void MainWindow::game()
{
    score = 0;
    star = 0;
    //arrange(prex, prey);
}

bool MainWindow::end()
{
    return false;
}

void MainWindow::arrange(int x, int y)
{
    int i, j, N;
    //check type 5 choco
    //horizontal
    for (i = 0; i < 6; i++)
    {
        for (j = 0; j < 10; j++)
        {
            N = board[j][i]->color;
            if (board[j][i + 1]->color == N && board[j][i + 2]->color == N && board[j][i + 3]->color == N && board[j][i + 4]->color == N)
            {
                board[j][i]->color = -1;
                board[j][i + 1]->color = -1;
                board[j][i + 2]->type = 5;
                board[j][i + 3]->color = -1;
                board[j][i + 4]->color = -1;
                movement++;
            }
        }
    }
    //vertical
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 6; j++)
        {
            N = board[j][i]->color;
            if (board[j + 1][i]->color == N && board[j + 2][i]->color == N && board[j + 3][i]->color == N && board[j + 4][i]->color == N)
            {
                board[j][i]->color = -1;
                board[j + 1][i]->color = -1;
                board[j + 2][i]->type = 5;
                board[j + 3][i]->color = -1;
                board[j + 4][i]->color = -1;
                movement++;
            }
        }
    }
/*    //check type 4 bomb
    //L1
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            N = board[j][i]->color;
            if (board[j + 1][i]->color == N && board[j + 2][i]->color == N && board[j + 2][i + 1]->color == N && board[j + 2][i + 2]->color == N)
            {
                board[j][i]->color = -1;
                board[j + 1][i]->color = -1;
                board[j + 2][i]->type = 4;
                board[j + 2][i + 1]->color = -1;
                board[j + 2][i + 1]->color = -1;
                movement++;
            }
        }
    }
    //L2
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            N = board[j][i]->color;
            if (board[j + 1][i]->color == N && board[j + 2][i]->color == N && board[j][i + 1]->color == N && board[j][i + 2]->color == N)
            {
                board[j][i]->type = 4;
                board[j + 1][i]->color = -1;
                board[j + 2][i]->color = -1;
                board[j][i + 1]->color = -1;
                board[j][i + 1]->color = -1;
                movement++;
            }
        }
    }
    //L3
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            N = board[j][i]->color;
            if (board[j][i + 1]->color == N && board[j][i + 2]->color == N && board[j + 1][i + 2]->color == N && board[j + 2][i + 2]->color == N)
            {
                board[j][i]->color = -1;
                board[j][i + 1]->color = -1;
                board[j][i + 2]->type = 4;
                board[j + 1][i + 2]->color = -1;
                board[j + 2][i + 2]->color = -1;
                movement++;
            }
        }
    }
    //L4
    for (i = 2; i < 10; i++)
    {
        for (j = 0; j < 8; j++)
        {
            N = board[j][i]->color;
            if (board[j + 1][i]->color == N && board[j + 2][i]->color == N && board[j + 2][i - 1]->color == N && board[j + 2][i - 2]->color == N)
            {
                board[j][i]->color = -1;
                board[j + 1][i]->color = -1;
                board[j + 2][i]->type = 4;
                board[j + 2][i - 1]->color = -1;
                board[j + 2][i - 2]->color = -1;
                movement++;
            }
        }
    }
    //check type 3 vertical liner
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 7; j++)
        {
            N = board[j][i]->color;
            if (board[j + 1][i]->color == N && board[j + 2][i]->color == N && board[j + 3][i]->color == N)
            {
                board[j][i]->color = -1;
                board[j + 1][i]->color = -1;
                board[j + 2][i]->color = -1;
                board[j + 3][i]->color = -1;
                board[y][x]->type = 3;
                movement++;
            }
        }
    }
    //check type 2 horizontal liner
    for (i = 0; i < 7; i++)
    {
        for (j = 0; j < 10; j++)
        {
            N = board[j][i]->color;
            if (board[j][i + 1]->color == N && board[j][i + 2]->color == N && board[j][i + 3]->color == N)
            {
                board[j][i]->color = -1;
                board[j][i + 1]->color = -1;
                board[j][i + 2]->color = -1;
                board[j][i + 3]->color = -1;
                board[y][x]->type = 2;
                movement++;
            }
        }
    }
    //check type 1 normal
    //horizontal
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 10; j++)
        {
            N = board[j][i]->color;
            if (board[j][i + 1]->color == N && board[j][i + 2]->color == N)
            {
                board[j][i]->color = -1;
                board[j][i + 1]->color = -1;
                board[j][i + 2]->color = -1;
                movement++;
            }
        }
    }
    //vertical
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 8; j++)
        {
            N = board[j][i]->color;
            if (board[j + 1][i]->color == N && board[j + 2][i]->color == N)
            {
                board[j][i]->color = -1;
                board[j + 1][i]->color = -1;
                board[j + 2][i]->color = -1;
                movement++;
            }
        }
    }*/
    //clean
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            if (board[j][i]->color == -1)
            switch (board[j][i]->type) {
            case 4:
                for (int t = x - 1; t < x + 2; t++)
                {
                    for (int s = y - 1; s < y + 2; s++)
                    {
                        board[s][t]->color = -1;
                    }
                }
                break;
            case 3:
                for (int t = 0; t < 10; t++)
                {
                    board[t][i]->color = -1;
                }
                break;
            case 2:
                for (int t = 0; t < 10; t++)
                {
                    board[j][t]->color = -1;
                }
                break;
            default:
                break;
            }
        }
    }
    //drop
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 9; j++)
        {
            if (board[j + 1][i]->color == -1)
            {
                board[j + 1][i] = board[j][i];
                board[j][i]->color = -1;
            }
        }
    }
    //fill
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            if (board[j][i]->color == -1)
            {
                board[j][i]->type = 1;
                board[j][i]->color = rand()%4;
            }
        }
    }
    if (movement != 0)
        arrange(x, y);
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
    //three case: next to it, on it, or the other
    movement = 0;
    if (x == prex && y == prey)
    {
        if (board[prey][prex]->selected == false)
        {
            board[y][x]->selected = true;
        } else if (board[prey][prex]->selected == true) {
            board[y][x]->selected = false;
        }
    } else if (neighbor(x, y) == true && board[prey][prex]->selected == true) {
        int temp = board[y][x]->color;
        board[y][x]->color = board[prey][prex]->color;
        board[prey][prex]->color = temp;
        board[prey][prex]->selected = false;
        arrange(x, y);
        if (movement == 0)
        {
            temp = board[y][x]->color;
            board[y][x]->color = board[prey][prex]->color;
            board[prey][prex]->color = temp;
        } else {
            step--;
        }
    } else {
        board[prey][prex]->selected = false;
        board[y][x]->selected = true;
    }
    //display and reset previous value
    board[y][x]->paint();
    board[prey][prex]->paint();
    prex = x;
    prey = y;
    //end condition
    if (end() == true)
    {
        emit quit(star, score);
        this->close();
    }
}
