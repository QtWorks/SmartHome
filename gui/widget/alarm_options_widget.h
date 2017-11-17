#ifndef ALARM_OPTIONS_WIDGET_H
#define ALARM_OPTIONS_WIDGET_H

#include "scalable_widget.h"
#include "qtsvgslideswitch.h"
#include "model/alarm.h"
#include <QtMultimedia/QSound>
#include "qtsvgbutton.h"

class AlarmOptionsWidget : public ScalableWidget
{
    Q_OBJECT

    QtSvgSlideSwitch* m_slide{nullptr};
    QtSvgButton* button;
    Alarm& m_alarm_state = Singleton<Alarm>::instance();
    QSound* m_alarm;

public:
    explicit AlarmOptionsWidget(QWidget* parent, QSize base_size);
    void setState(bool state);

signals:
    void passwordClicked();

protected:
    void paintEvent(QPaintEvent*);

public slots:
    void switchChanged(QtSvgSlideSwitch* slide, bool state);
    void buttonClicked();
    void logged();

    // QWidget interface
protected:
    void showEvent(QShowEvent *);
};

#endif
