#include "power_widget.h"
#include <QPainter>

PowerWidget::PowerWidget(QWidget* parent, QSize base_size, int power, int font_pixel_size) : ScalableWidget(parent, base_size), m_power(power), m_font_pixel_size(font_pixel_size)
{

}

void PowerWidget::setPower(int power)
{
    m_power = power;
    update();
}

void PowerWidget::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
    painter.setRenderHint(QPainter::Antialiasing, true);

    QPainterPath outer_path;
    QRect outer(0, 0.1 * height(), 0.765 * width(), 0.765 * height());
    outer_path.addRoundedRect(outer, m_border_roudness * m_scale, m_border_roudness * m_scale);
    painter.fillPath(outer_path, Qt::gray);

    QPainterPath inner_path;
    QRect inner(10, 0.1 * height() + 11, 0.685 * width(), 0.6775 * height());
    inner_path.addRoundedRect(inner, m_border_roudness * m_scale, m_border_roudness * m_scale);
    painter.fillPath(inner_path, QColor(98, 98, 98));

    QFont font = painter.font();
    font.setPixelSize(m_font_pixel_size * m_scale);
    font.setBold(true);
    painter.setFont(font);
    painter.setPen(Qt::white);
    QString usage = QString::number(m_power) + "W\nPower\nUsage";
    painter.drawText(inner, Qt::AlignCenter, usage);
}
