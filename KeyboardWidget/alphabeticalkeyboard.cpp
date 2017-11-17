#include "alphabeticalkeyboard.h"
#include "keyboardstylessheets.h"

AlphabeticalKeyboard::AlphabeticalKeyboard(QWidget *parent) :
    QWidget(parent)
{
    this->resize(sizeHint());
    caseUpperPermanetly = false;
    caseUpperOnce = false;

    textChangeTimer = new QTimer(this);
    connect(textChangeTimer, SIGNAL(timeout()), this, SLOT(slotTextChangeTimerTimeout()));

    widgetHolder = new QVBoxLayout(this);
    widgetHolder->setSpacing(0);
    widgetHolder->setContentsMargins(0, 0, 0, 0);

    containerWidget = new QWidget(this);
    widgetHolder->addWidget(containerWidget);
    containerWidget->setAttribute(Qt::WA_TransparentForMouseEvents);
    containerWidget->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    containerWidget->resize(sizeHint());
    containerWidget->show();

    mainLayout = new QVBoxLayout(containerWidget);
    mainLayout->setSpacing(3);
    mainLayout->setContentsMargins(5, 5, 5, 5);

    textEdit   = new QLineEdit();
    textEditLayout = new QHBoxLayout();
    textEditLayout->addWidget(textEdit);
    textEditLayout->setContentsMargins(0, 0, 0, 0);
    textEdit->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    textEdit->setStyleSheet(textEditStyle);

    connect(textEdit, SIGNAL(textChanged(QString)), this, SLOT(slotTextChanged(QString)));



    alphaKeypadRow1 = new QHBoxLayout();
    alphaKeypadRow1->setSpacing(3);
    alphaKeypadRow1->setContentsMargins(0, 0, 0, 0);
    alphaKeypadRow2 = new QHBoxLayout();
    alphaKeypadRow2->setSpacing(3);
    alphaKeypadRow2->setContentsMargins(0, 0, 0, 0);
    alphaKeypadRow3 = new QHBoxLayout();
    alphaKeypadRow3->setSpacing(3);
    alphaKeypadRow3->setContentsMargins(0, 0, 0, 0);
    alphaKeypadRow4 = new QHBoxLayout();
    alphaKeypadRow4->setSpacing(3);
    alphaKeypadRow4->setContentsMargins(0, 0, 0, 0);

    mainLayout->addLayout(textEditLayout, 5);
    mainLayout->addLayout(alphaKeypadRow1, 6);
    mainLayout->addLayout(alphaKeypadRow2, 6);
    mainLayout->addLayout(alphaKeypadRow3, 6);
    mainLayout->addLayout(alphaKeypadRow4, 6);

    createLetterButtons();
    createFuncButtons();
    displayLetters();
    populateAlphaKeypad();
}

QSize AlphabeticalKeyboard::sizeHint()
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

QString AlphabeticalKeyboard::getText()
{
    return textEdit->text();
}

void AlphabeticalKeyboard::mousePressEvent(QMouseEvent *event)
{
    mouseMoveEvent(event);
}

void AlphabeticalKeyboard::mouseReleaseEvent(QMouseEvent *)
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

void AlphabeticalKeyboard::mouseMoveEvent(QMouseEvent *)
{
    for(int i = 0; i<allButtons.length(); i++)
        {
            if(dynamic_cast<QPushButton1*>(allButtons[i])
                    ->clickableRect().contains(allButtons[i]->
                    mapFromGlobal(QCursor::pos())))
                {
                    allButtons[i]->setDown(true);
                }
            else
                {
                    allButtons[i]->setDown(false);
                }
        }
}


void AlphabeticalKeyboard::setText(QString text)
{
    textEdit->setText(text);
}

