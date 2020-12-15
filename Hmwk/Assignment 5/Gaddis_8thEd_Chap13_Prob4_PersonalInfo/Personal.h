/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Personal.h
 * Author: Joseph Alipranti
 *
 * Created on November 11, 2020, 8:40 PM
 */

#ifndef PERSONAL_H
#define PERSONAL_H

#include <string>

class PersonalInfo
{
    private:
        string name;
        string addr;
        int age;
        long int number;
    public:
        void getData(string, string, int, long int);
        void prnData();
};

#endif /* PERSONAL_H */

