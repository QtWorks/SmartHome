#include "spendings_performance_widget.h"
#include <QPainter>
#include <QDebug>
#include <QtMath>

SpendingsPerformanceWidget::SpendingsPerformanceWidget(QWidget* parent, QSize base_size) : ScalableWidget(parent, base_size)
{

}

void SpendingsPerformanceWidget::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
    painter.setRenderHint(QPainter::Antialiasing);

    QPainterPath path;
    path.addRoundedRect(rect(), 10, 10);
    QPen p(QColor("#1c1c1c"));
    painter.setPen(p);
    painter.fillPath(path, QColor("#1c1c1c"));
    painter.drawPath(path);

    painter.translate(0, 0.2f * height());

    qreal min_dimension = (width() < height()) ? width() : height();
    QPointF c = rect().center();
    QRectF bounds(c.x() - 0.5f * min_dimension, 2 + c.y() - 0.5f * min_dimension, min_dimension, min_dimension);
    painter.fillRect(bounds, "#1c1c1c");

    QPen pen(Qt::white);
    pen.setWidth(2);
    painter.setPen(pen);

    QConicalGradient gradient(rect().center(), 0.0);
    gradient.setColorAt(0.0, QColor(240, 93, 34));
    gradient.setColorAt(0.2, QColor(240, 93, 34));
    gradient.setColorAt(0.2001, QColor(248, 153, 27));
    gradient.setColorAt(0.3, QColor(248, 153, 27));
    gradient.setColorAt(0.3001, QColor(255, 210, 0));
    gradient.setColorAt(0.4, QColor(255, 210, 0));
    gradient.setColorAt(0.4001, QColor(141, 199, 64));
    gradient.setColorAt(0.45, QColor(141, 199, 64));
    gradient.setColorAt(0.4501, QColor(52, 125, 43));
    gradient.setColorAt(0.5, QColor(52, 125, 43));
    gradient.setColorAt(0.55, QColor(240, 93, 34));
    gradient.setColorAt(1.0, QColor(240, 93, 34));
    painter.setBrush(QBrush(gradient));

    //QRectF rectangle(10.0, 20.0, 80.0, 60.0);//preparation for drawPie method
    int startAngle = 0 * 16;
    int spanAngle = 180 * 16;
    painter.drawPie(bounds, startAngle, spanAngle);

    painter.setBrush(QColor("#1c1c1c"));
    painter.drawEllipse(rect().center(), int(0.325f * min_dimension), int(0.325f * min_dimension));
    QRect lower_rect(bounds.topLeft().x(), 1 + bounds.center().y(), bounds.width(), 0.5f * bounds.height());
    painter.fillRect(lower_rect, QColor("#1c1c1c"));

    QVector<qreal> m_angle_vector{-162.0f, -144.0f, -108.0f, -72.0f};
    for (int i = 0; i < m_angle_vector.size(); i++)
    {
        qreal angle = m_angle_vector[i];

        qreal x1 = c.x() + 0.325f * min_dimension * qCos(qDegreesToRadians(angle));
        qreal y1 = c.y() + 0.325f * min_dimension * qSin(qDegreesToRadians(angle));

        qreal x2 = c.x() + 0.485f * min_dimension * qCos(qDegreesToRadians(angle));
        qreal y2 = c.y() + 0.485f * min_dimension * qSin(qDegreesToRadians(angle));

        painter.drawLine(x1, y1, x2, y2);
    }

    qreal mu = qreal(m_power_state.getTotal()) / m_power_state.getMax();
    qreal power_angle =-180.0f + 180.0f * mu;
    qreal x = c.x() + 0.405f * min_dimension * qCos(qDegreesToRadians(power_angle));
    qreal y = c.y() + 0.405f * min_dimension * qSin(qDegreesToRadians(power_angle));

    pen.setColor(Qt::darkGray);
    pen.setWidth(3);
    painter.setPen(pen);
    painter.drawLine(c.x(), c.y(), x, y);

    QRect title_rect(0, -0.2f * height(), width(), 0.2f * height());
    QFont font = painter.font();
    font.setPixelSize(m_scale * 20);
    font.setBold(true);
    painter.setFont(font);
    pen.setColor(Qt::white);
    painter.setPen(pen);
    painter.drawText(title_rect, Qt::AlignCenter, "Power Now");

    QString pc = QString::number(m_power_state.getTotal());
    QRect power_rect(0, 0.6f * height(), width(), 0.2f * height());
    painter.drawText(power_rect, Qt::AlignCenter, pc + " Watts");
}
