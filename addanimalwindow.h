#ifndef ADDANIMALWINDOW_H
#define ADDANIMALWINDOW_H

#include <QDialog>
#include "animal.h"
#include "filemanager.h"

namespace Ui {
class AddAnimalWIndow;
}

class AddAnimalWIndow : public QDialog
{
    Q_OBJECT

public:
    explicit AddAnimalWIndow(QWidget *parent = 0);
    ~AddAnimalWIndow();

private slots:
    void on_addButton_clicked();

    void on_cancelButton_clicked();

    void on_maleCheck_clicked();

    void on_femaleCheck_clicked();


private:
    Ui::AddAnimalWIndow *ui;
    FileManager fm;
    //void saveAs(Animal a);
};

#endif // ADDANIMALWINDOW_H
