#ifndef LIGHTING_FLOORMAP_WIDGET_H
#define LIGHTING_FLOORMAP_WIDGET_H

#include "floormap_widget.h"
#include "lighting_overlay_widget.h"
#include "model/lighting.h"

class LightingFloormapWidget : public FloormapWidget
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

    LightingOverlayWidget* m_overlay{nullptr};

    Lighting& m_lighting = Singleton<Lighting>::instance();


    QVector<int> m_value_map{   20,
                                20,
                                20,
                                20,
                                20,
                                20,
                                20,
                                20
                              };

    int m_index{0};

private slots:
    void ok();
    void cancel();

public:
    explicit LightingFloormapWidget(QWidget* parent, QSize base_size, QPixmap pixmap);

    void setGlobalValue(int value);

protected:
    void paintEvent(QPaintEvent*);
    void mousePressEvent(QMouseEvent* event);
};

#endif


