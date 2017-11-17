#ifndef ALARM_SCREEN_H
#define ALARM_SCREEN_H

#include "left_right_screen.h"
#include "gui/widget/alarm_options_widget.h"
#include "KeyboardWidget/QVirtualKeyboard.h"

class AlarmScreen : public LeftRightScreen
{
    Q_OBJECT

    AlarmOptionsWidget* m_alarm_opt_widget{nullptr};
    Alarm& m_alarm_state = Singleton<Alarm>::instance();
    QString m_buffer;

    QVirtualKeyboard* m_keyboard{nullptr};

signals:
    void logged();

private slots:
    void valueChange(QKeyEvent* event);
    void passwordClicked();

public:
    explicit AlarmScreen(QWidget* parent);

protected:
    void setupLayout();

    // QWidget interface
protected:
    void leaveEvent(QEvent *);
};

#endif
