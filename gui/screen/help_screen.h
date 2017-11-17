#ifndef HELP_SCREEN_H
#define HELP_SCREEN_H

#include "gui/widget/scalable_widget.h"

class HelpScreen : public ScalableWidget
{
    Q_OBJECT

    qreal m_scale{1.0};
    qreal m_width_scale{1.0};
    qreal m_height_scale{1.0};
    int m_border_roudness{10};

public:
    explicit HelpScreen(QWidget* parent);
    void paintEvent(QPaintEvent*);
};


#endif // HELP_SCREEN_H
