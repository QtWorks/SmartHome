#ifndef MAIN_SCREEN_H
#define MAIN_SCREEN_H

#include "base_screen.h"
#include <QStackedLayout>
#include "gui/widget/background_widget.h"
#include "gui/widget/navigation_widget.h"
#include "notification_screen.h"

class MainScreen : public BaseScreen
{
    Q_OBJECT

    bool m_notification_visible{false};
    bool m_screens_active{true};

protected:
    QStackedLayout* m_screen_layout{nullptr};
    QStackedLayout* m_help_layout{nullptr};
    BackgroundWidget* m_navigation_background{nullptr};
    QWidget* m_screen;
    QWidget* m_help_screen;
    NotificationScreen* m_notification_screen;

    QSize m_navigation_background_size{60, 476};
    QSize m_navigation_widget_size{60, 41};
    QSize m_screen_size{730, 480};
    QSize m_help_screen_size{800, 480};

    QPoint m_screen_pos{70, 0};
    QPoint m_help_screen_pos{0, 0};
    QPoint m_navigation_background_pos{2, 2};

    int m_border_width{10};
    int m_count{10};

    QVector<NavigationWidget*> m_navigation_widget_vector;

    QPixmap getImage(int index);
    QString getTitle(int index);
    QString getFileName(int index);
    QString getText(int index);

private slots:
    void screenSelected(int index);
    void goToNotificationSlot();
    void goToHelpSlot();
    void returnFromNotificationSlot();
    void returnFromHelpSlot();

public:
    explicit MainScreen(QWidget* parent);

protected:
    void setupLayout();
};

#endif
