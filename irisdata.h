#ifndef IRISDATA_H
#define IRISDATA_H
#include <QFile>


class IrisData
{
public:
    IrisData();
    std::int16_t loadData(QFile & file);

private:


};

#endif // IRISDATA_H
