#ifndef CLOCK_WIDGET_H
#define CLOCK_WIDGET_H

#include "scalable_widget.h"
#include <QTimer>

class ClockWidget : public ScalableWidget
{
    Q_OBJECT

    int m_border_roudness{10};
    QTimer* m_blink_timer;
    bool m_toggled{true};

    QPoint textSize(const QFont& font, const QString& text);

private slots:
    void toggleBlink();

public:
    explicit ClockWidget(QWidget* parent, QSize base_size);

    void setBorderRoundess(int border_roundess);

protected:
    void paintEvent(QPaintEvent*);
};

#endif
