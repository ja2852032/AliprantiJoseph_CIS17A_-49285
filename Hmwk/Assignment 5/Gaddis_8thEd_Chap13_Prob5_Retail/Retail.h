
/* 
 * File:   Retail.h
 * Author: Joseph Alipranti
 *
 * Created on November 12, 2020, 4:28 PM
 */

#ifndef RETAIL_H
#define RETAIL_H

#include <string>

class RetailItem
{
    private:
        string description;
        int unitsOnHand;
        float price;
    public:
        RetailItem(string, int, float);
        void prnData(int);
};

#endif /* RETAIL_H */

