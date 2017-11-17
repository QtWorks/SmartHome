#include "hhelp_text_screen.h"

HHelpTextScreen::HHelpTextScreen(QWidget* parent, QString title, QString text) : HHelpScreen(parent, title)
{
    m_text_edit = new QTextEdit(this);
    m_text_edit->setText(text);
    m_text_edit->setStyleSheet("color: white; background-color: black; font: bold 20px;");
    m_text_edit->setReadOnly(true);
    m_text_edit->show();

    setupLayout();
}

void HHelpTextScreen::setupLayout()
{
    HHelpScreen::setupLayout();

    m_text_edit->resize(m_text_edit_size.width() * m_width_scale, m_text_edit_size.height() * m_height_scale);
    m_text_edit->move(m_text_edit_pos.x() * m_width_scale, m_text_edit_pos.y() * m_height_scale);
}
