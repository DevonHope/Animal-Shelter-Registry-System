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
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_lockButton_clicked();

    void on_unlockButton_clicked();

    void on_saveButton_clicked();

    void on_loadButton_clicked();

    void on_getAnimalsButton_clicked();

    void on_viewAnimalButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
