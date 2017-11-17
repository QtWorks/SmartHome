#ifndef NOTIFICATION_INFO_WIDGET_H
#define NOTIFICATION_INFO_WIDGET_H

#include "scalable_widget.h"
#include <QTimer>

class NotificationInfoWidget : public ScalableWidget
{
    Q_OBJECT

    QPixmap m_icon;
    QString m_date_time;
    QString m_information;
    int m_border_roudness{10};
    QTimer* m_blink_timer;

    bool m_toggled{true};
    bool m_severe{false};

private slots:
    void toggleBlink();

public:
    explicit NotificationInfoWidget(QWidget* parent, QSize base_size);

    void setIcon(const QPixmap& icon);
    void setDateTime(const QString& date_time);
    void setInformation(const QString& information);
    void setBorderRoundess(int border_roundess);
    void setSevere(bool severe);

protected:
    void paintEvent(QPaintEvent*);
};

#endif
