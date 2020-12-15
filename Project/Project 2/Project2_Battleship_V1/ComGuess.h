/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ComGuess.h
 * Author: Joseph Alipranti
 *
 * Created on December 11, 2020, 7:55 PM
 */

#ifndef COMGUESS_H
#define COMGUESS_H

class ComGuess
{
    private:
        int row;
        int col;
        int didHit;
        int didSink;
        int check;
    public:
        //Constructor for ComGuess class
        ComGuess();

        //Mutator and Accessor for didHit private variable
        void getHit(int);
        int retHit() const
            { return didHit; }
        
        //Mutator and Accessor for didSink private variable
        void getSunk(int);
        int retSunk() const
            { return didSink; }
        
        //Mutator function for row and col private variables
        void getNums(int,int);
        
        //Functions to set a new row or col coordinate for the computer
        int nearRow(int);
        int nearCol();
};

#endif /* COMGUESS_H */

