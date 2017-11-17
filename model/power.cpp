#include "power.h"


int Power::getMax() const
{
    int max = 0;

    for (int i = 0; i < m_enabled.size(); i++)
    {
        max += m_watt[i];
    }

    return max;
}

int Power::getTotal() const
{
    int total = 0;

    for (int i = 0; i < m_enabled.size(); i++)
    {
        total += m_enabled[i] * m_watt[i];
    }

    return total;
}

int Power::getPower(int index) const
{
    return m_watt[index];
}

bool Power::enabled(int index) const
{
    return m_enabled[index];
}

void Power::setEnabled(int index, bool enabled)
{
    m_enabled[index] = enabled;

    emit update();
}
