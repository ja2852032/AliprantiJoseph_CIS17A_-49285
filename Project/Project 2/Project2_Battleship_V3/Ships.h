/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ships.h
 * Author: Joseph Alipranti
 *
 * Created on December 13, 2020, 8:40 PM
 */

#ifndef SHIPS_H
#define SHIPS_H

class Ships
{
    private:
        //Holds number of players, AKA Fleets
        static int numFlts;
    protected:
        //Number of ships per fleet
        int size;
    public:
        //Ships constructor
        Ships();
        //Ships destructor
        ~Ships() {}
};

#endif /* SHIPS_H */

