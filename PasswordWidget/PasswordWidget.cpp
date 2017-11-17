#include "PasswordWidget.h"
#include <QPainter>
#include <QVBoxLayout>
#include <QDebug>
#include <QApplication>

bool PasswordWidget::m_logged = false;

void PasswordWidget::valueChange(QKeyEvent* event)
{
    qDebug() << "Value change...";
    if (event->key() == Qt::Key_Cancel)
    {
        m_line_edit->setText("");
        m_line_edit->setStyleSheet(m_normal_style);
        m_keyboard->slotSetText(m_line_edit->text());

        emit cancel();
        return;
    }

    if (event->key() == Qt::Key_Enter)
    {

        if (m_line_edit->text() != m_password)
        {
            m_line_edit->setStyleSheet(m_error_style);
        }
        else
        {
            emit login();
            m_line_edit->setText("");
            m_logged = true;
            m_reset_timer->start(3600000);
            m_keyboard->slotSetText(m_line_edit->text());

        }
    }
    else
    {
        m_line_edit->setStyleSheet(m_normal_style);
        QApplication::sendEvent(focusWidget(), event);
        m_keyboard->slotSetText(m_line_edit->text());
    }
}

void PasswordWidget::reset()
{
    m_logged = false;
    m_reset_timer->stop();
}

PasswordWidget::PasswordWidget(QWidget* parent) : QWidget(parent), m_password("service"), m_normal_style("QLineEdit {background: white; border: none;}"), m_error_style("QLineEdit {background: red; border: none;}")
{
    m_label = new QLabel(this);
    QFont font;

    font.setPixelSize(20);

    m_label->setFont(font);
    m_label->setText("PASSWORD:");
    m_label->setStyleSheet("QLabel { color : yellow; }");

    m_line_edit = new QLineEdit(this);
    m_line_edit->setEchoMode(QLineEdit::Password);
    m_line_edit->resize(width() / 4, height() / 10);
    m_line_edit->setStyleSheet(m_normal_style);
    m_line_edit->setFont(font);

    qreal x = (width() - m_line_edit->width()) / 2;
    qreal y = (height() - m_line_edit->height()) / 2;
    m_line_edit->move(x, y);

    y = (height() - m_line_edit->height()) / 2 - 3 * m_label->height();
    m_label->move(x, y);

    m_keyboard = new QVirtualKeyboard(this);
    m_keyboard->setLayout("Numerical");
    m_keyboard->move(0, height() - m_keyboard->height() - m_label->height());
    m_keyboard->show();

    m_line_edit->setFocus();
    m_line_edit->hide();

    QPalette p(palette());
    setAutoFillBackground(true);
    p.setColor(QPalette::Background, Qt::black);
    setPalette(p);

    connect(m_keyboard, SIGNAL(keyPressed(QKeyEvent*)), this, SLOT(valueChange(QKeyEvent*)));

    m_reset_timer = new QTimer(this);
    connect(m_reset_timer, SIGNAL(timeout()), this, SLOT(reset()));
}

bool PasswordWidget::isLogged()
{
    return m_logged;
}

QVirtualKeyboard* PasswordWidget::getKeyboard()
{
    return m_keyboard;
}

void PasswordWidget::resizeEvent(QResizeEvent *)
{
    qreal width_scale = width() / 800.0f;
    qreal height_scale = height() / 480.0f;
    qreal scale = (width_scale < height_scale) ? width_scale : height_scale;

    m_line_edit->resize(width() / 4, height() / 10);

    QFont font;
    font.setPixelSize(20 * scale);

    m_line_edit->setFont(font);

    qreal x = (width() - m_line_edit->width()) / 2;
    qreal y = (height() - m_line_edit->height()) / 2;
    m_line_edit->move(x, y);

    m_label->resize(130 * width_scale, 30 * height_scale);
    m_label->setFont(font);

    x = 300.0f * width_scale;
    y = 126.0f * height_scale;

    m_label->move(x, y);

    m_keyboard->setFixedSize(width(), 3.0f * height() / 5.0f);
    m_keyboard->move(0, height() - m_keyboard->height() - m_label->height());
}

void PasswordWidget::hideEvent(QHideEvent*)
{
    m_line_edit->setStyleSheet(m_normal_style);
    m_line_edit->setText("");
    m_keyboard->slotSetText(m_line_edit->text());
}
