#include "mainwindow.h"
#include "ui_mainwindow.h"







MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabs->setEnabled(false);



    chartViewMatrix[0][1] = new QChartView();
    chartViewMatrix[0][2] = new QChartView();
    chartViewMatrix[0][3] = new QChartView();

    chartViewMatrix[1][0] = new QChartView();

    chartViewMatrix[1][2] = new QChartView();
    chartViewMatrix[1][3] = new QChartView();

    chartViewMatrix[2][0] = new QChartView();
    chartViewMatrix[2][1] = new QChartView();

    chartViewMatrix[2][3] = new QChartView();

    chartViewMatrix[3][0] = new QChartView();
    chartViewMatrix[3][1] = new QChartView();
    chartViewMatrix[3][2] = new QChartView();


    ui->gridGeralGraph->addWidget(chartViewMatrix[0][1], 0, 3);
    ui->gridGeralGraph->addWidget(chartViewMatrix[0][2], 0, 4);
    ui->gridGeralGraph->addWidget(chartViewMatrix[0][3], 0, 5);

    ui->gridGeralGraph->addWidget(chartViewMatrix[1][0], 1, 2);

    ui->gridGeralGraph->addWidget(chartViewMatrix[1][2], 1, 4);
    ui->gridGeralGraph->addWidget(chartViewMatrix[1][3], 1, 5);

    ui->gridGeralGraph->addWidget(chartViewMatrix[2][0], 2, 2);
    ui->gridGeralGraph->addWidget(chartViewMatrix[2][1], 2, 3);

    ui->gridGeralGraph->addWidget(chartViewMatrix[2][3], 2, 5);

    ui->gridGeralGraph->addWidget(chartViewMatrix[3][0], 3, 2);
    ui->gridGeralGraph->addWidget(chartViewMatrix[3][1], 3, 3);
    ui->gridGeralGraph->addWidget(chartViewMatrix[3][2], 3, 4);

}

MainWindow::~MainWindow()
{
    delete ui;
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
    QMessageBox::information(this, tr("Alerta"),
                             "O arquivo foi carregado com sucesso");
    return;
}

void MainWindow::plotAll(){

    QScatterSeries *series0 = new QScatterSeries();
    series0->setName("scatter1");
    series0->setMarkerShape(QScatterSeries::MarkerShapeCircle);
    series0->setMarkerSize(2.0);

    series0->append(0, 6);
    series0->append(2, 4);
    series0->append(3, 8);
    series0->append(7, 4);
    series0->append(10, 5);


//    QChart *exChart = new QChart();
//    exChart->addSeries(series0);
//    exChart->createDefaultAxes();
//    exChart->legend()->setMarkerShape(QLegend::MarkerShapeFromSeries);

//    QGraphicsScene *exScene = new QGraphicsScene();
//    exScene->addItem(exChart);
//    ui->grv1x0->setScene(exScene);
//    ui->grv1x0->fitInView(ui->grv1x0->sceneRect(), Qt::KeepAspectRatio);

    chartViewMatrix[1][0]->chart()->addSeries(series0);
    chartViewMatrix[1][0]->chart()->createDefaultAxes();
    chartViewMatrix[1][0]->chart()->legend()->setMarkerShape(QLegend::MarkerShapeFromSeries);


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

    this->ui->tabs->setEnabled(true);
    plotAll();

    return;
}
