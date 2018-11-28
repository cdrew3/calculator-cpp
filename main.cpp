#include "mainwindowcalculator.h"
#include <QApplication>
#include <iostream>
#include "arithmetic.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindowCalculator w;
    w.show();

    return a.exec();
}
