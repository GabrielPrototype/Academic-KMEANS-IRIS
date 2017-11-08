#ifndef KCENTROID_H
#define KCENTROID_H
#include "irisdata.h"

class KCentroid
{
public:
    KCentroid();
    KCentroid(std::int16_t id);
    void reCalcCentroid();
    void fillIndexCluster(IrisData &data);


    std::vector<int32_t> getClusterIndex() const;

private:
    IrisDataItem point;
    std::vector<int32_t> clusterIndex;


};

#endif // KCENTROID_H
