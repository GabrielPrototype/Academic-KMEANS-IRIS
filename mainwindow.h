#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QFileDialog>
#include <QMessageBox>
#include <irisdata.h>
#include <kcentroid.h>

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
    void on_actionOpen_triggered();

    void on_actionGo_triggered();

private:
    Ui::MainWindow *ui;
    IrisData irisdata;

    void plotAll(IrisData&);


};

#endif // MAINWINDOW_H
