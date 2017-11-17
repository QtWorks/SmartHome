#ifndef SPRINKLER_H
#define SPRINKLER_H

#include <QObject>
#include <QVector>
#include "singleton.h"

class Sprinkler : public QObject
{
    Q_OBJECT

    friend class Singleton<Sprinkler>;

    QVector<bool> m_sprinkler_state_vector{ false, false, false};

    Sprinkler() : QObject(nullptr)
    {
    }

public:

    bool sprinklerState(int index) const;
    void setSprinklerState(int index, bool value);
    int sprinklerStateSize() const;
};

#endif