void AlphabeticalKeyboard::createLetterButtons()
{
    for(int i = 0; i< 26; i++)
        {
            letterButtonsGroup.addButton(new QPushButton1("", this),i);
            letterButtonsGroup.button(i)->setFocusPolicy(Qt::NoFocus);
            letterButtonsGroup.button(i)->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

            letterButtonsGroup.button(i)->setStyleSheet(buttonStyle);

            allButtons.append(letterButtonsGroup.button(i));
        }

    connect(&letterButtonsGroup, SIGNAL(buttonClicked(QAbstractButton*)), this, SLOT(slotLetterKeyClicked(QAbstractButton*)));
    displayLetters();
}

void AlphabeticalKeyboard::displayLetters()
{
    QString upperCases = "";
    upperCases += "QWERTYUIOP";
    upperCases += "ASDFGHJKL";
    upperCases += "ZXCVBNM";

    QString lowerCases = "";
    lowerCases += "qwertyuiop";
    lowerCases += "asdfghjkl";
    lowerCases += "zxcvbnm";


    if(caseUpperPermanetly || caseUpperOnce)
    {
        for(int i = 0; i< 26; i++)
            letterButtonsGroup.button(i)->setText(upperCases.at(i));
    }
    else
        for(int i = 0; i< 26; i++)
            letterButtonsGroup.button(i)->setText(lowerCases.at(i));

}

void AlphabeticalKeyboard::createFuncButtons()
{
    QList<QString> functionButtonsNames;
    functionButtonsNames <<"Shift" <<"Backspace"<<"123" <<"Space" <<"Cancel" <<"Enter";

    for (int i = 0; i< functionButtonsNames.length(); i++)
    {
        functionButtonsGroup.addButton(new QPushButton1(functionButtonsNames[i], this),i);
        functionButtonsGroup.button(i)->setFocusPolicy(Qt::NoFocus);
        functionButtonsGroup.button(i)->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

        functionButtonsGroup.button(i)->setStyleSheet(buttonStyle);

        allButtons.append(functionButtonsGroup.button(i));

        if((functionButtonsNames[i] == "Shift") || (functionButtonsNames[i] == "Backspace"))
        {
            functionButtonsGroup.button(i)->setText(""); 
        }
    }
    connect(&functionButtonsGroup, SIGNAL(buttonClicked(QAbstractButton*)), this, SLOT(slotFuncKeyClicked(QAbstractButton*)));
}

void AlphabeticalKeyboard::populateAlphaKeypad()
{
    for(int i = 0; i<10; i++)
        alphaKeypadRow1->addWidget(letterButtonsGroup.button(i));

    alphaKeypadRow2->insertStretch(0, 1);
    for(int i = 10; i<19; i++)
        alphaKeypadRow2->addWidget(letterButtonsGroup.button(i), 2);
    alphaKeypadRow2->insertStretch(-1, 1);

    alphaKeypadRow3->addWidget(functionButtonsGroup.button(0), 3);
    for(int i = 19; i<26; i++)
        alphaKeypadRow3->addWidget(letterButtonsGroup.button(i), 2);
    alphaKeypadRow3->addWidget(functionButtonsGroup.button(1), 3);

    alphaKeypadRow4->addWidget(functionButtonsGroup.button(2), 3);
    alphaKeypadRow4->addWidget(functionButtonsGroup.button(4), 4);
    alphaKeypadRow4->addWidget(functionButtonsGroup.button(3), 7);

    alphaKeypadRow4->addWidget(functionButtonsGroup.button(5), 4);


    QPixmap shiftPixmap = QPixmap(":arrow.png");
    QPixmap delPixmap = QPixmap(":delArrow.png");

    functionButtonsGroup.button(0)->setIcon(shiftPixmap.scaled(functionButtonsGroup.button(0)->width(),
                                                                functionButtonsGroup.button(0)->height(),
                                                                Qt::KeepAspectRatio));
    functionButtonsGroup.button(1)->setIcon(delPixmap.scaled(functionButtonsGroup.button(1)->width(),
                                                                functionButtonsGroup.button(1)->height(),
                                                                Qt::KeepAspectRatio));

    caseIndicatorlabel = new QLabel("",functionButtonsGroup.button(0));

    caseIndicatorlabel->setFixedSize(functionButtonsGroup.button(0)->height()/3,
                                      functionButtonsGroup.button(0)->height()/3);
    QString s1 = "QLabel{border: 1px solid gray;border-radius: ";
    QString s2 = QString::number(caseIndicatorlabel->width()/2);
    QString s3 = "px;background: rgb(240, 240, 240);}";

    caseIndicatorlabel->setStyleSheet(s1+s2+s3);
    caseIndicatorlabel->move(functionButtonsGroup.button(0)->height()/4,functionButtonsGroup.button(0)->height()/4);

}

