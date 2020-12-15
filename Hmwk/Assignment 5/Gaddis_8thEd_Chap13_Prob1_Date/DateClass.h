/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DateClass.h
 * Author: Joseph Alipranti
 *
 * Created on November 11, 2020, 7:30 PM
 */

#ifndef DATECLASS_H
#define DATECLASS_H

class Date
{
    private:
        int month;
        int day;
        int year;
    public:
        void getData(int, int, int);
        void print1();
        void print2();
        void print3();
};

#endif /* DATECLASS_H */

