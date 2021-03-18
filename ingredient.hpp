#ifndef INGREDIENT_H
#define INGREDIENT_H


// interface for ingredient class
#include <QString>
#include <iostream>

using namespace std;
class ingredient
{
private:
    // Data
    QString name;
    QString measurementUnit;

    float usedAmount;

    float packagePrice;
    float packageAmount;        // used for recipe cost

public:
    // constructors
    // default
    ingredient();
    // for parameterized constructor. If price isnt wanted then leave both optional paramters empty
    ingredient(QString n, QString unit, float usedamount,
               float packprice = 0.0, float packamount = 0.0);

    // general getters
    QString getName() const;
    QString getMeasurementUnit() const;
    float getUsedAmount() const;
    float getPackagePrice() const;
    float getPackageAmount() const;
    float getUnitPrice() const;

    // general setters
    void setName(QString  n);
    void setMeasurmentUnit(QString unit);
    void setUsedAmount(float amount);
    void setPackagePrice(float price);
    void setPackageAmount(float pAmount);

    //overloaded outsteam operators
    friend ostream& operator << (ostream& outs, const ingredient& ing);
};

#endif // INGREDIENT_H
