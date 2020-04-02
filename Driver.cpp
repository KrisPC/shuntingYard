#include <string.h>
#include <iostream>
#include "StringFunctions.hpp"
#include "Stack.hpp"


using namespace std ;
int main()
{


   Queue * q = StringFunctions::splitString("1111+2-34*56/78","+-*/");

//    for(int i = 0; i <sizeof(arrayStart)+1; i++)
//    {
//        cout<<  arrayStart[i]<< "\n";

//    }
    q->display();

    
    Stack* myStack = new Stack;
    int temp = q->count;

    for(int i = 0; i < temp; i++)
    {
        myStack->push(q->Dequeue());
    }
    cout<<"\n";
    myStack->display();
  


}