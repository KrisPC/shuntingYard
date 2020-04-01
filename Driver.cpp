#include <string.h>
#include <iostream>
#include "StringFactory.hpp"

using namespace std ;
int main()
{


   Queue * q = StringFactory::split("1111+2-34*56/78","+-*/");

    //update split to return a queue of strings that will represent our input queue
    // for shunting yard. This will require you to implement a Queue data structure that supports
    //Enqueue and Dequeue 

//    for(int i = 0; i <sizeof(arrayStart)+1; i++)
//    {
//        cout<<  arrayStart[i]<< "\n";

//    }
   
  q->display();


}