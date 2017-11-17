#ifndef TEMPERATURE_FLOORMAP_WIDGET_H
#define TEMPERATURE_FLOORMAP_WIDGET_H

#include "floormap_widget.h"
#include "thermometer_overlay_widget.h"
#include "model/temperature.h"

class TemperatureFloormapWidget : public FloormapWidget
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

    QVector<QPoint> m_ventilation_map{  QPoint(182, 210),
                                        QPoint(400, 239),
                                     };

    ThermometerOverlayWidget* m_overlay{nullptr};

    Temperature& m_temperature = Singleton<Temperature>::instance();

    int m_index{0};

private slots:
    void ok();
    void cancel();

public:
    explicit TemperatureFloormapWidget(QWidget* parent, QSize base_size, QPixmap pixmap);

    void setGlobalValue(qreal value);
    void setGlobalVentilatorValue(bool value);

protected:
    void paintEvent(QPaintEvent*);
    void mousePressEvent(QMouseEvent* event);
};

#endif


