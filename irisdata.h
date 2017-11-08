#ifndef IRISDATA_H
#define IRISDATA_H
#include <QFile>
#include <QTextStream>
#include <irisdataitem.h>

class IrisData
{
public:
    IrisData();
    std::int16_t loadData(QFile & file);

    std::vector<IrisDataItem> getIrisVector() const;

    void replaceItem(const int32_t pos, IrisDataItem &value);

    void replaceList(const std::vector<IrisDataItem> &value);

    void addItem(IrisDataItem &value);

    IrisDataItem getItem(std::int32_t pos);


private:
    std::vector<IrisDataItem> irisItem;
};

#endif // IRISDATA_H
