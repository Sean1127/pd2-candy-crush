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
    switch (selected) {
    case false:
        switch (type) {
        case 1:
            switch (color) {
            case 0:
                button->setIcon(QPixmap(":/prefix1/Resource/Bonemeal.png"));
                break;
            case 1:
                button->setIcon(QPixmap(":/prefix1/Resource/Rose_Red.png"));
                break;
            case 2:
                button->setIcon(QPixmap(":/prefix1/Resource/Dandelion_Yellow.png"));
                break;
            case 3:
                button->setIcon(QPixmap(":/prefix1/Resource/Ink_Sack.png"));
                break;
            }
            break;
        case 2:
            switch (color) {
            case 0:
                button->setIcon(QPixmap(":/prefix1/Resource/BonemealLR.png"));
                break;
            case 1:
                button->setIcon(QPixmap(":/prefix1/Resource/Rose_RedLR.png"));
                break;
            case 2:
                button->setIcon(QPixmap(":/prefix1/Resource/Dandelion_YellowLR.png"));
                break;
            case 3:
                button->setIcon(QPixmap(":/prefix1/Resource/Ink_SackLR.png"));
                break;
            }
            break;
        case 3:
            switch (color) {
            case 0:
                button->setIcon(QPixmap(":/prefix1/Resource/BonemealUD.png"));
                break;
            case 1:
                button->setIcon(QPixmap(":/prefix1/Resource/Rose_RedUD.png"));
                break;
            case 2:
                button->setIcon(QPixmap(":/prefix1/Resource/Dandelion_YellowUD.png"));
                break;
            case 3:
                button->setIcon(QPixmap(":/prefix1/Resource/Ink_SackUD.png"));
                break;
            }
            break;
        case 4:
            switch (color) {
            case 0:
                button->setIcon(QPixmap(":/prefix1/Resource/WTNT.png"));
                break;
            case 1:
                button->setIcon(QPixmap(":/prefix1/Resource/RTNT.png"));
                break;
            case 2:
                button->setIcon(QPixmap(":/prefix1/Resource/YTNT.png"));
                break;
            case 3:
                button->setIcon(QPixmap(":/prefix1/Resource/BTNT.png"));
                break;
            }
            break;
        case 5:
            button->setIcon(QPixmap(":/prefix1/Resource/Eye_of_Ender.png"));
            break;
        }
        break;
    case true:
        switch (type) {
        case 1:
            switch (color) {
            case 0:
                button->setIcon(QPixmap(":/prefix1/Resource/Bonemeals.png"));
                break;
            case 1:
                button->setIcon(QPixmap(":/prefix1/Resource/Rose_Reds.png"));
                break;
            case 2:
                button->setIcon(QPixmap(":/prefix1/Resource/Dandelion_Yellows.png"));
                break;
            case 3:
                button->setIcon(QPixmap(":/prefix1/Resource/Ink_Sacks.png"));
                break;
            }
            break;
        case 2:
            switch (color) {
            case 0:
                button->setIcon(QPixmap(":/prefix1/Resource/BonemealLRs.png"));
                break;
            case 1:
                button->setIcon(QPixmap(":/prefix1/Resource/Rose_RedLRs.png"));
                break;
            case 2:
                button->setIcon(QPixmap(":/prefix1/Resource/Dandelion_YellowLRs.png"));
                break;
            case 3:
                button->setIcon(QPixmap(":/prefix1/Resource/Ink_SackLRs.png"));
                break;
            }
            break;
        case 3:
            switch (color) {
            case 0:
                button->setIcon(QPixmap(":/prefix1/Resource/BonemealUDs.png"));
                break;
            case 1:
                button->setIcon(QPixmap(":/prefix1/Resource/Rose_RedUDs.png"));
                break;
            case 2:
                button->setIcon(QPixmap(":/prefix1/Resource/Dandelion_YellowUDs.png"));
                break;
            case 3:
                button->setIcon(QPixmap(":/prefix1/Resource/Ink_SackUDs.png"));
                break;
            }
            break;
        case 4:
            switch (color) {
            case 0:
                button->setIcon(QPixmap(":/prefix1/Resource/WTNTs.png"));
                break;
            case 1:
                button->setIcon(QPixmap(":/prefix1/Resource/RTNTs.png"));
                break;
            case 2:
                button->setIcon(QPixmap(":/prefix1/Resource/YTNTs.png"));
                break;
            case 3:
                button->setIcon(QPixmap(":/prefix1/Resource/BTNTs.png"));
                break;
            }
            break;
        case 5:
            button->setIcon(QPixmap(":/prefix1/Resource/Eye_of_Enders.png"));
            break;
        }
    break;
    }
}

void Rock::act()
{
    emit signal(x, y);
}
