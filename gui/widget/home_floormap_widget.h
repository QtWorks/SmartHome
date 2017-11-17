#ifndef HOME_FLOORMAP_WIDGET_H
#define HOME_FLOORMAP_WIDGET_H

#include "alarm_floormap_widget.h"
#include "thermometer_overlay_widget.h"
#include "model/temperature.h"

class HomeFloormapWidget : public AlarmFloormapWidget
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
    QVector<QPoint> m_icon_map{ QPoint(35, 195),
                                QPoint(70, 290),
                                QPoint(182, 262),
                                QPoint(282, 298),
                                QPoint(292, 152),
                                QPoint(324, 237),
                                QPoint(405, 152),
                                QPoint(378, 310)
                              };
    QSize m_icon_size{30, 30};

    Temperature& m_temperature = Singleton<Temperature>::instance();

public:
    explicit HomeFloormapWidget(QWidget* parent, QSize base_size, QPixmap pixmap);

protected:
    void paintEvent(QPaintEvent*);
};

#endif


