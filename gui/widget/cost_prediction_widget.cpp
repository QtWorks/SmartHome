#include "cost_prediction_widget.h"
#include <QPainter>

CostPredictionWidget::CostPredictionWidget(QWidget* parent, QSize base_size) : ScalableWidget(parent, base_size)
{

}

void CostPredictionWidget::setBorderRoundess(int border_roundess)
{
    m_border_roudness = border_roundess;
}

void CostPredictionWidget::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
    painter.setRenderHint(QPainter::Antialiasing, true);

    QPainterPath path;
    path.addRoundedRect(rect(), m_border_roudness * m_scale, m_border_roudness * m_scale);
    painter.fillPath(path, Qt::darkGray);

    QFont font;
    font.setPixelSize(20 * m_scale);
    painter.setFont(font);

    painter.setPen(Qt::white);
    painter.drawLine(0.05 * width(), 0.2f * height(), 0.95 * width(), 0.2f * height());
    painter.drawLine(width()/2, 0.2f * height(), width()/2, 0.7f * height());
    painter.drawLine(0.05 * width(), 0.65f * height(), 0.95 * width(), 0.65f * height());
    painter.drawLine(width()/2, 0.7f * height(), width()/2, 0.95f * height());

    QRect euro_rect(0.55f * width(), 0.2f * height(), 0.4f * width(), 0.45f * height());
    QRect value_rect(0.05f * width(), 0.3f * height(), 0.4f * width(), 0.45f * height());
    QRect cost_text_rect(0.05 * width(), 0, 0.95 * width(), 0.2f * height());
    QRect real_today_rect(0.05 * width(), 0.7f * height(), 0.4f * width(), 0.2f * height());
    QRect predicted_today_rect(0.55 * width(), 0.7f * height(), 0.45f * width(), 0.2f * height());
    QRect predicted_month_rect(0.05f * width(), 0.2f * height(), 0.4f * width(), 0.25f * height());

    QPixmap pixmap(":/Smart home/euro.png");
    QPixmap scaled_pixmap = pixmap.scaled(pixmap.width() * m_width_scale, pixmap.height() * m_height_scale, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    painter.drawPixmap(euro_rect.center().x() - 0.5f * scaled_pixmap.width(), euro_rect.center().y() - 0.5f * scaled_pixmap.height(), scaled_pixmap);

    QFont f( "Arial", 10);
    painter.setFont(f);
    painter.drawText(predicted_month_rect,Qt::AlignCenter, "Predicted for \nthis month:");
    painter.setFont(font);
    painter.drawText(value_rect, Qt::AlignCenter, "200 " + QString::fromUtf8("\u20AC"));
    painter.drawText(cost_text_rect, Qt::AlignCenter, "Cost prediction");
    painter.setFont(f);
    painter.drawText(real_today_rect, Qt::AlignCenter, "So far today: \n 8 " + QString::fromUtf8("\u20AC"));
    painter.drawText(predicted_today_rect, Qt::AlignCenter, "Predicted for  \n today: 10 " + QString::fromUtf8("\u20AC"));
}
