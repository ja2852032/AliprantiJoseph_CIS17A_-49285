/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   InventoryClass.h
 * Author: Joseph Alipranti
 *
 * Created on November 12, 2020, 7:25 PM
 */

#ifndef INVENTORYCLASS_H
#define INVENTORYCLASS_H

class Inventory
{
    private:
        int itemNumber;
        int quantity;
        float cost;
        float totalCost;
    public:
        Inventory()
            {itemNumber=0;
             quantity=0;
             cost=0;
             totalCost=0;}
        Inventory(int num,int q,float c)
            {itemNumber=num;
             quantity=q;
             cost=c;
             setTotalCost();}
        void setItemNumber(int n)
            {itemNumber=n;}
        void setQuantity(int q)
            {quantity=q;}
        void setCost(float c)
            {cost=c;}
        void setTotalCost()
            {totalCost=quantity*cost;}
        int getItemNumber()
            {return itemNumber;}
        int getQuantity()
            {return quantity;}
        float getCost()
            {return cost;}
        float getTotalCost()
            {return totalCost;}
};

#endif /* INVENTORYCLASS_H */

