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
