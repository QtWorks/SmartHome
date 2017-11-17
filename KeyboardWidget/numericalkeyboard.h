#ifndef NUMERICALKEYBOARD_H
#define NUMERICALKEYBOARD_H


#include <QtGui>
#include <QTextEdit>
#include "qpushbutton1.h"
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QButtonGroup>
#include <QLabel>

class NumericalKeyboard : public QWidget
{
    Q_OBJECT

    QHBoxLayout *mainLayout;

    QWidget* numKeypadWidget;
    QVBoxLayout *numKeyPadLayout;
    QLineEdit* textEdit;
    QHBoxLayout *textEditLayout;
    QHBoxLayout *numKeypadRow1;
    QHBoxLayout *numKeypadRow2;
    QHBoxLayout *numKeypadRow3;
    QHBoxLayout *numKeypadRow4;
    QButtonGroup numButtonsGroup;

    QWidget* functionButtonsWidget;
    QVBoxLayout *functionButtonsLayout;
    QButtonGroup functionButtonsGroup;

    QList<QAbstractButton*> allButtons;

    QTimer* textChangeTimer;



    void createNumButtons();
    void createFuncButtons();

    void populateNumKeypad();
    void populateFuncButtonsLayout();
public:
    explicit NumericalKeyboard(QWidget *parent = 0);

    virtual QSize sizeHint();
    QString getText();

    void mousePressEvent(QMouseEvent * event);
    void mouseReleaseEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    
signals:
    void sigKeyPressed(QKeyEvent* event);
    void sigSwitchLayout();
    

private slots:
    void slotNumKeyClicked(QAbstractButton * button);
    void slotFuncKeyClicked(QAbstractButton *button);
    void slotTextChanged(const QString& text);
    void slotTextChangeTimerTimeout();

public slots:
    void setText(QString text);
};

#endif // NUMERICALKEYBOARD_H
