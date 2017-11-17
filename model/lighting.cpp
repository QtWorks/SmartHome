#include "lighting.h"

qreal Lighting::lighting(int index) const
{
    return m_lighting_vector[index];
}

void Lighting::setLighting(int index, qreal value)
{
    m_lighting_vector[index] = value;
}

int Lighting::lightingSize() const
{
    return m_lighting_vector.size();
}


