#ifndef VACATION_PROFILE_WIDGET_H
#define VACATION_PROFILE_WIDGET_H

#include "scalable_widget.h"
#include <QGridLayout>

class VacationProfileWidget : public ScalableWidget
{
    Q_OBJECT

    QGridLayout* toplay{nullptr};

public:
    explicit VacationProfileWidget(QWidget* parent, QSize base_size);
};

#endif


