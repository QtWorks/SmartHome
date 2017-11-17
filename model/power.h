#ifndef POWER_H
#define POWER_H

#include <QObject>
#include <QVector>
#include "singleton.h"

class Power : public QObject
{
    Q_OBJECT

    friend class Singleton<Power>;

    QVector<bool> m_enabled{ true, false, false, false, false, true, false, true, true, true, false, true, false, false, false, false};
    QVector<int> m_watt{10, 100, 50, 100, 300, 500, 500, 500, 1000, 500, 500, 300, 100, 50, 100, 50};

    Power() : QObject(nullptr)
    {

    }

public:
    int getMax() const;
    int getTotal() const;
    int getPower(int index) const;
    bool enabled(int index) const;
    void setEnabled(int index, bool enabled);

signals:
    void update();
};

#endif
