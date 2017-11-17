#ifndef FLOORMAP_WIDGET_H
#define FLOORMAP_WIDGET_H

#include "scalable_widget.h"

class FloormapWidget : public ScalableWidget
{
    Q_OBJECT

    QPixmap m_pixmap;

public:
    explicit FloormapWidget(QWidget* parent, QSize base_size, QPixmap pixmap);

protected:
    void paintEvent(QPaintEvent*);

};

#endif


