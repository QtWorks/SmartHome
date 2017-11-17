#ifndef ALPHABETICALKEYBOARD_H
#define ALPHABETICALKEYBOARD_H

#include <QtGui>
#include <QTextEdit>
#include "qpushbutton1.h"
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QButtonGroup>
#include <QLabel>

class AlphabeticalKeyboard : public QWidget
{
    Q_OBJECT

    QVBoxLayout *widgetHolder;
    QWidget* containerWidget;
    QVBoxLayout *mainLayout;

    QLineEdit* textEdit;
    QHBoxLayout *textEditLayout;

    QHBoxLayout *alphaKeypadRow1;
    QHBoxLayout *alphaKeypadRow2;
    QHBoxLayout *alphaKeypadRow3;
    QHBoxLayout *alphaKeypadRow4;
    QButtonGroup letterButtonsGroup;

    QButtonGroup functionButtonsGroup;

    QList<QAbstractButton*> allButtons;

    QTimer* textChangeTimer;

    bool caseUpperPermanetly;
    bool caseUpperOnce;
    QLabel* caseIndicatorlabel;

    void createLetterButtons();
    void displayLetters();

    void createFuncButtons();

    void populateAlphaKeypad();
public:
    explicit AlphabeticalKeyboard(QWidget *parent = 0);

    virtual QSize sizeHint();
    QString getText();

    void mousePressEvent(QMouseEvent * event);
    void mouseReleaseEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    
signals:
    void sigKeyPressed(QKeyEvent* event);
    void sigSwitchLayout();
    
private slots:
    void slotLetterKeyClicked(QAbstractButton * button);
    void slotFuncKeyClicked(QAbstractButton *button);
    void slotTextChanged(const QString& text);
    void slotTextChangeTimerTimeout();

public slots:
    void setText(QString text);
};

#endif // ALPHABETICALKEYBOARD_H
