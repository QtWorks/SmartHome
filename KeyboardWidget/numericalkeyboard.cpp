#include "numericalkeyboard.h"
#include "keyboardstylessheets.h"

NumericalKeyboard::NumericalKeyboard(QWidget *parent) :
    QWidget(parent)
{
    this->resize(sizeHint());

    textChangeTimer = new QTimer(this);
    connect(textChangeTimer, SIGNAL(timeout()), this, SLOT(slotTextChangeTimerTimeout()));

    numKeypadWidget = new QWidget(this);
    numKeypadWidget->setAttribute(Qt::WA_TransparentForMouseEvents);
    functionButtonsWidget = new QWidget(this);
    functionButtonsWidget->setAttribute(Qt::WA_TransparentForMouseEvents);

    mainLayout = new QHBoxLayout(this);
    mainLayout->setSpacing(5);
    mainLayout->setContentsMargins(5, 5, 5, 5);

    numKeyPadLayout =  new QVBoxLayout(numKeypadWidget);
    numKeyPadLayout->setSpacing(3);
    numKeyPadLayout->setContentsMargins(0, 0, 0, 0);
    textEdit = new QLineEdit();
    textEdit->setEchoMode(QLineEdit::Password);
    textEditLayout = new QHBoxLayout();
    textEditLayout->addWidget(textEdit);
    textEdit->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

    textEdit->setStyleSheet(textEditStyle);

    connect(textEdit, SIGNAL(textChanged(QString)), this, SLOT(slotTextChanged(QString)));

    numKeypadRow1 = new QHBoxLayout();
    numKeypadRow2 = new QHBoxLayout();
    numKeypadRow3 = new QHBoxLayout();
    numKeypadRow4 = new QHBoxLayout();

    createNumButtons();
    createFuncButtons();
    populateNumKeypad();




    mainLayout->addWidget(numKeypadWidget, 3);

    functionButtonsLayout =  new QVBoxLayout(functionButtonsWidget);
    functionButtonsLayout->setSpacing(3);
    functionButtonsLayout->setContentsMargins(0, 0, 0, 0);
    populateFuncButtonsLayout();


    mainLayout->addWidget(functionButtonsWidget, 1);


}

QSize NumericalKeyboard::sizeHint()
{
    QWidget* parent = parentWidget();

        if (parent == 0)
        {
            return QSize(320, 240);
        }
        else
        {
            return QSize(parent->width(), parent->height());
        }
}

QString NumericalKeyboard::getText()
{
    return textEdit->text();
}

void NumericalKeyboard::mousePressEvent(QMouseEvent *event)
{
    mouseMoveEvent(event);
}

void NumericalKeyboard::mouseReleaseEvent(QMouseEvent *)
{
    for(int i = 0; i<allButtons.length(); i++)
        {
            if(dynamic_cast<QPushButton1*>(allButtons[i])
                    ->clickableRect().contains(allButtons[i]->
                    mapFromGlobal(QCursor::pos())))
            {
                allButtons[i]->setDown(false);
                allButtons[i]->click();

            }
        }
}

void NumericalKeyboard::mouseMoveEvent(QMouseEvent* )
{
    for(int i = 0; i<allButtons.length(); i++)
    {
        if(dynamic_cast<QPushButton1*>(allButtons[i])
                ->clickableRect().contains(allButtons[i]->
                mapFromGlobal(QCursor::pos())))
            allButtons[i]->setDown(true);
        else
            allButtons[i]->setDown(false);
    }
}


void NumericalKeyboard::createNumButtons()
{

    QList<QString> numButtonStrings;

    numButtonStrings << "1"<< "2"<< "3";
    numButtonStrings << "4"<< "5"<< "6";
    numButtonStrings << "7"<< "8"<< "9";
    numButtonStrings << "-"<< "0"<< ".";

    for(int i=0; i < numButtonStrings.length(); i++)
    {
        numButtonsGroup.addButton(new QPushButton1(numButtonStrings[i], this),i);
        numButtonsGroup.button(i)->setFocusPolicy(Qt::NoFocus); 
        numButtonsGroup.button(i)->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        numButtonsGroup.button(i)->setStyleSheet(buttonStyle);

        allButtons.append(numButtonsGroup.button(i));
    }

    connect(&numButtonsGroup, SIGNAL(buttonClicked(QAbstractButton*)), this, SLOT(slotNumKeyClicked(QAbstractButton*)));
}

