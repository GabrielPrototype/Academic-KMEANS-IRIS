#ifndef IRISDATA_H
#define IRISDATA_H
#include <QFile>
#include <QTextStream>
#include <irisdataitem.h>
#include <cmath>

class IrisData
{
public:
    IrisData();
    std::int16_t loadData(QFile & file);

    std::vector<IrisDataItem> getIrisVector() const;

    void replaceItem(const int32_t pos, IrisDataItem &value);

    void replaceList(const std::vector<IrisDataItem> &value);

    void addItem(IrisDataItem &value);

    IrisDataItem getItem(std::int32_t id);

    static double euclidianDistance(IrisDataItem iris1, IrisDataItem iris2);

    void clearVector(void);

private:
    std::vector<IrisDataItem> irisVector;

};

#endif // IRISDATA_H
