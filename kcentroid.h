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

#ifndef KCENTROID_H
#define KCENTROID_H
#include "irisdata.h"
#include "constants.h"

class KCentroid
{
public:
    KCentroid();
    KCentroid(std::int16_t id);
    int16_t reCalcCentroid(IrisData &irisData);
    void addToClusterIndex(std::int64_t id);
    void clearClusterIndex();


    std::vector<int64_t> getClusterIndex() const;
    IrisDataItem getCntrdPoint() const;

    static void newRandomCentroids(std::vector<KCentroid> &vector, int16_t nCentroids);
    static int16_t clusterizeData(std::vector<KCentroid> &vector, IrisData &irisData);
    static bool compareCentroidsPos(KCentroid a, KCentroid b);

private:
    IrisDataItem cntrdPoint;
    std::vector<std::int64_t> clusterIndex;
    double randomDouble(double min, double max);

};

#endif // KCENTROID_H
