#include "clock_widget.h"
#include <QPainter>
#include <QTime>

QPoint ClockWidget::textSize(const QFont& font, const QString &text)
{
    QFontMetrics metrics(font);
    return QPoint(metrics.width(text), metrics.height());
}

void ClockWidget::toggleBlink()
{
    m_toggled = !m_toggled;

    update();
}

ClockWidget::ClockWidget(QWidget* parent, QSize base_size) : ScalableWidget(parent, base_size)
{
    m_blink_timer = new QTimer(this);
    m_blink_timer->start(1000);

    connect(m_blink_timer, SIGNAL(timeout()), this, SLOT(toggleBlink()));
}

void ClockWidget::setBorderRoundess(int border_roundess)
{
    m_border_roudness = border_roundess;
}

void ClockWidget::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
    painter.setRenderHint(QPainter::Antialiasing, true);

    QFont font;
    font.setPixelSize(32 * m_scale);
    font.setBold(true);
    painter.setFont(font);

    QPainterPath path;
    path.addRoundedRect(rect(), m_border_roudness * m_scale, m_border_roudness * m_scale);
    painter.fillPath(path, Qt::darkGray);

    painter.setPen(Qt::white);

    QTime time = QTime::currentTime();
    QString hh = QString("%1").arg(time.hour(), 2, 10, QChar('0'));
    QString mm = QString("%1").arg(time.minute(), 2, 10, QChar('0'));

    QPoint c = rect().center();
    QPoint value_metric = textSize(font, ":");
    QRect seperator_rect(c.x() - 0.5f * value_metric.x(), c.y() - 0.5f * value_metric.y(), value_metric.x(), value_metric.y());
    value_metric = textSize(font, "00");
    QRect hh_rect(seperator_rect.topLeft().x() - value_metric.x(), c.y() - 0.5f * value_metric.y() + 3 * m_scale, value_metric.x(), value_metric.y());
    QRect mm_rect(seperator_rect.topRight().x(), c.y() - 0.5f * value_metric.y() + 3 * m_scale, value_metric.x(), value_metric.y());

    painter.drawText(hh_rect, Qt::AlignCenter, hh);
    if (m_toggled == true)
    {
        painter.drawText(seperator_rect, Qt::AlignCenter, ":");
    }
    else
    {
        painter.drawText(seperator_rect, Qt::AlignCenter, " ");
    }
    painter.drawText(mm_rect, Qt::AlignCenter, mm);
}
