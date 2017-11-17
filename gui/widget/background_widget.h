#ifndef BACKGROUND_WIDGET_H
#define BACKGROUND_WIDGET_H

#include "scalable_widget.h"

class BackgroundWidget : public ScalableWidget
{
    Q_OBJECT

    QColor m_background_color;
    int m_border_roudness{20};

public:
    explicit BackgroundWidget(QWidget* parent, QSize base_size, QColor background_color);

    void setBorderRoundess(int border_roundess);

protected:
    void paintEvent(QPaintEvent*);
};
#endif
