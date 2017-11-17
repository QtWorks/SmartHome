#ifndef PASSWORD_WIDGET_H
#define PASSWORD_WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QVirtualKeyboard.h>

class PasswordWidget : public QWidget
{
    Q_OBJECT
    QLabel* m_label;
    QLineEdit* m_line_edit;
    QString m_password;

    QVirtualKeyboard* m_keyboard;

    const QString m_normal_style;
    const QString m_error_style;

    static bool m_logged;

    QTimer* m_reset_timer;

signals:
    void login();
    void cancel();

private slots:
    void valueChange(QKeyEvent* event);
    void reset();

public:
    explicit PasswordWidget(QWidget* parent);
    static bool isLogged();

    QVirtualKeyboard* getKeyboard();

    // QWidget interface
protected:
    void resizeEvent(QResizeEvent *);

    // QWidget interface
protected:
    void hideEvent(QHideEvent *);
};
#endif // PASSWORD_WIDGET_H
