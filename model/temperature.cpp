#include "temperature.h"

qreal Temperature::temperature(int index) const
{
    return m_temperature_vector[index];
}

void Temperature::setTemperature(int index, qreal value)
{
    m_temperature_vector[index] = value;
}

int Temperature::temperatureSize() const
{
    return m_temperature_vector.size();
}

bool Temperature::ventilationState(int index) const
{
    return m_ventilation_state_vector[index];
}

void Temperature::setVentilationState(int index, bool value)
{
    m_ventilation_state_vector[index] = value;
}

int Temperature::ventilationStateSize() const
{
    return m_ventilation_state_vector.size();
}
