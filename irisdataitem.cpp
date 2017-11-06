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
