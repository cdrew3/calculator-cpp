#ifndef MAINWINDOWCALCULATOR_H
#define MAINWINDOWCALCULATOR_H

#include <QMainWindow>

namespace Ui {
class MainWindowCalculator;
}

class MainWindowCalculator : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindowCalculator(QWidget *parent = 0);
    ~MainWindowCalculator();

private:
    Ui::MainWindowCalculator *ui;
private slots:
    void press7();
};

#endif // MAINWINDOWCALCULATOR_H