void AlphabeticalKeyboard::slotLetterKeyClicked(QAbstractButton *button)
{
    textEdit->setText(textEdit->text() + button->text());
    emit sigKeyPressed(new QKeyEvent(QEvent::KeyPress, button->text()[0].unicode(), Qt::NoModifier, button->text()));

    if(caseUpperOnce)
    {
        caseUpperOnce = false;
        QString s1 = "QLabel{border: 1px solid gray;border-radius: ";
        QString s2 = QString::number(caseIndicatorlabel->width()/2);
        QString s3 = "px;background: rgb(240, 240, 240);}";

        caseIndicatorlabel->setStyleSheet(s1+s2+s3);
        displayLetters();
    }
}

void AlphabeticalKeyboard::slotFuncKeyClicked(QAbstractButton *button)
{
    QString buttonName = button->text();

    if(button == functionButtonsGroup.button(0))
    {
        if(caseUpperPermanetly)
        {
            QString s1 = "QLabel{border: 1px solid gray;border-radius: ";
            QString s2 = QString::number(caseIndicatorlabel->width()/2);
            QString s3 = "px;background: rgb(240, 240, 240);}";

            caseIndicatorlabel->setStyleSheet(s1+s2+s3);
            caseUpperOnce = false;
            caseUpperPermanetly = false;
        }
        else
        {
            if(caseUpperOnce)
            {
                QString s1 = "QLabel{border: 1px solid gray;border-radius: ";
                QString s2 = QString::number(caseIndicatorlabel->width()/2);
                QString s3 = "px;background: rgb(240, 0, 0);}";

                caseIndicatorlabel->setStyleSheet(s1+s2+s3);
                caseUpperPermanetly = true;
                caseUpperOnce = false;
            }
            else
            {
                QString s1 = "QLabel{border: 1px solid gray;border-radius: ";
                QString s2 = QString::number(caseIndicatorlabel->width()/2);
                QString s3 = "px;background: rgb(0, 0, 240);}";

                caseIndicatorlabel->setStyleSheet(s1+s2+s3);
                caseUpperOnce = true;
            }
        }
        displayLetters();
    }

    else if(button == functionButtonsGroup.button(1))
    {
        textEdit->backspace();
        emit sigKeyPressed(new QKeyEvent(QEvent::KeyPress, Qt::Key_Backspace, Qt::NoModifier));
    }

    else if(buttonName == "123")
    {
        emit sigSwitchLayout();
    }

    else if(buttonName == "Space")
    {
        textEdit->setText(textEdit->text() + " ");
        emit sigKeyPressed(new QKeyEvent(QEvent::KeyPress, Qt::Key_Space, Qt::NoModifier));
    }

    else if(buttonName == "Cancel")
    {
        emit sigKeyPressed(new QKeyEvent(QEvent::KeyPress, Qt::Key_Cancel, Qt::NoModifier));
    }
    else if(buttonName == "Enter")
    {
        emit sigKeyPressed(new QKeyEvent(QEvent::KeyPress, Qt::Key_Enter, Qt::NoModifier, QString(QChar(13))+QString(QChar(13))));
    }

}

void AlphabeticalKeyboard::slotTextChanged(const QString&)
{
    textEdit->setStyleSheet(textEditChangedStyle);
    textChangeTimer->start(150);

}

void AlphabeticalKeyboard::slotTextChangeTimerTimeout()
{
    textEdit->setStyleSheet(textEditStyle);
    textChangeTimer->stop();
}
