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
