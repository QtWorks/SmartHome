#ifndef GARDENING_WIDGET_H
#define GARDENING_WIDGET_H

#include "scalable_widget.h"
#include "model/sprinkler.h"

class GardeningWidget : public ScalableWidget
{
    Q_OBJECT

    QPixmap m_pixmap;
    QColor m_color;

    /*
     * Washroom
     * Parent's Bedroom
     * Living Room
     * Bob's Bedroom
     * Kitchen
     * Hall
     * Study
     * Alice's Bedroom
     * */

    QSize m_icon_size{50, 50};

    QVector<QPoint> m_sprinkler_map{  QPoint( 12, 240),
                                      QPoint(140, 165),
                                      QPoint(365, 287),
                                     };


    Sprinkler& m_sprinkler = Singleton<Sprinkler>::instance();

    int m_index{0};

public:
    explicit GardeningWidget(QWidget* parent, QSize base_size, QPixmap pixmap);
    void setGlobalSprinklerValue(bool value);

protected:
    void paintEvent(QPaintEvent*);
    void mousePressEvent(QMouseEvent* event);
};

#endif


