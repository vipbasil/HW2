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

    ui->widget->pen->addSphereR( 0.5f);
    ui->widget->repaint();
    ui->objectList->addItem("Sphere");
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
 ui->widget->pen->selectedColor[2] = ChosenColor.blue();

}

void MainWindow::on_pushButton_2_clicked()
{
    //please delete first items from real objects
    qDeleteAll(ui->objectList->selectedItems());
}

void MainWindow::on_Tx_sliderReleased()
{
    float x = (float)ui->Tx->value() / (float)ui->Tx->maximum() * 4 - 2;
    int objectIndex = ui->objectList->currentRow();
    QMatrix4x4 matrix;
    matrix.setToIdentity();
    matrix.translate(x,0,0);
    ui->widget->pen->transformations.at(objectIndex) = matrix;
    ui->widget->repaint();
    //ui->widget->pen->transformations.push_back(matrix);
}
