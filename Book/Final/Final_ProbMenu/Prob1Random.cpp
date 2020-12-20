/* 
 * File:   Prob1Random.cpp
 * Author: Joseph Alipranti
 * Created on December 15th, 2020, 8:10 PM
 * Purpose: Functions for Prob1Random class
 */

//System Libraries
#include <iostream>  //I/O Library
#include <iomanip> //I/O Manipulator
#include <ctime> //For rand()
using namespace std;

//User Libraries
#include "Prob1Random.h"

Prob1Random::Prob1Random(const char n,const char *numSet){
    nset=n;
    set=new char[static_cast<int>(nset)];
    freq=new int[static_cast<int>(nset)];
    numRand=0;
    
    for(int i=0;i<static_cast<int>(nset);i++){
        set[i]=numSet[i];
    }
    for(int i=0;i<static_cast<int>(nset);i++){
        freq[i]=0;
    }
}

Prob1Random::~Prob1Random(){
    delete []set;
    delete []freq;
}

char Prob1Random::randFromSet(){
    int r=rand()%static_cast<int>(nset);
    freq[r]+=1;
    numRand+=1;
    
    return set[r];
}

int *Prob1Random::getFreq() const{
    return freq;
}

char *Prob1Random::getSet() const{
    return set;
}

int Prob1Random::getNumRand() const{
    return numRand;
}