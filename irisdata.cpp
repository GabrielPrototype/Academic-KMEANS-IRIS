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

    return constants::E_SUCCESS;
}

IrisDataItem IrisData::getItem(std::int32_t id)
{
    std::uint32_t i;

    for( i= 0; i < irisVector.size() && irisVector[i].getId() != id; i++);

    if(i < irisVector.size())
        return irisVector[i];


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

void IrisData::clearVector()
{
    irisVector.clear();
}

std::vector<IrisDataItem> IrisData::getIrisVector() const
{
    return irisVector;
}

double IrisData::getAtributeByName(int32_t id, QString text)
{
    if (text == "SepalLengthCm")
        return  this->getItem(id).getSepalLengthCm();
    if (text == "SepalWidthCm")
        return  this->getItem(id).getSepalWidthCm();
    if (text == "PetalLengthCm")
        return  this->getItem(id).getPetalLengthCm();
    if (text ==  "PetalWidthCm")
        return  this->getItem(id).getPetalWidthCm();

    return 0;
}

void IrisData::addItem(IrisDataItem &value){

    irisVector.push_back(value);

}
