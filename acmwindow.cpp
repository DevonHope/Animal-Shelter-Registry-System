#include "acmwindow.h"
#include "ui_acmwindow.h"

ACMWindow::ACMWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ACMWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("ACM Results");
    ui->textBrowser->setReadOnly(true);
}

ACMWindow::~ACMWindow()
{
    delete ui;
}

void ACMWindow::on_cancelButton_clicked()
{
    this->destroy(); //Closes window
}
