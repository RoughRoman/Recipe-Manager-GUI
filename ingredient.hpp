#ifndef INGREDIENT_H
#define INGREDIENT_H


// interface for ingredient class
#include <string>
#include <iostream>

using namespace std;
class ingredient
{
private:
    // Data
    string name;
    string measurementUnit;

    float usedAmount;

    float packagePrice;
    float packageAmount;        // used for recipe cost

public:
    // constructors
    // default
    ingredient();
    // for parameterized constructor. If price isnt wanted then leave both optional paramters empty
    ingredient(string n, string unit, float usedamount,
               float packprice = 0.0, float packamount = 0.0);

    // general getters
    string getName() const;
    string getMeasurementUnit() const;
    float getUsedAmount() const;
    float getPackagePrice() const;
    float getPackageAmount() const;
    float getUnitPrice() const;

    // general setters
    void setName(string  n);
    void setMeasurmentUnit(string unit);
    void setUsedAmount(float amount);
    void setPackagePrice(float price);
    void setPackageAmount(float pAmount);

    //overloaded outsteam operators
    friend ostream& operator << (ostream& outs, const ingredient& ing);
};

#endif // INGREDIENT_H
