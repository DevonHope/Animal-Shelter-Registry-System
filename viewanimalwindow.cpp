#include "viewanimalwindow.h"
#include "ui_viewanimalwindow.h"

ViewAnimalWindow::ViewAnimalWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewAnimalWindow)
{
    ui->setupUi(this);
}

ViewAnimalWindow::~ViewAnimalWindow()
{
    delete ui;
}
