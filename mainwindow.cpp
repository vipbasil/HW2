#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QColorDialog"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

    switch(ui->comboBox->currentIndex()){
        case 0:{
            ui->widget->pen->addSphereR();
            ui->objectList->addItem("Sphere");
        }break;
        case 1:{
            ui->widget->pen->addConeR();
            ui->objectList->addItem("Cone");
        }break;
        case 2:{
            ui->widget->pen->addCylinderR();
            ui->objectList->addItem("Cylinder");
        }break;
    }
    ui->widget->repaint();

    //ui->objectList->currentItem()->setBackgroundColor();
}

void MainWindow::on_colorButton_clicked()
{
 QColor ChosenColor = QColorDialog::getColor (Qt::white );
 const QString COLOR_STYLE("QPushButton { background-color : %1; color : %2; }");

 //QColor ChosenColor; // Color chosen by the user with QColorDialog
 QColor IdealTextColor = Qt::black;//getIdealTextColor(ChosenColor);
 ui->colorButton->setStyleSheet(COLOR_STYLE.arg(ChosenColor.name()).arg(IdealTextColor.name()));

 ui->widget->pen->selectedColor[0] = ChosenColor.redF();
 ui->widget->pen->selectedColor[1] = ChosenColor.greenF();
 ui->widget->pen->selectedColor[2] = ChosenColor.blueF();

 int objectIndex = ui->objectList->currentRow();
 if(objectIndex == -1)
     return;
  ui->widget->pen->objects.at(objectIndex).set_color(ChosenColor.redF(), ChosenColor.greenF(), ChosenColor.blueF());

}

void MainWindow::on_pushButton_2_clicked()
{
    //please delete first items from real objects
    qDeleteAll(ui->objectList->selectedItems());
}


void MainWindow::on_Ty_valueChanged(int value)
{
    float y = (float)value / (float)ui->Ty->maximum() * ORTHO_DIST * 2 - ORTHO_DIST;
    int objectIndex = ui->objectList->currentRow();
    if(objectIndex == -1)
        return;
    float diff = fabs((ui->widget->pen->objects.at(objectIndex).TranslationY - y) / ORTHO_DIST);
    if( diff > 0.02f)
        ui->widget->pen->objects.at(objectIndex).TranslationY = y;
    ui->widget->repaint();


}

void MainWindow::on_Tz_valueChanged(int value)
{
    float z = (float)value  / (float)ui->Tz->maximum() * ORTHO_DIST * 2 - ORTHO_DIST;
    int objectIndex = ui->objectList->currentRow();
    if(objectIndex == -1)
        return;
    if(fabs((ui->widget->pen->objects.at(objectIndex).TranslationZ - z) / ORTHO_DIST) > 0.02f)
        ui->widget->pen->objects.at(objectIndex).TranslationZ = z;
    ui->widget->repaint();
}

void MainWindow::on_Tx_valueChanged(int value)
{
    float x = (float)value  / (float)ui->Tx->maximum() * ORTHO_DIST * 2 - ORTHO_DIST;
    int objectIndex = ui->objectList->currentRow();
    if(objectIndex == -1)
        return;
    if(fabs((ui->widget->pen->objects.at(objectIndex).TranslationX - x) / ORTHO_DIST) > 0.02f)
        ui->widget->pen->objects.at(objectIndex).TranslationX = x;
    ui->widget->repaint();
}

void MainWindow::on_Rx_valueChanged(int value)
{
    float x = (float)value / (float)ui->Rx->maximum() * 360;
    int objectIndex = ui->objectList->currentRow();
    if(objectIndex == -1)
        return;
    if(fabs((ui->widget->pen->objects.at(objectIndex).RotationX - x) / x) > 0.05f)
        ui->widget->pen->objects.at(objectIndex).RotationX = x;
    ui->widget->repaint();
}

