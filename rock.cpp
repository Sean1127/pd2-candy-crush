#include "rock.h"

Rock::Rock(QWidget *parent, int a, int b, int c, int d):
    QObject(parent), x(a), y(b), color(c), type(d)
{
    button = new QPushButton(parent);
    button->setGeometry(x*150, y*150, 150, 150);
    connect(button,SIGNAL(clicked(bool)),this,SLOT(act()));
}

void Rock::act()
{
    emit selected(x, y);
}
