#include "notification_info_widget.h"
#include <QPainter>

void NotificationInfoWidget::toggleBlink()
{
    m_toggled = !m_toggled;

    update();
}

NotificationInfoWidget::NotificationInfoWidget(QWidget* parent, QSize base_size) : ScalableWidget(parent, base_size)
{
    m_blink_timer = new QTimer(this);
    m_blink_timer->start(1000);

    connect(m_blink_timer, SIGNAL(timeout()), this, SLOT(toggleBlink()));
}

void NotificationInfoWidget::setIcon(const QPixmap& icon)
{
    m_icon = icon;
    update();
}

void NotificationInfoWidget::setDateTime(const QString& date_time)
{
    m_date_time = date_time;
    update();
}

void NotificationInfoWidget::setBorderRoundess(int border_roundess)
{
    m_border_roudness = border_roundess;
}

void NotificationInfoWidget::setSevere(bool severe)
{
    m_severe = severe;
    update();
}

void NotificationInfoWidget::setInformation(const QString& information)
{
    m_information = information;
    update();
}

void NotificationInfoWidget::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
    painter.setRenderHint(QPainter::Antialiasing, true);

    QFont font = painter.font();
    font.setPixelSize(20 * m_scale);
    painter.setFont(font);

    painter.setPen(Qt::white);

    QRect time_rect(0.3 * width(), 0, 0.5 * width(), 0.3 * height());
    QRect reason_rect(0, 0.4f * height(), width(), 0.3 * height());

    QPainterPath path;
    path.addRoundedRect(rect(), m_border_roudness * m_scale, m_border_roudness * m_scale);
    painter.fillPath(path, Qt::darkGray);

    painter.fillRect(time_rect, Qt::darkGray);
    painter.fillRect(reason_rect, Qt::darkGray);

    if (m_toggled || !m_severe)
    {
        QPixmap pixmap = m_icon.scaled(m_icon.width() * m_scale, m_icon.height() * m_scale, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        QRect pixmap_rect = QRect(5, 5, pixmap.width(), pixmap.height());
        painter.drawPixmap(pixmap_rect, pixmap);
    }

    painter.drawText(time_rect, Qt::AlignCenter, m_date_time);
    painter.drawText(reason_rect, Qt::AlignCenter, m_information);
}
