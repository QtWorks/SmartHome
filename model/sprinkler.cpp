#include "sprinkler.h"

bool Sprinkler::sprinklerState(int index) const
{
    return m_sprinkler_state_vector[index];
}

void Sprinkler::setSprinklerState(int index, bool value)
{
    m_sprinkler_state_vector[index] = value;
}

int Sprinkler::sprinklerStateSize() const
{
    return m_sprinkler_state_vector.size();
}
