#ifndef ACTIVE_PROFILE_WIDGET_H
#define ACTIVE_PROFILE_WIDGET_H

#include "scalable_widget.h"
#include <QGridLayout>
#include <QRadioButton>

class  ActiveProfileWidget : public ScalableWidget
{
    Q_OBJECT

    QGridLayout* toplay{nullptr};

public:
    explicit ActiveProfileWidget(QWidget* parent, QSize base_size);
};

#endif
