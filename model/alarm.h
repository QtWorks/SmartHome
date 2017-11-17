#ifndef ALARM_H
#define ALARM_H

#include <QObject>
#include <QVector>
#include "singleton.h"

class Alarm : public QObject
{
    Q_OBJECT

    friend class Singleton<Alarm>;

    QVector<bool> m_alarm_state_vector = {false, false, false, false, false, false, false, false, false};
    bool m_sound_on{true};
    bool m_alarm_raised{false};

    Alarm() : QObject(nullptr)
    {

    }

public:
    bool alarm(int index) const;
    void setAlarm(int index, bool value);
    int alarmSize() const;
    bool soundOn() const;
    void setSoundOn(bool value);
    int count() const;
    void setAlarmRaised(bool value);
    bool alarmRaised() const;

signals:
    void update();
};

#endif
