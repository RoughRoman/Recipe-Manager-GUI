/*
#Over view#
    This class should be used as a abstract data type inside a recipe container class
    However. It is simple enough to be used anyhow.
    Yes this is lots of documentation just because that's good practice.

#Additional notes#
    packagePrice and packageAmount refer to the product as you got it on the shelf.
    This information can be used to calculate recipe cost

#What needs to be done# (remove once done)
    o Testing

#Changelog#
    28/02/2021- Declared class/default and parameter constructors/member variables.
                Implemented getters. Poorly implemented setters.- Matty
    01/03/2021- Added namespace std for QString usage. Bug fixes; dont program while high.
    02/03/2021- Implemented constructors, Data checking and defaulting, header file made.

*/
#include "ingredient.hpp"

using namespace std; // Doing this is bad but its fine because we arent
                     // using any other namespace anyway.

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

QString ingredient::getName()const
{//  returns name
    return name;
}

QString ingredient::getMeasurementUnit()const
{// returns measurement unit
    return measurementUnit;
}

float ingredient::getUsedAmount()const
{// returns used amountt
    return usedAmount;
}

float ingredient::getPackagePrice()const
{// returns package price
    return usedAmount;
}

float ingredient::getPackageAmount()const
{// returns package amount
    return packageAmount;
}

float ingredient::getUnitPrice()const
{// price is usedamount/packedamount * packed price.
    return((usedAmount / packageAmount) * packagePrice);
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

