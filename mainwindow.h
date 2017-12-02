/*
 * This file is part of KMeans_IRIS.
 *
 * KMeans_IRIS is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * KMeans_IRIS is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with KMeans_IRIS.  If not, see <http://www.gnu.org/licenses/>.
 */

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
#include <QStandardItemModel>

#include <irisdata.h>
#include <kcentroid.h>
#include "constants.h"


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
    void makeTable();
    double getAtributeByNameXAxis(std::int32_t id);
    double getAtributeByNameYAxis(std::int32_t id);


};

#endif // MAINWINDOW_H
