#include "kcentroid.h"


KCentroid::KCentroid()
{

}

KCentroid::KCentroid(std::int16_t id)
{

    // sorteia a posição do centroid.
    this->point.setId(id);
    this->point.setSepalLengthCm(((float)qrand() / (float)RAND_MAX) * 9);
    this->point.setSepalWidthCm(((float)qrand() / (float)RAND_MAX) * 6);
    this->point.setPetalLengthCm(((float)qrand() / (float)RAND_MAX) * 8);
    this->point.setPetalWidthCm(((float)qrand() / (float)RAND_MAX) * 4);
    this->point.setSpecies("Centroid_" + QString::number(id));
}


void KCentroid::reCalcCentroid(void){


}

void KCentroid::fillIndexCluster(IrisData &data){



}

std::vector<int32_t> KCentroid::getClusterIndex() const
{
    return clusterIndex;
}
