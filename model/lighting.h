#ifndef LIGHTING_H
#define LIGHTING_H

#include <QObject>
#include <QVector>
#include "singleton.h"

class Lighting : public QObject
{
    Q_OBJECT

    friend class Singleton<Lighting>;

    QVector<qreal> m_lighting_vector = {18.0f, 18.0f, 18.0f, 18.0f, 18.0f, 18.0f, 18.0f, 18.0f};

    Lighting() : QObject(nullptr)
    {

    }

public:
    qreal lighting(int index) const;
    void setLighting(int index, qreal value);
    int lightingSize() const;

};

#endif
