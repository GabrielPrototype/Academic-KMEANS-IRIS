#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QFileDialog>
#include <QMessageBox>
#include <QTime>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QScatterSeries>


#include <irisdata.h>
#include <kcentroid.h>

using namespace QtCharts;

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
    std::vector<KCentroid> vctrCentroids;
    QChartView *chartViewMatrix[4][4];
    void plotAll();


};

#endif // MAINWINDOW_H
