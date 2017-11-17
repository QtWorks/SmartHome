#include "qpushbutton1.h"
#include <QDebug>

float QPushButton1::moveFromEdge = 5;

QPushButton1::QPushButton1(const QString & text, QWidget * parent) : QPushButton(text, parent)
{

}
QPushButton1::~QPushButton1(){}

QRect QPushButton1::clickableRect() const
{
    float shrinkingFactor = moveFromEdge/100;
    QRect result = rect();

    result.adjust((int)((float)this->width()*shrinkingFactor),
                  (int)((float)this->height()*shrinkingFactor),
                  (int)((float)this->width()*( - shrinkingFactor)),
                  (int)((float)this->height()*( - shrinkingFactor)));
    return result;
}

void QPushButton1::setMoveFromEdge(float value)
{
    moveFromEdge = value;
}

float QPushButton1::getMoveFromEdge()
{
    return moveFromEdge;
}



