#ifndef VIDEO_WIDGET_H
#define VIDEO_WIDGET_H

#include "scalable_widget.h"

class VideoWidget : public ScalableWidget
{
    Q_OBJECT

    QString m_room_name;

public:
    explicit VideoWidget(QWidget* parent, QSize base_size, const QString& room_name);

protected:
    void paintEvent(QPaintEvent*);
};

#endif
