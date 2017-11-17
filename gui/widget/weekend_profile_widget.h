#ifndef LIGHTING_PROFILE_WIDGET_H
#define LIGHTING_PROFILE_WIDGET_H

#include "scalable_widget.h"
#include <QGridLayout>

class  WeekendProfileWidget : public ScalableWidget
{
    Q_OBJECT

    QGridLayout* toplay{nullptr};

public:
    explicit WeekendProfileWidget(QWidget* parent, QSize base_size);
};

#endif



