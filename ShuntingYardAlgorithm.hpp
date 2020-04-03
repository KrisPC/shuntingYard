#ifndef ShuntingYardAlgorithm_hpp
#define ShuntingYardAlgorithm_hpp
#include "Stack.hpp"
#include "Queue.hpp"
#include "StringFunctions.hpp"
using namespace std;


class ShuntingYardAlgorithm
{
    private:
        static void popThenPushQtoQ(Queue * q1, Queue * q2);
        static void popThenPushStoQ(Stack * s1, Queue * q1);
        static int convertOpToInt(string s1);
        static void popThenPushQtoS(Queue * q1, Stack * s1);


    public:
        static Queue * performAlgorithm(Queue * inputQueue);

};



#endif