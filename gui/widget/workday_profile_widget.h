#ifndef HEATING_PROFILE_WIDGET_H
#define HEATING_PROFILE_WIDGET_H

#include "scalable_widget.h"
#include <QGridLayout>

class  WorkdayProfileWidget : public ScalableWidget
{
    Q_OBJECT

    QGridLayout* toplay{nullptr};

public:
    explicit WorkdayProfileWidget(QWidget* parent, QSize base_size);
};

#endif


