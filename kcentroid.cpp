#include "kcentroid.h"


KCentroid::KCentroid()
{

}

KCentroid::KCentroid(std::int16_t id)
{

    // sorteia a posição do centroid.
    this->cntrdPoint.setId(id);
    this->cntrdPoint.setSepalLengthCm(((float)qrand() / (float)RAND_MAX) * 9);
    this->cntrdPoint.setSepalWidthCm(((float)qrand() / (float)RAND_MAX) * 6);
    this->cntrdPoint.setPetalLengthCm(((float)qrand() / (float)RAND_MAX) * 8);
    this->cntrdPoint.setPetalWidthCm(((float)qrand() / (float)RAND_MAX) * 4);
    this->cntrdPoint.setSpecies("Centroid_" + QString::number(id));
}


std::int16_t KCentroid::reCalcCentroid(IrisData &irisData)
{
    if(clusterIndex.empty())
        return false;

    double m1 = 0;
    double m2 = 0;
    double m3 = 0;
    double m4 = 0;

    std::int64_t numItens;

    numItens = clusterIndex.size();

    foreach (std::int64_t item, clusterIndex) {
        m1 += irisData.getIrisVector()[item].getPetalLengthCm();
        m2 += irisData.getIrisVector()[item].getPetalWidthCm();
        m3 += irisData.getIrisVector()[item].getSepalLengthCm();
        m4 += irisData.getIrisVector()[item].getSepalWidthCm();
    }

    this->cntrdPoint.setPetalLengthCm(m1/numItens);
    this->cntrdPoint.setPetalWidthCm(m2/numItens);
    this->cntrdPoint.setSepalLengthCm(m3/numItens);
    this->cntrdPoint.setSepalWidthCm(m4/numItens);
}

void KCentroid::addToClusterIndex(int64_t id)
{
    clusterIndex.push_back(id);
}

std::vector<std::int64_t> KCentroid::getClusterIndex() const
{
    return clusterIndex;
}

IrisDataItem KCentroid::getCntrdPoint() const
{
    return cntrdPoint;
}

void KCentroid::newRandomCentroids(std::vector<KCentroid> &vctrCentroids, std::int16_t nCentroids)
{
    //sorteia centroides
    for (int i = 0; i < nCentroids; i++) {

        //dinamicamente adicionar centroids no std::vector.

        KCentroid *cntr = new KCentroid(i+1);
        vctrCentroids.push_back(*cntr);
        delete cntr;
    }
}

std::int16_t KCentroid::clusterizeData(std::vector<KCentroid> &vctrCentroids, IrisData &irisData)
{
    if(vctrCentroids.empty())
        return false;

    std::int16_t index;
    std::int16_t nrstCentroidIndex;
    double nrstDistance;
    double tmpDist;

    foreach (IrisDataItem point, irisData.getIrisVector()) {

        nrstCentroidIndex = -1;
        nrstDistance = NULL;
        tmpDist = 0;
        index = 0;

        foreach (KCentroid centroid, vctrCentroids) {
            tmpDist = IrisData::euclidianDistance(point, centroid.getCntrdPoint());

            if(nrstDistance == NULL || nrstDistance > tmpDist){
                nrstDistance = tmpDist;
                nrstCentroidIndex = index;
            }

            index++;
        }
        vctrCentroids[nrstCentroidIndex].addToClusterIndex(point.getId());
    }

    return true;
}