void NumericalKeyboard::createFuncButtons()
{
    QList<QString> funcButtonStrings;

    funcButtonStrings << "Backspace";
    funcButtonStrings << "Cancel";
    funcButtonStrings << "Enter";

    for(int i=0; i < funcButtonStrings.length(); i++)
    {
        functionButtonsGroup.addButton(new QPushButton1(funcButtonStrings[i], this),i);
        functionButtonsGroup.button(i)->setFocusPolicy(Qt::NoFocus);
        functionButtonsGroup.button(i)->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        functionButtonsGroup.button(i)->setStyleSheet(buttonStyle);


        allButtons.append(functionButtonsGroup.button(i));
        if(funcButtonStrings[i] == "Backspace")
            {
                functionButtonsGroup.button(i)->setText("");
            }
    }
    connect(&functionButtonsGroup, SIGNAL(buttonClicked(QAbstractButton*)), this, SLOT(slotFuncKeyClicked(QAbstractButton*)));
}

void NumericalKeyboard::populateNumKeypad()
{
    numKeyPadLayout->addLayout(textEditLayout, 5);
    numKeyPadLayout->addLayout(numKeypadRow1, 6);
    numKeyPadLayout->addLayout(numKeypadRow2, 6);
    numKeyPadLayout->addLayout(numKeypadRow3, 6);
    numKeyPadLayout->addLayout(numKeypadRow4, 6);


    for (int i = 0; i<3; i++)
        numKeypadRow1->addWidget(numButtonsGroup.button(i));
    for (int i = 0; i<3; i++)
        numKeypadRow2->addWidget(numButtonsGroup.button(i+3));
    for (int i = 0; i<3; i++)
        numKeypadRow3->addWidget(numButtonsGroup.button(i+6));
    for (int i = 0; i<3; i++)
        numKeypadRow4->addWidget(numButtonsGroup.button(i+9));
}

void NumericalKeyboard::populateFuncButtonsLayout()
{
    for(int i = 0; i<functionButtonsGroup.buttons().length(); i++)
        functionButtonsLayout->addWidget(functionButtonsGroup.button(i), 5 + 3*(int)(i>0));

    QPixmap delPixmap = QPixmap(":delArrow.png");

    functionButtonsGroup.button(0)->setIcon(delPixmap.scaled(functionButtonsGroup.button(0)->width(),
                                                                functionButtonsGroup.button(0)->height(),
                                                                Qt::KeepAspectRatio));
}

void NumericalKeyboard::slotNumKeyClicked(QAbstractButton *button)
{
    textEdit->setText(textEdit->text() + button->text());
    emit sigKeyPressed(new QKeyEvent(QEvent::KeyPress, button->text()[0].unicode(), Qt::NoModifier, button->text()));
}

void NumericalKeyboard::slotFuncKeyClicked(QAbstractButton *button)
{
    QString buttonName = button->text();

    if(button == functionButtonsGroup.button(0))
    {
        textEdit->backspace();
        emit sigKeyPressed(new QKeyEvent(QEvent::KeyPress, Qt::Key_Backspace, Qt::NoModifier));
    }

    else if(buttonName == "Cancel")
    {
        emit sigKeyPressed(new QKeyEvent(QEvent::KeyPress, Qt::Key_Cancel, Qt::NoModifier));
    }
    else if(buttonName == "Enter")
    {
        emit sigKeyPressed(new QKeyEvent(QEvent::KeyPress, Qt::Key_Enter, Qt::NoModifier, QString(QChar(13))+QString(QChar(13))));
    }
    else if(buttonName == "ABC")
    {
        emit sigSwitchLayout();
    }

}

void NumericalKeyboard::slotTextChanged(const QString&)
{
    textEdit->setStyleSheet(textEditChangedStyle);
    textChangeTimer->start(150);
}

void NumericalKeyboard::slotTextChangeTimerTimeout()
{
    textEdit->setStyleSheet(textEditStyle);
    textChangeTimer->stop();
}

void NumericalKeyboard::setText(QString text)
{
    textEdit->setText(text);
}
