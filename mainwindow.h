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
    explicit MainWindow(QWidget *parent = 0); //constructor
     QString file;

    ~MainWindow();//destructor
public slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private slots:
    //void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;//pointer to mainwindow...helps in accesing the mainwindow
};

#endif // MAINWINDOW_H
