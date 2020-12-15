/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TopRow.h
 * Author: Joseph Alipranti
 *
 * Created on December 12th, 2020, 2:35 PM
 */

#ifndef TOPROW_H
#define TOPROW_H

class topRow
{
    private:
        char *topGrid;
        int size;
    public:
        //Constructor for topRow
        topRow();
        //Destructor for topRow, deletes dynamic data inline
        ~topRow() {delete topGrid;}
        //function to get size of array for topGrid
        void getSize(int);
        //Size the topGrid array
        void setTop();
        //Fill the topGrid array with chars
        void fillTop(int,char);
        //Return array when called to print the array
        char prnTop(int);
};

#endif /* TOPROW_H */
