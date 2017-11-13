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
    static bool deleteAll(QScatterSeries *element);
private slots:
    void on_actionOpen_triggered();

    void on_actionGo_triggered();

    void on_actionUpdateGraph_triggered();

private:
    Ui::MainWindow *ui;
    IrisData irisdata;
    std::vector<KCentroid> vctrCentroids;

    QChartView *chartView;
    std::list<QScatterSeries*> scatterList;

    void plotChart();
    double tmpMethodX(std::int32_t id);
    double tmpMethodY(std::int32_t id);
    double tmpMethod(std::int32_t id, QString text);



};

#endif // MAINWINDOW_H
