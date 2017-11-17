#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include <QObject>
#include <QVector>
#include "singleton.h"

class Temperature : public QObject
{
    Q_OBJECT

    friend class Singleton<Temperature>;

    QVector<qreal> m_temperature_vector{18.0f, 18.0f, 18.0f, 18.0f, 18.0f, 18.0f, 18.0f, 18.0f};
    QVector<bool> m_ventilation_state_vector{ false, false };

    Temperature() : QObject(nullptr)
    {

    }

public:
    qreal temperature(int index) const;
    void setTemperature(int index, qreal value);
    int temperatureSize() const;

    bool ventilationState(int index) const;
    void setVentilationState(int index, bool value);
    int ventilationStateSize() const;
};

#endif
