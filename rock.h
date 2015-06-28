#ifndef ROCK_H
#define ROCK_H

#include <QObject>
#include <QPushButton>
#include <iostream>
#include <cstdlib>
class Rock : public QObject{
    Q_OBJECT

public:
    explicit Rock(QWidget *parent, int a, int b, int c, int d = 0);
    ~Rock();
    QPushButton *button;
    const int x, y;
    int color;
    int type;
    void paint();
public slots:
    void act();
signals:
    void selected(int x, int y);
};

#endif // ROCK_H

