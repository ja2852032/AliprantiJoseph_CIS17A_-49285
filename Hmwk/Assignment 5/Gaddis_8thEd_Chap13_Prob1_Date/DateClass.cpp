/* 
 * File:   main.cpp
 * Author: Joseph Alipranti
 * Created on November 11th, 2020, 7:25 PM
 * Purpose: Class functions
 */

#include "DateClass.h"
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

void Date::getData(int m, int d, int y){
    month = m;
    day = d;
    year = y;
}

void Date::print1(){
    cout<<month<<"/"<<day<<"/"<<year<<endl;
}

void Date::print2(){
    string mon;
    mon=month==1?"January":month==2?"February":month==3?"March":month==4?"April":
        month==5?"May":month==6?"June":month==7?"July":month==8?"August":
        month==9?"September":month==10?"October":month==11?"November":"December";
    
    cout<<mon<<" "<<day<<", "<<year<<endl;
}

void Date::print3(){
    string mon;
    mon=month==1?"January":month==2?"February":month==3?"March":month==4?"April":
        month==5?"May":month==6?"June":month==7?"July":month==8?"August":
        month==9?"September":month==10?"October":month==11?"November":"December";
    
    cout<<day<<" "<<mon<<" "<<year<<endl;
}