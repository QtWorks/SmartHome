#ifndef HOME_APPLIANCES_OPTIONS_WIDGET_H
#define HOME_APPLIANCES_OPTIONS_WIDGET_H

#include "scalable_widget.h"
#include "model/power.h"
#include <QGroupBox>
#include <QGridLayout>
#include "qtsvgslideswitch.h"
#include "gui/widget/power_widget.h"

class HomeAppliancesOptionsWidget : public ScalableWidget
{
    Q_OBJECT

    int m_index{0};
    Power& m_power_state = Singleton<Power>::instance();
    QGridLayout* toplay{nullptr};
    QVector<bool> m_switchable{true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true};
    QVector<QGroupBox*> m_beryl_vector;
    QVector<QtSvgSlideSwitch*> m_slider_vector;
    QVector<PowerWidget*> m_power_widget_vector;

    QGroupBox* getOptions(int index);
    QGroupBox* getOptionsWithoutSwitch();

    QString getName(int index);

public:
    explicit HomeAppliancesOptionsWidget(QWidget* parent, QSize base_size);

protected:
    void paintEvent(QPaintEvent*);

public slots:
    void setVisible(int index);
    void switchChanged(QtSvgSlideSwitch* slide, bool state);
    void setState(int index, bool state);
};

#endif
