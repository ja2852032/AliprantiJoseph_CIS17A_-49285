/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nums.h
 * Author: jalip
 *
 * Created on November 12, 2020, 8:55 PM
 */

#ifndef NUMS_H
#define NUMS_H

#include <string>
const int SIZE=6;

class Numbers
{
    private:
        int number;
        static string teens[SIZE];
    public:
        Numbers(int);
        void print();
};

#endif /* NUMS_H */

