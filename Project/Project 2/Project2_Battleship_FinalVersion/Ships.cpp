/* 
 * File:   Ships.cpp
 * Author: Joseph Alipranti
 * Created on December 13th, 2020, 9:00 PM
 * Purpose: Functions for Ships class
 */

//System Libraries
#include <iostream>  //I/O Library
#include <iomanip> //I/O Manipulator
using namespace std;

//User Libraries
#include "Ships.h"

//Static declaration
int Ships::numFlts=2;

//Constructor, setting object size to 5
Ships::Ships(){
    size=5;
    //34 represents the total units covered by both user and computer at the
    //start of the game
    tot=34;
}

//Virtual function (polymorphic)
int Ships::fleet() const{
    return tot;
}