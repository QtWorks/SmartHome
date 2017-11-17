#include "alarm.h"

bool Alarm::alarm(int index) const
{
    return m_alarm_state_vector[index];
}

void Alarm::setAlarm(int index, bool value)
{
    m_alarm_state_vector[index] = value;
}

int Alarm::alarmSize() const
{
    return m_alarm_state_vector.size();
}

bool Alarm::soundOn() const
{
    return m_sound_on;
}

void Alarm::setSoundOn(bool value)
{
    m_sound_on = value;

    emit update();
}

int Alarm::count() const
{
    return m_alarm_state_vector.size();
}

void Alarm::setAlarmRaised(bool value)
{
    m_alarm_raised = value;
}

bool Alarm::alarmRaised() const
{
    return m_alarm_raised;
}
