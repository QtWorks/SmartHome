#include "video_widget.h"
#include <QPainter>

VideoWidget::VideoWidget(QWidget* parent, QSize base_size, const QString& room_name) : ScalableWidget(parent, base_size), m_room_name(room_name)
{

}

void VideoWidget::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
    painter.setRenderHint(QPainter::Antialiasing, true);

    painter.fillRect(rect(), Qt::black);

    QRect room_name_rect(0.025f * width(), 0, 0.65f * width(), 0.175f * height());

    QFont font = painter.font();
    font.setPixelSize(18 * m_scale);
    painter.setFont(font);

    painter.setPen(Qt::white);
    painter.drawText(room_name_rect, Qt::AlignVCenter, m_room_name);
}
