#include "QVirtualKeyboard.h"
#include <QDebug>

#define defaultWidth    320
#define defaultHeight   240

QVirtualKeyboard::QVirtualKeyboard(QWidget *parent) : QWidget(parent)
{
    this->resize(sizeHint());
    switchLayoutEnabled = true;
    backgroundLabel = new QLabel("",this);
    backgroundLabel->setStyleSheet(QString::fromUtf8("background-color:rgb(105, 105, 105);"));
    backgroundLabel->setGeometry(QRect(0, 0, this->width(), this->height()));
    backgroundLabel->show();
    stackedLayout = new QStackedLayout(this);

    alphabeticalKeyboard = new AlphabeticalKeyboard(this);
    numericalKeyboard = new NumericalKeyboard(this);

    connect(alphabeticalKeyboard, SIGNAL(sigKeyPressed(QKeyEvent*)), this, SLOT(slotKeyPressed(QKeyEvent*)));
    connect(numericalKeyboard, SIGNAL(sigKeyPressed(QKeyEvent*)), this, SLOT(slotKeyPressed(QKeyEvent*)));

    connect(alphabeticalKeyboard, SIGNAL(sigSwitchLayout()), this, SLOT(slotSwitchLayout()));
    connect(numericalKeyboard, SIGNAL(sigSwitchLayout()), this, SLOT(slotSwitchLayout()));


    stackedLayout->addWidget(alphabeticalKeyboard);
    stackedLayout->addWidget(numericalKeyboard);
}

QSize QVirtualKeyboard::sizeHint()
{
    QWidget* parent = parentWidget();

    if (parent == 0)
    {
        return QSize(320, 160);
    }
    else
    {
        return QSize(parent->width(), parent->height());
    }
}

QString QVirtualKeyboard::layout() const
{
    if (stackedLayout->currentIndex() == 0)
    {
        return "Alphabetical";
    }

    if (stackedLayout->currentIndex() == 1)
    {
        return "Numerical";
    }

    return "";
}

void QVirtualKeyboard::slotKeyPressed(QKeyEvent *event)
{
    emit keyPressed(event);
    if(event->key() == Qt::Key_Cancel)
        this->hide();
}

void QVirtualKeyboard::slotSwitchLayout()
{
    // ABC - 0
    // 123 - 1

    if(stackedLayout->currentIndex() == 0)
        numericalKeyboard->setText(alphabeticalKeyboard->getText());
    else
        alphabeticalKeyboard->setText(numericalKeyboard->getText());

    stackedLayout->setCurrentIndex((stackedLayout->currentIndex() + 1) % 2);
}

void QVirtualKeyboard::setLayout(QString layoutType)
{
    if(switchLayoutEnabled == false)
        return;

    else if(layoutType == "Numerical")
    {
        if(stackedLayout->currentIndex() != 1)
            slotSwitchLayout();
    }

    else if(layoutType == "Alphabetical")
    {
        if(stackedLayout->currentIndex() != 0)
            slotSwitchLayout();
    }
}

void QVirtualKeyboard::disableLayoutSwitch()
{
    switchLayoutEnabled = false;
}

void QVirtualKeyboard::enableLayoutSwitch()
{
    switchLayoutEnabled = true;
}

void QVirtualKeyboard::showEvent(QShowEvent *)
{
    backgroundLabel->setGeometry(QRect(0, 0, this->width(), this->height()));
}

void QVirtualKeyboard::resizeEvent(QResizeEvent* event)
{
    backgroundLabel->resize(event->size());

    alphabeticalKeyboard->resize(event->size());
    numericalKeyboard->resize(event->size());
}

void QVirtualKeyboard::slotSetText(QString text)
{
    numericalKeyboard->setText(text);
    alphabeticalKeyboard->setText(text);
}
