#include "notification_text_widget.h"
#include <QPainter>

NotificationTextWidget::NotificationTextWidget(QWidget* parent, QSize base_size, const QString& text, int font_size) : ScalableWidget(parent, base_size), m_text(text), m_font_size(font_size)
{

}

void NotificationTextWidget::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
    painter.setRenderHint(QPainter::Antialiasing, true);

    painter.fillRect(rect(), QColor(128, 128, 128));
    painter.setPen(Qt::white);
    QFont font = painter.font();
    font.setPixelSize(m_font_size * m_scale);
    font.setBold(true);
    painter.setFont(font);
    painter.drawText(rect(), Qt::AlignCenter, m_text);
}

