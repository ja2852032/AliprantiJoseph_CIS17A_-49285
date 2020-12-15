/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   UsrShips.h
 * Author: Joseph Alipranti
 *
 * Created on December 13, 2020, 8:45 PM
 */

#ifndef USRSHIPS_H
#define USRSHIPS_H

#include "Ships.h"

class UsrShips : public Ships
{
    private:
        //Arrays to hold coordinates of the ship
        int *uShip1;
        int *uShip2;
        int *uShip3;
        int *uShip4;
        int *uShip5;
        int *cShip1;
        int *cShip2;
        int *cShip3;
        int *cShip4;
        int *cShip5;
        //Used to differentiate between user and computer arrays in functions
        int flip;
    public:
        //UsrShips constructor
        UsrShips();
        //UsrShips destructor
        ~UsrShips();
        //Prime the dynamic ship arrays for numerical input
        void mkShips(int);
        //Increment flip object
        void next();
        //Fill the ship arrays with their coordinates
        void fill(int,int,int,int);
        //Determine which element of which ship has been hit, and alters the element
        void hit(int,int);
        //Determines if any of the ship arrays are empty, which means it has sank
        int sunk(int);
        
};

#endif /* USRSHIPS_H */
