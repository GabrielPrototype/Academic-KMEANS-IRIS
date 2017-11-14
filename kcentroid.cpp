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

#include "kcentroid.h"


KCentroid::KCentroid()
{

}

KCentroid::KCentroid(std::int16_t id)
{


    // sorteia a posição do centroid.
    this->cntrdPoint.setId(id);
    this->cntrdPoint.setSepalLengthCm(randomDouble(5, 7));
    this->cntrdPoint.setSepalWidthCm(randomDouble(2.5, 3));
    this->cntrdPoint.setPetalLengthCm(randomDouble(2, 5.5));
    this->cntrdPoint.setPetalWidthCm(randomDouble(0.5, 2.2));
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
        m1 += irisData.getItem(item).getPetalLengthCm();
        m2 += irisData.getItem(item).getPetalWidthCm();
        m3 += irisData.getItem(item).getSepalLengthCm();
        m4 += irisData.getItem(item).getSepalWidthCm();
    }

    this->cntrdPoint.setPetalLengthCm(m1/numItens);
    this->cntrdPoint.setPetalWidthCm(m2/numItens);
    this->cntrdPoint.setSepalLengthCm(m3/numItens);
    this->cntrdPoint.setSepalWidthCm(m4/numItens);

    return EXIT_SUCCESS;
}

void KCentroid::addToClusterIndex(int64_t id)
{
    clusterIndex.push_back(id);
}

void KCentroid::clearClusterIndex()
{
    clusterIndex.clear();
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

    for (int i = 0; i < vctrCentroids.size(); i++) {
        vctrCentroids[i].clearClusterIndex();
    }

    foreach (IrisDataItem point, irisData.getIrisVector()) {

        nrstCentroidIndex = -1;
        nrstDistance = -1;
        tmpDist = 0;
        index = 0;

        foreach (KCentroid centroid, vctrCentroids) {
            tmpDist = IrisData::euclidianDistance(point, centroid.getCntrdPoint());

            if(nrstDistance == -1 || nrstDistance > tmpDist){
                nrstDistance = tmpDist;
                nrstCentroidIndex = index;
            }

            index++;
        }
        vctrCentroids[nrstCentroidIndex].addToClusterIndex(point.getId());
    }

    return true;
}

bool KCentroid::compareCentroidsPos(KCentroid a, KCentroid b)
{
    if(a.getCntrdPoint().getPetalLengthCm() != b.getCntrdPoint().getPetalLengthCm())
        return false;
    if(a.getCntrdPoint().getPetalWidthCm() != b.getCntrdPoint().getPetalWidthCm())
        return false;
    if(a.getCntrdPoint().getSepalLengthCm() != b.getCntrdPoint().getSepalLengthCm())
        return false;
    if(a.getCntrdPoint().getSepalWidthCm() != b.getCntrdPoint().getSepalWidthCm())
        return false;

    return true;
}

double KCentroid::randomDouble(double min, double max)
{
    return  (max - min) * ((((float) qrand()) / (float) RAND_MAX)) + min ;
}




