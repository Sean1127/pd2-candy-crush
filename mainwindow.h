#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <ctime>
#include <cmath>
#include <cstring>
#include "rock.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void game();
    bool end();
    void arrange(int x, int y);
    bool neighbor(int x, int y);
    Rock *genRock(int x, int y);

public slots:
    void button_clicked(int x, int y);
signals:
    quit(int star, int score);
private:
    Ui::MainWindow *ui;
    int score;
    int star;
    int step;
    int movement;
    Rock *board[10][10];
    int prex, prey;
};

#endif // MAINWINDOW_H
