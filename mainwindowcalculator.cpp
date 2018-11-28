#include "mainwindowcalculator.h"
#include "ui_mainwindowcalculator.h"
#include <iostream>
#include <QPushButton>
#include <QWidget>
#include <QDebug>

MainWindowCalculator::MainWindowCalculator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowCalculator)
{
    ui->setupUi(this);

    QList<QPushButton *> buttons = centralWidget()->findChildren<QPushButton *>("centralWidget");
    qDebug() << buttons.size();

    for (QPushButton *button : buttons) {
        qDebug() << "-> " << (*button).objectName();
    }

    connect(ui->pushButton7, SIGNAL (released()), this, SLOT (press7()));
}

MainWindowCalculator::~MainWindowCalculator()
{
    delete ui;
}

void MainWindowCalculator::press7() {
    ui->textEditResults->setText(ui->textEditResults->toPlainText() + " 7");
}
