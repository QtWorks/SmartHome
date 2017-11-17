#ifndef BASE_CONTENT_SCREEN_H
#define BASE_CONTENT_SCREEN_H

#include "base_screen.h"
#include "gui/widget/placeholder_widget.h"

class BaseContentScreen : public BaseScreen
{
    Q_OBJECT

public slots:
    void notificationClicked();
    void helpClicked();

protected:
    PlaceholderWidget* m_help_widget;
    PlaceholderWidget* m_events_widget;

    QSize m_help_widget_size{228, 35};
    QPoint m_help_widget_pos{500, 443};

    QSize m_events_widget_size{228, 35};
    QPoint m_events_widget_pos{265, 443};

    explicit BaseContentScreen(QWidget* parent);
    virtual void setupLayout();
};

#endif