void MainWindow::on_Ry_valueChanged(int value)
{
    float y = (float)value / (float)ui->Ry->maximum() * 360;
    int objectIndex = ui->objectList->currentRow();
    if(objectIndex == -1)
        return;
    if((fabs(ui->widget->pen->objects.at(objectIndex).RotationY - y) / y) > 0.05f)
        ui->widget->pen->objects.at(objectIndex).RotationY = y;
    ui->widget->repaint();

}

void MainWindow::on_Rz_valueChanged(int value)
{
    float z = (float)value / (float)ui->Rz->maximum() * 360;
    int objectIndex = ui->objectList->currentRow();
    if(objectIndex == -1)
        return;
    if(fabs((ui->widget->pen->objects.at(objectIndex).RotationZ - z) / z) > 0.05f)
        ui->widget->pen->objects.at(objectIndex).RotationZ = z;
    ui->widget->repaint();
}

void MainWindow::on_Sx_valueChanged(int value)
{
    float x = (float)value / (float)ui->Sx->maximum() * ORTHO_DIST * 2;
    int objectIndex = ui->objectList->currentRow();
    if(objectIndex == -1)
        return;
    if(fabs((ui->widget->pen->objects.at(objectIndex).ScaleX - x) / x) > 0.05f)
        ui->widget->pen->objects.at(objectIndex).ScaleX = x;

    ui->widget->repaint();
}

void MainWindow::on_Sy_valueChanged(int value)
{
    float y = (float)value / (float)ui->Sy->maximum() * ORTHO_DIST * 2;
    int objectIndex = ui->objectList->currentRow();
    if(objectIndex == -1)
        return;
    if(fabs((ui->widget->pen->objects.at(objectIndex).ScaleY - y) / y) > 0.05f)
        ui->widget->pen->objects.at(objectIndex).ScaleY = y;
    ui->widget->repaint();
}

void MainWindow::on_Sz_valueChanged(int value)
{

    float z = (float)value / (float)ui->Sz->maximum() * ORTHO_DIST * 2;
    int objectIndex = ui->objectList->currentRow();
    if(objectIndex == -1)
        return;
    if(fabs((ui->widget->pen->objects.at(objectIndex).ScaleZ - z) / z) > 0.05f)
        ui->widget->pen->objects.at(objectIndex).ScaleZ = z;
    ui->widget->repaint();
}

void MainWindow::on_objectList_currentRowChanged(int currentRow)
{
    if(currentRow == -1)
        return;
    ui->Tx->setValue(((ui->widget->pen->objects.at(currentRow).TranslationX + ORTHO_DIST) * (float)ui->Tx->maximum()) / (ORTHO_DIST * 2));
    ui->Ty->setValue(((ui->widget->pen->objects.at(currentRow).TranslationY + ORTHO_DIST) * (float)ui->Ty->maximum()) / (ORTHO_DIST * 2));
    ui->Tz->setValue(((ui->widget->pen->objects.at(currentRow).TranslationZ + ORTHO_DIST) * (float)ui->Tz->maximum()) / (ORTHO_DIST * 2));

    ui->Rx->setValue(((ui->widget->pen->objects.at(currentRow).RotationX) * (float)ui->Tx->maximum()) / (360));
    ui->Ry->setValue(((ui->widget->pen->objects.at(currentRow).RotationY) * (float)ui->Ty->maximum()) / (360));
    ui->Rz->setValue(((ui->widget->pen->objects.at(currentRow).RotationZ) * (float)ui->Tz->maximum()) / (360));

    ui->Sx->setValue(((ui->widget->pen->objects.at(currentRow).ScaleX) * (float)ui->Sx->maximum()) / (ORTHO_DIST * 2));
    ui->Sy->setValue(((ui->widget->pen->objects.at(currentRow).ScaleY) * (float)ui->Sy->maximum()) / (ORTHO_DIST * 2));
    ui->Sz->setValue(((ui->widget->pen->objects.at(currentRow).ScaleZ) * (float)ui->Sz->maximum()) / (ORTHO_DIST * 2));



}
