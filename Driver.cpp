#include <string.h>
#include <iostream>
#include "StringFactory.hpp"

using namespace std ;
int main()
{


   string * arrayStart = StringFactory::split("1111+2-34*56/78","+-*/");

   for(int i = 0; i <sizeof(arrayStart)+1; i++)
   {
       cout<<  arrayStart[i]<< "\n";

   }
   
  


}