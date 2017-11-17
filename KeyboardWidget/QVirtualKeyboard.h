#ifndef QVIRTUALKEYBOARD_H
#define QVIRTUALKEYBOARD_H

#include <QtGui>
#include <QTextEdit>
#include <QStackedLayout>



#include "alphabeticalkeyboard.h"
#include "numericalkeyboard.h"

class QVirtualKeyboard : public QWidget
{

    Q_OBJECT

    QStackedLayout* stackedLayout;
    QLabel *backgroundLabel;

    AlphabeticalKeyboard* alphabeticalKeyboard;
    NumericalKeyboard* numericalKeyboard;

    bool switchLayoutEnabled;


public:
    QVirtualKeyboard(QWidget *parent = 0);

    virtual QSize sizeHint();
    QString layout() const;

private slots:
     void slotKeyPressed(QKeyEvent* event);


public slots:
    void slotSetText(QString text);
    void slotSwitchLayout();
    void setLayout(QString layoutType);
    void disableLayoutSwitch();
    void enableLayoutSwitch();

signals:
    void keyPressed(QKeyEvent* event);

    // QWidget interface
protected:
    void showEvent(QShowEvent *);

    // QWidget interface
protected:
    void resizeEvent(QResizeEvent* event);
};

#endif // VIRTUALKEYBOARD_H

