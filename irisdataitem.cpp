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

#include "irisdataitem.h"

IrisDataItem::IrisDataItem()
{

}

IrisDataItem::IrisDataItem(const IrisDataItem &obj){

    id = obj.getId();
    sepalLengthCm = obj.getSepalLengthCm();
    sepalWidthCm = obj.getSepalWidthCm();
    petalLengthCm = obj.petalLengthCm;
    petalWidthCm = obj.petalWidthCm;
    species = obj.species;
}

IrisDataItem::IrisDataItem(std::int32_t id, double sepalLengthCm,
                           double sepalWidthCm, double petalLengthCm,
                           double petalWidthCm, QString species)
{
    this->id = id;
    this->sepalLengthCm = sepalLengthCm;
    this->sepalWidthCm = sepalWidthCm;
    this->petalLengthCm = petalLengthCm;
    this->petalWidthCm = petalWidthCm;
    this->species = species;
}

std::int32_t IrisDataItem::getId() const
{
    return id;
}

double IrisDataItem::getSepalLengthCm() const
{
    return sepalLengthCm;
}

double IrisDataItem::getSepalWidthCm() const
{
    return sepalWidthCm;
}

double IrisDataItem::getPetalLengthCm() const
{
    return petalLengthCm;
}

double IrisDataItem::getPetalWidthCm() const
{
    return petalWidthCm;
}

QString IrisDataItem::getSpecies() const
{
    return species;
}

void IrisDataItem::setId(const std::int32_t &value)
{
    id = value;
}

void IrisDataItem::setSepalLengthCm(double value)
{
    sepalLengthCm = value;
}

void IrisDataItem::setSepalWidthCm(double value)
{
    sepalWidthCm = value;
}

void IrisDataItem::setPetalLengthCm(double value)
{
    petalLengthCm = value;
}

void IrisDataItem::setPetalWidthCm(double value)
{
    petalWidthCm = value;
}

void IrisDataItem::setSpecies(const QString &value)
{
    species = value;
}
