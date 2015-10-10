#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void on_pushButton_clicked();

    void on_colorButton_clicked();

    void on_pushButton_2_clicked();

    void on_Ty_valueChanged(int value);

    void on_Tz_valueChanged(int value);

    void on_Tx_valueChanged(int value);

    void on_Rx_valueChanged(int value);

    void on_Ry_valueChanged(int value);

    void on_Rz_valueChanged(int value);

    void on_Sx_valueChanged(int value);

    void on_Sy_valueChanged(int value);

    void on_Sz_valueChanged(int value);

    void on_objectList_currentRowChanged(int currentRow);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
