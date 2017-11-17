#include "alarm_floormap_widget.h"
#include <QPainter>
#include <QDebug>

void AlarmFloormapWidget::toggleBlink()
{
    m_toggled = !m_toggled;

    update();
}

AlarmFloormapWidget::AlarmFloormapWidget(QWidget* parent, QSize base_size, QPixmap pixmap) : FloormapWidget(parent, base_size, pixmap)
{
    m_blink_timer = new QTimer(this);
    m_blink_timer->start(1000);

    connect(m_blink_timer, SIGNAL(timeout()), this, SLOT(toggleBlink()));
}

void AlarmFloormapWidget::paintEvent(QPaintEvent*)
{
    FloormapWidget::paintEvent(nullptr);
    QPainter painter(this);
    painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
    painter.setRenderHint(QPainter::Antialiasing, true);

    for (int i = 0; i < m_icon_map.size(); i++)
    {
        QRect alarm_state(m_icon_map[i].topLeft().x() * m_width_scale, m_icon_map[i].topLeft().y() * m_height_scale, m_icon_map[i].width() * m_height_scale, m_icon_map[i].height() * m_height_scale);

        if((m_alarm_state.alarm(i)==true) && (m_toggled))
        {
        painter.fillRect(alarm_state, Qt::red);
        }
        else{
           painter.fillRect(alarm_state, Qt::darkGreen);
        }

    }
}
