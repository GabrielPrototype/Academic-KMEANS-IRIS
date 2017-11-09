#include "irisdata.h"

IrisData::IrisData()
{

}

std::int16_t IrisData::loadData(QFile &file){

    IrisDataItem * idt;

    QStringList strlist;
    if(!file.atEnd())
        file.readLine();

    while(!file.atEnd()){


        QByteArray line = file.readLine();
        if(line.at(line.length() == '\n'))
                line.truncate(line.length()-1);

        strlist.clear();
        foreach (QString str, line.split(',')) {
            strlist.append(str);
        }

        idt = new IrisDataItem(
                    strlist.at(0).toInt(),
                    strlist.at(1).toDouble(),
                    strlist.at(2).toDouble(),
                    strlist.at(3).toDouble(),
                    strlist.at(4).toDouble(),
                    strlist.at(5)
                    );
        addItem(*idt);
        delete idt;

    }
}

IrisDataItem IrisData::getItem(std::int32_t pos)
{
    irisItem[pos];
}

double IrisData::euclidianDistance(IrisDataItem iris1, IrisDataItem iris2)
{

    double a1, a2, a3, a4;
    double dist;

    a1 = iris1.getPetalLengthCm() - iris2.getPetalLengthCm();
    a2 = iris1.getPetalWidthCm() - iris2.getPetalWidthCm();
    a3 = iris1.getSepalLengthCm() - iris2.getSepalLengthCm();
    a4 = iris1.getSepalWidthCm() - iris2.getSepalWidthCm();

    dist = std::pow(a1,2) + std::pow(a2,2) + std::pow(a3,2) + std::pow(a4,2);
    dist = std::sqrt(dist);

    return dist;
}

std::vector<IrisDataItem> IrisData::getIrisVector() const
{
    return irisItem;
}

void IrisData::replaceItem(int32_t pos, IrisDataItem &value)
{
    if(pos < irisItem.size() && pos >= 0)
        irisItem.insert(irisItem.begin(),value);
}

void IrisData::addItem(IrisDataItem &value){

    irisItem.push_back(value);

}

void IrisData::replaceList(const std::vector<IrisDataItem> &value)
{
    irisItem = value;
}
