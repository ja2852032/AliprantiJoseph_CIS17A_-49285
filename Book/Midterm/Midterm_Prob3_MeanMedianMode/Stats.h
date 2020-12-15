/* 
 * File:   Stats.h
 * Author: Joseph Alipranti
 * Created on October 20th, 2020, 7:57 PM
 * Purpose:  Stats structure specification
 */

#ifndef MDSTRUCT_H
#define MDSTRUCT_H
#include "Array.h"

struct Stats{
    Array *mode;  //Array ADT contains number of modes and the modes themselves
    int modFreq;  //Mode Frequency
    float median; //Median of the array
    float avg;    //Average of the Array
};

#endif /* MDSTRUCT_H */
