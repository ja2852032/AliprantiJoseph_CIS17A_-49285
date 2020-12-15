
/* 
 * File:   Company.h
 * Author: Joseph Alipranti
 *
 * Created on October 18, 2020, 7:10 PM
 */

#ifndef COMPANY_H
#define COMPANY_H
#include <string>

using namespace std;

struct Sales
{
    string branch;
    int quarter[4];
    float qSales[4];
};

#endif /* COMPANY_H */

