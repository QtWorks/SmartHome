#ifndef THERMOMETER_OVERLAY_WIDGET_H
#define THERMOMETER_OVERLAY_WIDGET_H

#include "scalable_widget.h"
#include <QWidget>
#include <qtsvgdialgauge.h>
#include <qslider.h>

class ThermometerOverlayWidget : public QWidget
{
    Q_OBJECT

    QtSvgDialGauge* m_gauge;
    QSlider* m_slider;

private slots:
    void okClicked();
    void cancelClicked();

public:
    explicit ThermometerOverlayWidget(QWidget* parent);

    void setValue(int value);
    qreal value() const;

signals:
    void ok();
    void cancel();
};
#endif
