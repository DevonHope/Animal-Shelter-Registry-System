#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "animal.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    void initAnimals();
    void refreshAnimals();
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void showProfile();

    void on_addAnimalButton_clicked();

    void on_refreshAnimalsButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
