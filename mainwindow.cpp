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

void MainWindow::plotAll(IrisData& data){


}

void MainWindow::on_actionGo_triggered()
{
    int32_t nCentroids = this->ui->sbxCentroids->value();

    if (!(nCentroids >= 2)) {
        QMessageBox::information(this, tr("Numero de Centroides fora do limite"),
                                 "numero de centroides fora do limite");
        return;
    }

    //sorteia os centroids
    KCentroid::newRandomCentroids(vctrCentroids, nCentroids);

    //calcula distancias e define a qual centroide o ponto pertence
    KCentroid::clusterizeData(vctrCentroids,irisdata);

    std::vector<KCentroid> tmpCentroids;
    tmpCentroids = vctrCentroids;

    foreach (KCentroid item, vctrCentroids) {
        item.reCalcCentroid(irisdata);
    }
    return;
}
