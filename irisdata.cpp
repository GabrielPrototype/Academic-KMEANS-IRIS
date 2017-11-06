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

std::vector<IrisDataItem> IrisData::getObjItem() const
{
    return irisItem;
}

void IrisData::replaceItem(int32_t pos, IrisDataItem &value)
{
    if(pos <= irisItem.size() && pos >= 0)
        irisItem.insert(irisItem.begin(),value);
}

void IrisData::addItem(IrisDataItem &value){

    irisItem.push_back(value);

}

void IrisData::replaceList(const std::vector<IrisDataItem> &value)
{
    irisItem = value;
}
