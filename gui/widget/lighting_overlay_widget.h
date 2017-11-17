#ifndef LIGHTING_OVERLAY_WIDGET_H
#define LIGHTING_OVERLAY_WIDGET_H

#include "scalable_widget.h"
#include <QWidget>
#include <qslider.h>

class LightingOverlayWidget : public QWidget
{
    Q_OBJECT

    QSlider* m_slider;

private slots:
    void okClicked();
    void cancelClicked();

public:
    explicit LightingOverlayWidget(QWidget* parent);

    void setValue(int value);
    int value() const;

signals:
    void ok();
    void cancel();
};
#endif
