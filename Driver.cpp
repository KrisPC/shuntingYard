#include <string.h>
#include <iostream>
#include "StringFunctions.hpp"
#include "Stack.hpp"
#include "ShuntingYardAlgorithm.hpp"


using namespace std ;
int main()
{


   Queue * q = StringFunctions::splitString("(1-4*(1+1))*3+5","+-*/()");

//    for(int i = 0; i <sizeof(arrayStart)+1; i++)
//    {
//        cout<<  arrayStart[i]<< "\n";

//    }
    q->display();

    
    // Stack* myStack = new Stack;
    // int temp = q->count;

    // for(int i = 0; i < temp; i++)
    // {
    //     myStack->push(q->Dequeue());
    // }
    // cout<<"\n";
    // myStack->display();

    Queue * answer = ShuntingYardAlgorithm::performAlgorithm(q);
    //answer->display();
    answer->fancyDisplay();


}