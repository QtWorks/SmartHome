#ifndef GARDENING_OPTIONS_WIDGET_H
#define GARDENING_OPTIONS_WIDGET_H

#include "scalable_widget.h"

class GardeningOptionsWidget : public ScalableWidget
{
    Q_OBJECT

private slots:
    void sprinklerOnClicked();
    void sprinklerOffClicked();

public:
    explicit GardeningOptionsWidget(QWidget* parent, QSize base_size);

signals:
    void sprinklerOn();
    void sprinklerOff();

};

#endif
