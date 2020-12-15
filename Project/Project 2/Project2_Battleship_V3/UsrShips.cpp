/* 
 * File:   UsrShips.cpp
 * Author: Joseph Alipranti
 * Created on December 13th, 2020, 9:10 PM
 * Purpose: Functions for UsrShips class
 */

//System Libraries
#include <iostream>  //I/O Library
#include <iomanip> //I/O Manipulator
using namespace std;

//User Libraries
#include "UsrShips.h"

//Default all ship arrays to null once class is declared
UsrShips::UsrShips(){
    uShip1=nullptr;
    uShip2=nullptr;
    uShip3=nullptr;
    uShip4=nullptr;
    uShip5=nullptr;
    cShip1=nullptr;
    cShip2=nullptr;
    cShip3=nullptr;
    cShip4=nullptr;
    cShip5=nullptr;
    //Initialize flip to 0
    flip=0;
}

//Destructor, releases contents of all ship arrays once program ends
UsrShips::~UsrShips(){
    delete uShip1;
    delete uShip2;
    delete uShip3;
    delete uShip4;
    delete uShip5;
    delete cShip1;
    delete cShip2;
    delete cShip3;
    delete cShip4;
    delete cShip5;
}

//Size the dynamic ship arrays
void UsrShips::mkShips(int n){    
    //Ship1 has size n
    uShip1=new int[n];
    //Ship2 has 1 size less than n (smaller ship)
    uShip2=new int[n-1];
    //Ship3 has 2 sizes less than n (even smaller ship), until back to the top of the order
    uShip3=new int[n-2];
    uShip4=new int[n-2];
    uShip5=new int[n-3];
    cShip1=new int[n];
    cShip2=new int[n-1];
    cShip3=new int[n-2];
    cShip4=new int[n-2];
    cShip5=new int[n-3];
}

//Basic mutator function, increments flip
void UsrShips::next(){
    flip++;
}

//Fill the ship arrays with their coordinate data
void UsrShips::fill(int r,int c,int num,int i){
    //If flip is 0, fill in user ships
    if(flip==0){
        //If num is 0, first ship (biggest)
        if(num==0){
            uShip1[i]=r+(c*10);
        }
        //If num is 1, second ship (2nd biggest)
        else if(num==1){
            uShip2[i]=r+(c*10);
        }
        //If num is 2, third ship (T-3rd biggest)
        else if(num==2){
            uShip3[i]=r+(c*10);
        }
        //If num is 3, fourth ship (T-3rd biggest)
        else if(num==3){
            uShip4[i]=r+(c*10);
        }
        //Else, fill in smallest ship
        else{
            uShip5[i]=r+(c*10);
        }
    }
    //Else, fill in computer ships
    else{
        if(num==0){
            cShip1[i]=r+(c*10);
        }
        else if(num==1){
            cShip2[i]=r+(c*10);
        }
        else if(num==2){
            cShip3[i]=r+(c*10);
        }
        else if(num==3){
            cShip4[i]=r+(c*10);
        }
        else{
            cShip5[i]=r+(c*10);
        }
    }
}

