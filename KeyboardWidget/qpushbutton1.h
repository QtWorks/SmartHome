#ifndef QPUSHBUTTON1_H
#define QPUSHBUTTON1_H

#include <QPushButton>

class QPushButton1 : public QPushButton
{
    Q_OBJECT

    static float moveFromEdge;
public:
    QPushButton1(const QString & text, QWidget * parent = 0);
    virtual ~QPushButton1();


    QRect clickableRect() const;

    static void setMoveFromEdge(float value);
    static float getMoveFromEdge();
};

#endif // QPUSHBUTTON1_H
