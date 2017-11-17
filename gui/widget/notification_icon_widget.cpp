#include "notification_icon_widget.h"
#include <QPainter>

QPixmap NotificationIconWidget::getIcon(NotificationEnum type) const
{
    QVector<QPixmap> m_icon{ QPixmap(":/Smart home/green-icon.png"),
                             QPixmap(":/Smart home/warning.png"),
                             QPixmap(":/Smart home/alarm_note.png"),
                             QPixmap(":/Smart home/alarm_note.png"),
                             QPixmap(":/Smart home/dismiss.png")
                            };

    return m_icon[type];
}

void NotificationIconWidget::toggleBlink()
{
    m_toggled = !m_toggled;

    update();
}

NotificationIconWidget::NotificationIconWidget(QWidget* parent, QSize base_size, NotificationEnum type) : ScalableWidget(parent, base_size), m_type(type)
{
    m_blink_timer = new QTimer(this);
    m_blink_timer->start(1000);

    connect(m_blink_timer, SIGNAL(timeout()), this, SLOT(toggleBlink()));
}

void NotificationIconWidget::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
    painter.setRenderHint(QPainter::Antialiasing, true);

    painter.fillRect(rect(), QColor(128, 128, 128));
    if ((m_toggled) || (m_type != NotificationEnum::Alarm && m_type != NotificationEnum::Critical))
    {
        QPixmap pixmap = getIcon(m_type);
        qreal x = rect().center().x() - 0.5f * pixmap.width();
        qreal y = rect().center().y() - 0.5f * pixmap.height();

        painter.drawPixmap(x, y, pixmap);
    }
}
