/* 
 * File:   ComGuess.cpp
 * Author: Joseph Alipranti
 * Created on December 11th, 2020, 8:10 PM
 * Purpose: Functions for ComGuess class
 */

//System Libraries
#include <iostream>  //I/O Library
#include <iomanip> //I/O Manipulator
using namespace std;

//User Libraries
#include "ComGuess.h"

//Constructor for ComGuess class
ComGuess::ComGuess(){
    row=0;
    col=0;
    didHit=0;
    didSink=0;
    check=0;
}

//Mutator for didHit private variable
void ComGuess::getHit(int h){
    didHit=h;
}

//Mutator for didSink private variable
void ComGuess::getSunk(int s){
    didSink=s;
}

//Mutator function for row and col private variables
void ComGuess::getNums(int r,int c){
    row=r;
    col=c;
}

//Function to set a new row coordinate for the computer
int ComGuess::nearRow(int ch){
    check=ch;
    if(check==1){
        //If row coordinate at near edge of grid, move 1 unit in
        if(row==0)
            return row+1;
        //If row coordinate at far edge of grid, move 1 unit in
        else if(row==9)
            return row-1;
        else
            return row+1;
    }
    else if(check==3){
        //If row coordinate at near edge of grid, move 1 unit in
        if(row==0)
            return row+1;
        //If row coordinate at far edge of grid, move 1 unit in
        else if(row==9)
            return row-1;
        else
            return row-1;
    }
    else{
        //Else, rows stay the same when alternating with the columns on check
        if(row==0)
            return row;
        else if(row==9)
            return row;
        else
            return row;
    }
}

//Function to set a new col coordinate for the computer
int ComGuess::nearCol(){
    if(check==2){
        //If col coordinate at near edge of grid, move 1 unit in
        if(col==1)
            return col+1;
        //If col coordinate at far edge of grid, move 1 unit in
        else if(col==10)
            return col-1;
        else
            return col+1;
    }
    else if(check==4){
        //If col coordinate at near edge of grid, move 1 unit in
        if(col==1)
            return col+1;
        //If col coordinate at far edge of grid, move 1 unit in
        else if(col==10)
            return col-1;
        else
            return col-1;
    }
    else{
        //Else, columns stay the same when alternating with the rows on check
        if(col==1)
            return col;
        else if(col==10)
            return col;
        else
            return col;
    }
}