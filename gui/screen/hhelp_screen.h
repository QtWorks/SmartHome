#ifndef HHELP_SCREEN_H
#define HHELP_SCREEN_H

#include "base_screen.h"
#include "gui/widget/placeholder_widget.h"

class HHelpScreen : public BaseScreen
{
    Q_OBJECT

    QString m_title;

public slots:
    void helpClicked();

protected:
    PlaceholderWidget* m_help_widget;

    QSize m_help_widget_size{228, 35};
    QPoint m_help_widget_pos{570, 443};

public:
    explicit HHelpScreen(QWidget* parent, QString title = "777");
    virtual void setupLayout();

    // QWidget interface
protected:
    void paintEvent(QPaintEvent*);
};


#endif // HHELP_SCREEN_H
