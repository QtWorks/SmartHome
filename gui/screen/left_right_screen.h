#ifndef LEFT_RIGHT_SCREEN_H
#define LEFT_RIGHT_SCREEN_H

#include "left_screen.h"

class LeftRightScreen : public LeftScreen
{
    Q_OBJECT

protected:
    PlaceholderWidget* m_right_widget;

    QSize m_right_widget_size{230, 440};
    QPoint m_right_widget_pos{500, 0};

    explicit LeftRightScreen(QWidget* parent);
    void setupLayout();
};

#endif
