#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStackedLayout>
#include "gui/screen/main_screen.h"

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QStackedLayout* layout = new QStackedLayout();
    layout->addWidget(new MainScreen(this));

    centralWidget()->setLayout(layout);
}

MainWindow::~MainWindow()
{
    delete ui;
}
