#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <ctime>
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
    void arrange();
    bool check();
    void clean();
    void drop();
    void fill();

public slots:
    void button_clicked(int x, int y);
private:
    Ui::MainWindow *ui;
    int score;
    int star;
    Rock *board[][];
};

#endif // MAINWINDOW_H
