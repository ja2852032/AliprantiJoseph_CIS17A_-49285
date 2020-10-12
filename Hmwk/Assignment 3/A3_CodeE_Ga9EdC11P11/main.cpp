/* 
 * File:   main.cpp
 * Author: Joseph Alipranti
 * Created on October 11th, 6:20 PM
 * Purpose:  Calculate a student's monthly budget by passing a structure
 *           to a function, displaying the over or under for each category
 */

//System Libraries
#include <iostream> //I/O Library
#include <iomanip> //Formatting Library
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
struct MonthlyBudget
{
    float housing,
          utlts,
          houseEx,
          trnsprt,
          food,
          med,
          ins,
          ent,
          cloth,
          misc;
};

void inBdgt(MonthlyBudget &);
void outBdgt(const MonthlyBudget &);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare/Initialize Variable Data Types and Constants
    MonthlyBudget a;
    
    //Process or map Inputs to Outputs
    
    //Display Outputs
    inBdgt(a);
    outBdgt(a);

    //Exit stage right!
    return 0;
}

void inBdgt(MonthlyBudget &a){
    cout<<"Enter housing cost for the month:$"<<endl;
    cin>>a.housing;
    cout<<"Enter utilities cost for the month:$"<<endl;
    cin>>a.utlts;
    cout<<"Enter household expenses cost for the month:$"<<endl;
    cin>>a.houseEx;
    cout<<"Enter transportation cost for the month:$"<<endl;
    cin>>a.trnsprt;
    cout<<"Enter food cost for the month:$"<<endl;
    cin>>a.food;
    cout<<"Enter medical cost for the month:$"<<endl;
    cin>>a.med;
    cout<<"Enter insurance cost for the month:$"<<endl;
    cin>>a.ins;
    cout<<"Enter entertainment cost for the month:$"<<endl;
    cin>>a.ent;
    cout<<"Enter clothing cost for the month:$"<<endl;
    cin>>a.cloth;
    cout<<"Enter miscellaneous cost for the month:$"<<endl;
    cin>>a.misc;
    
}

void outBdgt(const MonthlyBudget &a){
    float totBdgt=1420;
    float totExp=0,
          diff=0;
    string hRes,
           uRes,
           heRes,
           tRes,
           fRes,
           mRes,
           iRes,
           eRes,
           cRes,
           miRes;
    
    hRes=a.housing==500?"Even":a.housing<500?"Under":"Over";
    cout<<"Housing "<<hRes<<endl;
    uRes=a.utlts==150?"Even":a.utlts<150?"Under":"Over";
    cout<<"Utilities "<<uRes<<endl;
    heRes=a.houseEx==65?"Even":a.houseEx<65?"Under":"Over";
    cout<<"Household Expenses "<<heRes<<endl;
    tRes=a.trnsprt==50?"Even":a.trnsprt<50?"Under":"Over";
    cout<<"Transportation "<<tRes<<endl;
    fRes=a.food==250?"Even":a.food<250?"Under":"Over";
    cout<<"Food "<<fRes<<endl;
    mRes=a.med==30?"Even":a.med<30?"Under":"Over";
    cout<<"Medical "<<mRes<<endl;
    iRes=a.ins==100?"Even":a.ins<100?"Under":"Over";
    cout<<"Insurance "<<iRes<<endl;
    eRes=a.ent==150?"Even":a.ent<150?"Under":"Over";
    cout<<"Entertainment "<<eRes<<endl;
    cRes=a.cloth==75?"Even":a.cloth<75?"Under":"Over";
    cout<<"Clothing "<<cRes<<endl;
    miRes=a.misc==50?"Even":a.misc<50?"Under":"Over";
    cout<<"Miscellaneous "<<miRes<<endl;
    
    totExp=(a.housing+a.utlts+a.houseEx+a.trnsprt+a.food+a.med+a.ins+a.ent+a.cloth+a.misc);
    if(totExp>totBdgt){
        diff=totExp-totBdgt;
        cout<<setprecision(2)<<showpoint<<fixed<<"You were $"<<diff<<" over budget";
    }
    else{
        diff=totBdgt-totExp;
        cout<<setprecision(2)<<showpoint<<fixed<<"You were $"<<diff<<" under budget";
    }
}