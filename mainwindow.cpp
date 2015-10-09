#include "mainwindow.h"
#include "ui_mainwindow.h"

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
    std::vector<float> vertices;
    std::vector<float> onecolor;


    vertices.resize(3);
    onecolor.resize(3);


    vertices[0] = 0.0f;
    vertices[1] = 1.0f;
    vertices[2] = 0.0f;
    ui->widget->pen->addSphereR(vertices, vertices, 0.5f);
    ui->widget->repaint();
}
