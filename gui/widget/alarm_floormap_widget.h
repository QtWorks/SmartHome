#ifndef ALARM_FLOORMAP_WIDGET_H
#define ALARM_FLOORMAP_WIDGET_H

#include "floormap_widget.h"
#include "model/alarm.h"
#include <QTimer>

class AlarmFloormapWidget : public FloormapWidget
{
    Q_OBJECT

    QPixmap m_pixmap;
    QColor m_color;
    QTimer* m_blink_timer;
    bool m_toggled{true};

    QVector<QRect> m_icon_map{  QRect( 47, 392, 86, 8),
                                QRect(166, 392, 72, 8),
                                QRect(264, 392, 70, 8),
                                QRect(372, 392, 73, 8),
                                QRect(382, 142, 70, 8),
                                QRect(315, 142, 34, 8),
                                QRect(208, 119, 39, 8),
                                QRect(117, 119, 84, 8),
                                QRect(  3, 195, 8, 34),
                              };

    Alarm& m_alarm_state = Singleton<Alarm>::instance();

private slots:
    void toggleBlink();

public:
    explicit AlarmFloormapWidget(QWidget* parent, QSize base_size, QPixmap pixmap);

protected:
    void paintEvent(QPaintEvent*);
};

#endif


