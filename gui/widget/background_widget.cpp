#include "background_widget.h"
#include <QPainter>


BackgroundWidget::BackgroundWidget(QWidget* parent, QSize base_size, QColor background_color) : ScalableWidget(parent, base_size), m_background_color(background_color)
{

}

void BackgroundWidget::setBorderRoundess(int border_roundess)
{
    m_border_roudness = border_roundess;
}

void BackgroundWidget::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
    painter.setRenderHint(QPainter::Antialiasing, true);

    QPainterPath path;
    path.addRoundedRect(rect(), m_border_roudness * m_scale, m_border_roudness * m_scale);
    painter.fillPath(path, m_background_color);
}



