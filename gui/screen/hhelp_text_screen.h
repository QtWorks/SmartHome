#ifndef HHELP_TEXT_SCREEN_H
#define HHELP_TEXT_SCREEN_H

#include "hhelp_screen.h"
#include "QTextEdit"

class HHelpTextScreen : public HHelpScreen
{
    Q_OBJECT

protected:
    QTextEdit* m_text_edit{nullptr};

    QSize m_text_edit_size{800, 370};
    QPoint m_text_edit_pos{0, 70};

public:
    explicit HHelpTextScreen(QWidget* parent, QString title, QString text = "");
    virtual void setupLayout();
};


#endif // HHELP_TEXT_SCREEN_H
