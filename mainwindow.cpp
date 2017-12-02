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

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graphFrame->setEnabled(false);
    ui->graphFrame->setHidden(true);
    ui->tabWidget->setEnabled(false);
    chartView = new QChartView();

}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::deleteAll( QScatterSeries * element )
{
    delete element;
    return true;
}

void MainWindow::plotChart(){

    ui->graphFrame->setEnabled(true);
    ui->graphFrame->setHidden(false);
    ui->tabWidget->setEnabled(true);

    chartView->chart()->removeAllSeries();
    scatterList.clear();

    delete chartView;
    chartView = new QChartView();

    ui->gridGraph->addWidget(chartView, 0, 1);

    // execute delete antes de remover o ponteiro, e assim apaga toda a lista.
    //scatterList.remove_if([](QScatterSeries *element){delete element; return true;});


    foreach (KCentroid item, vctrCentroids) {
        QScatterSeries *series = new QScatterSeries();

        series->setName(item.getCntrdPoint().getSpecies());
        series->setMarkerShape(QScatterSeries::MarkerShapeCircle);
        series->setMarkerSize(15.0);

        foreach (std::int32_t id, item.getClusterIndex()) {
             series->append(tmpMethodX(id),tmpMethodY(id));

        }
        scatterList.push_back(series);
    }


    foreach (QScatterSeries *item, scatterList) {
        chartView->chart()->addSeries(item);
    }

    chartView->chart()->createDefaultAxes();
    chartView->chart()->legend()->setMarkerShape(QLegend::MarkerShapeFromSeries);

    this->ui->lbX->setText(this->ui->cmbX->currentText());
    this->ui->lbY->setText(this->ui->cmbY->currentText());


}

void MainWindow::makeTable()
{

    ui->tableMatrix->clear();
    QStringList horzHeaders;
    horzHeaders << "Iris Setosa" << "Iris Versicolor" << "Iris Virginica";
    ui->tableMatrix->setRowCount(3);
    ui->tableMatrix->setColumnCount(vctrCentroids.size());
    ui->tableMatrix->setVerticalHeaderLabels( horzHeaders );


    std::int32_t count_setosa;
    std::int32_t count_versicolor;
    std::int32_t count_virginica;

    QString tmp = "";

    for (std::int32_t i = 0;  i < vctrCentroids.size(); i++) {

        count_setosa = 0;
        count_versicolor = 0;
        count_virginica = 0;

        foreach (std::int32_t id, vctrCentroids[i].getClusterIndex()) {

            tmp = irisdata.getItem(id).getSpecies();

            if (tmp == "Iris-setosa") count_setosa++;
            else if (tmp == "Iris-versicolor") count_versicolor++;
            else if (tmp == "Iris-virginica") count_virginica++;
        }

        ui->tableMatrix->setItem(0,i,new QTableWidgetItem(QString::number(count_setosa)));
        ui->tableMatrix->setItem(1,i,new QTableWidgetItem(QString::number(count_versicolor)));
        ui->tableMatrix->setItem(2,i,new QTableWidgetItem(QString::number(count_virginica)));
    }

}

double MainWindow::tmpMethodX(int32_t id)
{

   QString text = this->ui->cmbX->currentText();

   return tmpMethod(id,text);

}

double MainWindow::tmpMethodY(std::int32_t id)
{

   QString text = this->ui->cmbY->currentText();

   return tmpMethod(id,text);

}

double MainWindow::tmpMethod(int32_t id, QString text)
{

    if (text == "SepalLengthCm")
        return  irisdata.getItem(id).getSepalLengthCm();
    if (text == "SepalWidthCm")
        return  irisdata.getItem(id).getSepalWidthCm();
    if (text == "PetalLengthCm")
        return  irisdata.getItem(id).getPetalLengthCm();
    if (text ==  "PetalWidthCm")
        return  irisdata.getItem(id).getPetalWidthCm();

}

void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Selecionar base de dados"), "",
                                                    tr("All Files (*)"));
    if (fileName.isEmpty())
        return;

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(this, tr("Falha ao abrir arquivo"),
                                 file.errorString());
        return;
    }
    if(!irisdata.loadData(file)){
        QMessageBox::information(this, tr("Falha ao carregar arquivo"),
                                 "Houve um problema ao carregar o arquivo");
        return;
    }

    this->ui->btExec->setEnabled(true);
    this->ui->btOpen->setEnabled(false);

    this->ui->cmbX->addItems(QStringList()
                             << tr("SepalLengthCm")
                             << tr("SepalWidthCm")
                             << tr("PetalLengthCm")
                             << tr("PetalWidthCm"));
    this->ui->cmbY->addItems(QStringList()
                             << tr("SepalLengthCm")
                             << tr("SepalWidthCm")
                             << tr("PetalLengthCm")
                             << tr("PetalWidthCm"));
    this->ui->cmbY->setCurrentIndex(1);
    QMessageBox::information(this, tr("Alerta"),
                             "O arquivo foi carregado com sucesso");
    return;
}

void MainWindow::on_actionGo_triggered()
{
    qsrand(QTime::currentTime().msec());

    std::vector<KCentroid> tmpCentroids;

    int32_t nCentroids = this->ui->sbxCentroids->value();
    bool execute = true;
    std::uint32_t i;


    if (!(nCentroids >= 2)) {
        QMessageBox::information(this, tr("Numero de Centroides fora do limite"),
                                 "numero de centroides fora do limite");
        return;
    }


    if(vctrCentroids.size() > 0 ){
        vctrCentroids.clear();
    }
    //sorteia os centroids
    KCentroid::newRandomCentroids(vctrCentroids, nCentroids);

    do{
        //calcula distancias e define a qual centroide o ponto pertence
        KCentroid::clusterizeData(vctrCentroids,irisdata);

        tmpCentroids = vctrCentroids;

        for (i = 0; i < vctrCentroids.size(); i++) {
            vctrCentroids[i].reCalcCentroid(irisdata);
        }

        for ( i = 0; i < vctrCentroids.size() && execute; i++) {
            execute = ! KCentroid::compareCentroidsPos(vctrCentroids[i],tmpCentroids[i]);
            // execute é true quando o estado anterior do vetor é diferente do estado atual.
        }

    }while(execute);

    this->ui->graphFrame->setEnabled(true);
    plotChart();
    makeTable();
    return;
}

void MainWindow::on_actionUpdateGraph_triggered()
{
    if(this->ui->cmbX->currentText() == this->ui->cmbY->currentText()){

        QMessageBox::information(this, tr("Menssagem"),
                                 "Um mesmo atributo foi selecionado para ambos os eixos");

        return;
    }

    plotChart();
}