//Determine if ship was hit, and where
void UsrShips::hit(int val,int det){
    //Determine if 0, then user ships
    if(det==0){
        //loop through array to match values passed from main
        for(int i=0;i<size;i++)
            if(uShip1[i]==val)
                //Set element of user ship 1 to 0 if hit
                uShip1[i]=0;
        //loop through array to match values passed from main
        for(int i=0;i<size-1;i++)
            if(uShip2[i]==val)
                //Set element of user ship 2 to 0 if hit
                uShip2[i]=0;
        //loop through array to match values passed from main
        for(int i=0;i<size-2;i++)
            if(uShip3[i]==val)
                //Set element of user ship 3 to 0 if hit
                uShip3[i]=0;
        //loop through array to match values passed from main
        for(int i=0;i<size-2;i++)
            if(uShip4[i]==val)
                //Set element of user ship 4 to 0 if hit
                uShip4[i]=0;
        //loop through array to match values passed from main
        for(int i=0;i<size-3;i++)
            if(uShip5[i]==val)
                //Set element of user ship 5 to 0 if hit
                uShip5[i]=0;
    }
    //Else, computer ships
    else{
        for(int i=0;i<size;i++)
            if(cShip1[i]==val)
                cShip1[i]=0;
        for(int i=0;i<size-1;i++)
            if(cShip2[i]==val)
                cShip2[i]=0;
        for(int i=0;i<size-2;i++)
            if(cShip3[i]==val)
                cShip3[i]=0;
        for(int i=0;i<size-2;i++)
            if(cShip4[i]==val)
                cShip4[i]=0;
        for(int i=0;i<size-3;i++)
            if(cShip5[i]==val)
                cShip5[i]=0;
    }
}

//Determine if any ships have sank
int UsrShips::sunk(int det){
    int c=0;
    //Determine if 0, then values are for user ships
    if(det==0){
        for(int i=0;i<size;i++){
            //If there is any non-zero value, increment c
            if(uShip1[i]!=0)
                c++;
        }
        //If c was not incremented, ship 1 is empty and has sunk
        if(c==0){
            //Add value to empty ship 1 array to keep from later detection
            uShip1[0]=1;
            return -1;
        }
        c=0;
        for(int i=0;i<size-1;i++){
            //If there is any non-zero value, increment c
            if(uShip2[i]!=0)
                c++;
        }
        //If c was not incremented, ship 2 is empty and has sunk
        if(c==0){
            //Add value to empty ship 2 array to keep from later detection
            uShip2[0]=1;
            return -1;
        }
        c=0;
        for(int i=0;i<size-2;i++){
            //If there is any non-zero value, increment c
            if(uShip3[i]!=0)
                c++;
        }
        //If c was not incremented, ship 3 is empty and has sunk
        if(c==0){
            //Add value to empty ship 3 array to keep from later detection
            uShip3[0]=1;
            return -1;
        }
        c=0;
        for(int i=0;i<size-2;i++){
            //If there is any non-zero value, increment c
            if(uShip4[i]!=0)
                c++;
        }
        //If c was not incremented, ship 4 is empty and has sunk
        if(c==0){
            //Add value to empty ship 4 array to keep from later detection
            uShip4[0]=1;
            return -1;
        }
        c=0;
        for(int i=0;i<size-3;i++){
            //If there is any non-zero value, increment c
            if(uShip5[i]!=0)
                c++;
        }
        //If c was not incremented, ship 5 is empty and has sunk
        if(c==0){
            //Add value to empty ship 5 array to keep from later detection
            uShip5[0]=1;
            return -1;
        }
        c=0;
    }
    //Else, they are for computer ships
    else if(det==1){
        //Repeat process like user ships
        for(int i=0;i<size;i++){
            if(cShip1[i]!=0)
                c++;
        }
        if(c==0){
            cShip1[0]=1;
            return -1;
        }
        c=0;
        for(int i=0;i<size-1;i++){
            if(cShip2[i]!=0)
                c++;
        }
        if(c==0){
            cShip2[0]=1;
            return -1;
        }
        c=0;
        for(int i=0;i<size-2;i++){
            if(cShip3[i]!=0)
                c++;
        }
        if(c==0){
            cShip3[0]=1;
            return -1;
        }
        c=0;
        for(int i=0;i<size-2;i++){
            if(cShip4[i]!=0)
                c++;
        }
        if(c==0){
            cShip4[0]=1;
            return -1;
        }
        c=0;
        for(int i=0;i<size-3;i++){
            if(cShip5[i]!=0)
                c++;
        }
        if(c==0){
            cShip5[0]=1;
            return -1;
        }
        c=0;
    }
    else
        return 1;
}
