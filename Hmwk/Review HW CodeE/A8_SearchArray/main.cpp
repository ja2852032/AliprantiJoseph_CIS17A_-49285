/* 
 * File:   main.cpp
 * Author: Joseph Alipranti
 * Created on 9/17/2020 at 9:00pm
 * Purpose:  Searching for multiple occurrence of patterns
 * Note:  cout proceeds to null terminator, cin reads to end of line
 *        for character arrays
 * 
 */

//System Libraries Here
#include <iostream>//cin,cout,getline()
#include <cstring> //strlen()
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//PI, e, Gravity, or conversions

//Function Prototypes Begins Here
//srch1 utility function Input->start position, Output->position found or not
//srch1 is a simple linear search function, repeat in srchAll till all found
//srch1 Input->sentence, pattern, start position Output-> position found
//Remember arrays start at index/position 0
//srchAll Input->sentence, pattern Output->position array
int  srch1(const char [],const char [],int);//Search for 1 occurrence
void srchAll(const char [],const char [],int []);//Search for all occurrences
void print(const char []);//Print the character arrays
void print(const int []); //Print the array of indexes where the pattern found

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int LINE=81;               //Size of sentence or pattern to find
    char sntnce[LINE],pattern[LINE]; //80 + null terminator
    int match[LINE];                 //Index array where pattern was found
    
    //Input a sentence and a pattern to match
    cout<<"Match a pattern in a sentence."<<endl;
    cout<<"Input a sentence"<<endl;
    cin.getline(sntnce,LINE);
    cout<<"Input a pattern."<<endl;
    cin.getline(pattern,LINE);
    
    //Search for the pattern
    //Input the sentence and pattern, Output the matching positions
    //Remember, indexing starts at 0 for arrays.
    srchAll(sntnce,pattern,match);
    
    //Display the inputs and the Outputs
    cout<<endl<<"The sentence and the pattern"<<endl;
    print(sntnce);
    print(pattern);
    cout<<"The positions where the pattern matched"<<endl;
    print(match);
    
    //Exit
    return 0;
}

int  srch1(const char sntnce[],const char pattern[],int start){
    int patLen=strlen(pattern);
    int found=start; //Found is the starting element of sntnce that matches w/ pattern[0]
    int i=0;
    
    while(i<patLen){
        if(sntnce[start+i]!=pattern[i]){
            found=-1; //If at any point the sntnce array does not match w/ pattern array, found =-1
            i=patLen; //Set i to length of pattern array to end while loop
        }
        i++;
    }
    return found; //Return either -1 if match not found, else return value from start
}

void srchAll(const char sntnce[],const char pattern[],int match[]){
    int start=0, //Variable to determine where to begin the linear search in srch1
        index=0, //Index for while loop
        firstEl=0, //First element of pattern array
        found=0, //Return from srch1 function
        i=0; //Index for match array if a match is found
    int patLen=strlen(pattern);
    int totLen=strlen(sntnce);
    for(int j=0;j<sizeof(match);j++)
        match[j]=-1; //Set all values in match array to -1 (for checking in a later function)
    
    while(index<totLen){
        if(sntnce[index]==pattern[firstEl]){
            start=index; //If char in pattern[0] == char in sntnce[index], set start to index
            
            found=srch1(sntnce, pattern, start); //Call srch1 function, return to found
            if(found>-1){
                match[i]=index; //If found returns an element 0 or greater, match was found
                i++; //Increment i to set up input if another match is found
            }
        }
        index++; //Increment index to control while loop
    }
}

void print(const char input[]){
    cout<<input<<endl; //Cout both inputs when called upon
}

void print(const int match[]){
    int i=0;
    if(match[i]==-1)
        cout<<"None"<<endl; //If value in first element of match is -1, no match was found
    else{
        while(match[i]!=-1){
        cout<<match[i]<<endl; //Else, while values in array match != -1, output values
        i++;
        }
    }
}