#ifndef KCENTROID_H
#define KCENTROID_H
#include "irisdata.h"

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
