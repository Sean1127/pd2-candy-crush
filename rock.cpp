#include "rock.h"

Rock::Rock(QWidget *parent, int a, int b, int c, int d):
    QObject(parent), x(a), y(b), color(c), type(d)
{
    button = new QPushButton(parent);
    button->setGeometry(x*50, y*50, 50, 50);
    connect(button,SIGNAL(clicked()),this,SLOT(act()));
}

Rock::~Rock()
{

}

void Rock::paint()
{
    button->setIconSize(QSize(50, 50));
    switch (type) {
    case 0:
        button->setIcon(QPixmap(""));
        break;
    case 1:
        switch (color) {
        case 1:
            button->setIcon(QPixmap(":/prefix1/Resource/Bonemeal.png"));
            break;
        case 2:
            button->setIcon(QPixmap(":/prefix1/Resource/Rose_Red.png"));
            break;
        case 3:
            button->setIcon(QPixmap(":/prefix1/Resource/Dandelion_Yellow.png"));
            break;
        case 0:
            button->setIcon(QPixmap(":/prefix1/Resource/Ink_Sack.png"));
            break;
        }
        break;
    case 2:
        switch (color) {
        case 1:
            button->setIcon(QPixmap(":/prefix1/Resource/Bonemeals.png"));
            break;
        case 2:
            button->setIcon(QPixmap(":/prefix1/Resource/Rose_Reds.png"));
            break;
        case 3:
            button->setIcon(QPixmap(":/prefix1/Resource/Dandelion_Yellows.png"));
            break;
        case 0:
            button->setIcon(QPixmap(":/prefix1/Resource/Ink_Sacks.png"));
            break;
        }
        break;
    case 3:
        switch (color) {
        case 1:

            break;
        case 2:

            break;
        case 3:

            break;
        case 0:

            break;
        }
        break;
    case 4:
        switch (color) {
        case 1:

            break;
        case 2:

            break;
        case 3:

            break;
        case 0:

            break;
        }
        break;
    case 5:

        break;
    }

}

void Rock::act()
{
    emit selected(x, y);
}
