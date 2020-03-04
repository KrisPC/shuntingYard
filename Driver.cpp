#include <string.h>
#include <iostream>
#include "StringFunctions.hpp"
using namespace std ;
int main()
{
    //char string[]=  "123+456-789*101112/131415";
     char delims[]=  "*/+-";
    string Animals[1] = {"123+456-789*101112/131415"};
    string  * answer = StringFunctions::returnStringArray(Animals[0],Animals[0]);
    StringFunctions::display(answer);
 
  return 0;
}