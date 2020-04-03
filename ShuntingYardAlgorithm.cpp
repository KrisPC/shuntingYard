#include "ShuntingYardAlgorithm.hpp"

void ShuntingYardAlgorithm::popThenPushStoQ(Stack * s1, Queue * q1)
{
    q1->Enqueue(s1->pop());
}

int ShuntingYardAlgorithm::convertOpToInt(string s)
{
    if(s == string(1, '*') || s == string(1, '/'))
    {
        return 3;
    }
    else if(s == string(1, '+') || s == string(1, '-'))
    {
        return 2;
    }

    else
    {
        return 0;
    }
    
}


void ShuntingYardAlgorithm::popThenPushQtoS(Queue * q1, Stack * s1)
{
    s1->push(q1->Dequeue());
}
    
Queue * ShuntingYardAlgorithm::performAlgorithm(Queue * inputQueue)
{
    Queue * outputQueue = new Queue();
    Stack * operatorStack = new Stack();

    Node * currNode = inputQueue->peek();
    //While there is stuff in the input queue
    while(inputQueue)
    {
        //We are looking at a number
        if( ! StringFunctions::isInString("+-*/()", currNode->getPayload()))
        {
            ShuntingYardAlgorithm::popThenPushQtoQ(inputQueue, outputQueue);
        }

        //We are looking at an operator
        else if(StringFunctions::isInString("+-*/()", currNode->getPayload()))
        {
            if(!operatorStack)
            {
                //Stack is empty
                popThenPushQtoS(inputQueue, operatorStack);
            }
        }
        else
        {
            //stack is not empty, time to compare
            int inputOp = convertOpToInt(currNode->getPayload());
            int operatorOp = convertOpToInt(operatorStack->peek());
            if(inputOp >= operatorOp)
            {
                //input operator is greater or equal to top of op stack
                popThenPushStoQ(operatorStack, outputQueue);
                popThenPushQtoS(inputQueue, operatorStack);
            }
        }
        
    }
    
}


void ShuntingYardAlgorithm::popThenPushQtoQ(Queue  * q1, Queue * q2)
{
    q2->Enqueue(q1->Dequeue());
}