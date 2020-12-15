/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DoY.h
 * Author: Joseph Alipranti
 *
 * Created on November 12, 2020, 10:05 PM
 */

#ifndef DOY_H
#define DOY_H

#include <string>
const int SIZE=12;

class DayOfYear
{
    private:
        int day;
        static string month[SIZE];
    public:
        DayOfYear(int);
        void print();
};

#endif /* DOY_H */

