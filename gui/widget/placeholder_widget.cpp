#include "placeholder_widget.h"
#include <QPainter>

PlaceholderWidget::PlaceholderWidget(QWidget* parent, QSize base_size, QColor background_color, const QString &title, int font_pixel_size) : ScalableWidget(parent, base_size), m_background_color(background_color), m_title(title), m_font_pixel_size(font_pixel_size)
{

}

void PlaceholderWidget::setIndex(int index)
{
    m_index = index;
}

void PlaceholderWidget::setTitle(const QString &title)
{
    m_title = title;
}

void PlaceholderWidget::setBorderRoundess(int border_roundess)
{
    m_border_roudness = border_roundess;
}

void PlaceholderWidget::setBackgroundColor(QColor background_color)
{
    m_background_color = background_color;
    update();
}

void PlaceholderWidget::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
    painter.setRenderHint(QPainter::Antialiasing, true);

    QPainterPath path;
    path.addRoundedRect(rect(), m_border_roudness * m_scale, m_border_roudness * m_scale);
    painter.fillPath(path, m_background_color);

    QFont font = painter.font();
    font.setPixelSize(m_font_pixel_size * m_scale);
    font.setBold(true);
    painter.setFont(font);
    painter.setPen(Qt::white);
    painter.drawText(rect(), Qt::AlignCenter, m_title);
}

void PlaceholderWidget::mouseReleaseEvent(QMouseEvent*)
{
    emit selected(m_index);
    emit clicked();
}
