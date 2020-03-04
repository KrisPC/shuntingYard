#include "StringFunctions.hpp"
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
std::string * StringFunctions::returnStringArray(std::string fullString,std::string delims)
{
    std::string * returnThis = new string[50];

    int d = 0;
    string currSpot = "";
    string plus = "+";
    string minus = "-";
    string times = "*";
    string divide = "/";
    for(int i =0; i < fullString.length(); i ++)
    {
        string currentThing(1, fullString[i]);

        if(currentThing.find(plus) != string::npos || currentThing.find(minus) != string::npos || currentThing.find(times) != string::npos || currentThing.find(divide) != string::npos)
        {
           returnThis[d] = currSpot;
           currSpot = "";
           d++;
           returnThis[d] = currentThing;
           d++;
        }
        else
        {
            currSpot = currSpot.append(currentThing);
        }

    }

    returnThis[d] = currSpot;
    currSpot = "";
    d ++;

    return   returnThis;
}

void StringFunctions::display(std::string * input)
{
    int i =0;
    while(input[i] != "" )
    {
        cout<<input[i] << "\n";
        i++;
    }
}