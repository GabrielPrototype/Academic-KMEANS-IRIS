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

    std::vector<KCentroid> centroids;




    if (!(nCentroids >= 2)) {
        QMessageBox::information(this, tr("Numero de Centroides fora do limite"),
                                 "numero de centroides fora do limite");
        return;
    }

    //sorteia centroides
    for (int i = 0; i < nCentroids; i++) {

        //dinamicamente adicionar centroids no std::vector.

        KCentroid *cntr = new KCentroid(i+1);
        centroids.push_back(*cntr);
        delete cntr;
    }

    //calcula distancias e define a qual centroide o ponto pertence
    foreach (IrisDataItem unit, this->irisdata.getIrisVector()) {

        std::int16_t nearestCentroid = -1;

        foreach (KCentroid centunit, centroids) {

        }
    }




}
