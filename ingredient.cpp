#include "ingredient.hpp"

using namespace std;

ingredient::ingredient()
{// default constructor sets all variables to default values
    name = "Default name";
    measurementUnit = "Default unit";
    usedAmount = 0.0;
    packagePrice = 0.0;
    packageAmount = 0.0;
}

ingredient::ingredient(QString n, QString unit, float usedamount,
           float packprice, float packamount)
{// constructor with data for initialization
    // data check with default
    if (usedamount < 0.0){
        usedamount = 1.0;
    }
    if (packprice < 0.0){
        packprice = 1.0;
    }
    if (packamount < 0.0){
        packamount = 1.0;
    }

    name = n;
    measurementUnit = unit;
    usedAmount = usedamount;
    packagePrice = packprice;
    packageAmount = packamount;


}

QString ingredient::getName()
{//  returns name
    return name;
}

QString ingredient::getMeasurementUnit()
{// returns measurement unit
    return measurementUnit;
}

float ingredient::getUsedAmount()
{// returns used amountt
    return usedAmount;
}

float ingredient::getPackagePrice()
{// returns package price
    return packagePrice;
}

float ingredient::getPackageAmount()
{// returns package amount
    return packageAmount;
}

float ingredient::getUnitPrice()
{// price is usedamount/packedamount * packed price.
    if (packagePrice == 0.0)
    {
        return 0.0;
    }
    else
    {
        return((usedAmount / packageAmount) * packagePrice);
    }

}

void ingredient::setName(QString  n)
{// sets name
    // dont need data checking as who cares if they name it something stupid
    name = n;
}

void ingredient::setMeasurmentUnit(QString unit)
{// sets measurement unit
    // dont need data checking as who cares if they name it something stupid
    measurementUnit = unit;
}

void ingredient::setUsedAmount(float amount)
{// sets amount used
    if (amount < 0.0)
    {// default to 1.0
        amount = 1.0;
    }
    usedAmount = amount;
}

void ingredient::setPackagePrice(float price)
{// sets package price
    if (price < 0.0)
    {// default to 1.0
        price = 1.0;
    }
    packagePrice = price;
}

void ingredient::setPackageAmount(float pAmount)
{// sets package amount
    if (pAmount < 0.0)
    {// default to 1.0
        pAmount = 1.0;
    }
    packageAmount = pAmount;
}

