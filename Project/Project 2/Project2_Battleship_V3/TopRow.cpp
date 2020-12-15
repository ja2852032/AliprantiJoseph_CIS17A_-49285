/* 
 * File:   ComGuess.cpp
 * Author: Joseph Alipranti
 * Created on December 12th, 2020, 2:40 PM
 * Purpose: Functions for TopRow class
 */

//System Libraries
#include <iostream>  //I/O Library
#include <iomanip> //I/O Manipulator
using namespace std;

//User Libraries
#include "TopRow.h"

topRow::topRow(){
    size=0;
}

void topRow::getSize(int m){
    size=m;
}

void topRow::setTop(){
    topGrid=new char[size];
}

void topRow::fillTop(int i,char c){
    topGrid[i]=c;
}

char topRow::prnTop(int i){
    return topGrid[i];
}