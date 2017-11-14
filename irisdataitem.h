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

#ifndef IRISDATAITEM_H
#define IRISDATAITEM_H

#include <QString>



class IrisDataItem
{
public:
    IrisDataItem();
    IrisDataItem(std::int32_t id, double sepalLengthCm, double sepalWidthCm, double petalLengthCm, double petalWidthCm, QString species);
    IrisDataItem(const IrisDataItem &obj);
    std::int32_t getId() const;

    double getSepalLengthCm() const;

    double getSepalWidthCm() const;

    double getPetalLengthCm() const;

    double getPetalWidthCm() const;

    QString getSpecies() const;


    void setId(const std::int32_t &value);

    void setSepalLengthCm(double value);

    void setSepalWidthCm(double value);

    void setPetalLengthCm(double value);

    void setPetalWidthCm(double value);

    void setSpecies(const QString &value);



private:
    std::int32_t id;
    double sepalLengthCm;
    double sepalWidthCm;
    double petalLengthCm;
    double petalWidthCm;
    QString species;
};

#endif // IRISDATAITEM_H
