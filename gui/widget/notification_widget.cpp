#include "notification_widget.h"
#include <QPainter>
#include <QMouseEvent>
#include <QPolygonF>
#include <QDebug>

void NotificationWidget::updateNotificationInfo()
{
    int count = m_notification_state.count();

    if (count == 0)
    {
        m_notificiation_info->setIcon(m_icon[4]);
        m_notificiation_info->setDateTime("");
        m_notificiation_info->setInformation("No notifications \n to display");
        m_notificiation_info->setSevere(false);
    }
    else
    {
        auto notification = m_notification_state.get(m_current);

        m_notificiation_info->setIcon(m_icon[notification.level]);
        m_notificiation_info->setDateTime(notification.time);
        m_notificiation_info->setInformation(notification.text);
        bool severe = notification.level >= 2;
        m_notificiation_info->setSevere(severe);
    }

    update();
}

void NotificationWidget::notificationUpdate()
{
    m_current = 0;
    updateNotificationInfo();
}

void NotificationWidget::setBorderRoundess(int border_roundess)
{
    m_border_roudness = border_roundess;
}

NotificationWidget::NotificationWidget(QWidget* parent, QSize base_size) : ScalableWidget(parent, base_size)
{
    m_notificiation_info = new NotificationInfoWidget(this, QSize(width(), 0.8f * height()));
    connect(&m_notification_state, SIGNAL(notificationUpdate()), this, SLOT(notificationUpdate()));
    updateNotificationInfo();
}

void NotificationWidget::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
    painter.setRenderHint(QPainter::Antialiasing, true);

    QPainterPath path;
    path.addRoundedRect(rect(), m_border_roudness * m_scale, m_border_roudness * m_scale);
    painter.fillPath(path, Qt::darkGray);

    painter.setPen(Qt::white);

    QPolygonF left_polygon = QVector<QPointF>{
        QPointF(0, 0.9f * height()),
        QPointF(0.1 * width(), 0.825f * height()),
        QPointF(0.1 * width(), 0.975f * height()),
        QPointF(0, 0.9f * height()),
    };

    int count = m_notification_state.count();

    if (count != 0)
    {
        if (m_current != 0)
        {
            QPainterPath left_path;
            left_path.addPolygon(left_polygon);

            painter.drawPolygon(left_polygon);
            painter.fillPath(left_path, Qt::white);
        }

        QPolygonF right_polygon = QVector<QPointF>{
            QPointF(width(), 0.9f * height()),
            QPointF(0.9 * width(), 0.825f * height()),
            QPointF(0.9 * width(), 0.975f * height()),
            QPointF(width(), 0.9f * height()),
        };

        int display_size = count < m_display_size? count : m_display_size;
        if (m_current != display_size - 1)
        {
            QPainterPath right_path;
            right_path.addPolygon(right_polygon);

            painter.drawPolygon(right_polygon);
            painter.fillPath(right_path, Qt::white);
        }
    }
}

void NotificationWidget::resizeEvent(QResizeEvent*)
{
    updateScale();

    m_notificiation_info->resize(width(), 0.8f * height());
    m_notificiation_info->move(0, 0);
}

void NotificationWidget::mouseReleaseEvent(QMouseEvent* event)
{
    int count = m_notification_state.count();

    if (count == 0)
        return;

    int display_size = count < m_display_size? count : m_display_size;

    if (event->x() < 0.5f * width())
    {
        if (m_current != 0)
        {
            m_current--;
        }
    }
    else
    {
        if (m_current != display_size - 1)
        {
            m_current++;
        }
    }

    updateNotificationInfo();
}
