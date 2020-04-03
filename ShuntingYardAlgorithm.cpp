#include "ShuntingYardAlgorithm.hpp"

    Queue * ShuntingYardAlgorithm::performAlgorithm(Queue * inputQueue)
    {
        Queue * outputQueue = new Queue();
        Stack * operatorStack = new Stack();
        Node * currNode = inputQueue->peek();
        //While there is an input queue
        while(inputQueue->peek())
        {
            cout<<"Running main loop on num:" << inputQueue->peek()->getPayload()<< "\n";
            if(! StringFunctions::isInString("+/-*()",currNode->getPayload()))
            {
                cout<<"This is a num" <<"\n";
                cout<<"output Queue: ";
                popThenPushQtoQ(inputQueue,outputQueue);
            } 
            else if(StringFunctions::isInString("+/-*",currNode->getPayload()))
            {
                cout <<"This is an op, not a () Top of op stack is: "<< operatorStack->peek()<<"\n";
                if(operatorStack->peek() == string(""))
                {
                    cout<<"Stack is empty"<<"\n";
                    cout<<"operator stack: ";
                    popThenPushQtoS(inputQueue,operatorStack);
                }
                else
                {
                    cout<<"Operator stack is not empty, time to do math"<<"\n";
                    int inputOp = convertOpToInt(currNode->getPayload());
                    int operatorOp = convertOpToInt(operatorStack->peek());
                    if(inputOp < operatorOp)
                    {
                        //input operator is less than to top of op stack
                        // while(operatorStack->peek()!= string(""))
                        // {
                        //     popThenPushStoQ(operatorStack,outputQueue);
                        // }
                        // popThenPushQtoS(inputQueue,operatorStack);
                                            
                        cout<<"Output queue: ";
                        popThenPushStoQ(operatorStack,outputQueue);
                        cout<<"Operator stack: ";
                        popThenPushQtoS(inputQueue,operatorStack);
                    }
                    else if(inputOp == operatorOp)
                    {
                        cout<<"Output queue: ";
                        popThenPushStoQ(operatorStack,outputQueue);
                        cout<<"Operator stack: ";
                        popThenPushQtoS(inputQueue,operatorStack);
                    }
                    else
                    {
                        cout<<"operator stack: ";
                        popThenPushQtoS(inputQueue, operatorStack);
                    }
                }
                
            }
            else
            {
                cout<<"looking at either ( or )" <<"\n";
                if(inputQueue->peek()->getPayload() == string("("))
                {
                    cout<<"Looking at '(' "<<"\n";
                    popThenPushQtoS(inputQueue,operatorStack);
                    
                }
                else if(inputQueue->peek()->getPayload() == string(")"))
                {
                    cout<<"Looking at ') "<<"\n";
                    while(operatorStack->peek() != string("("))
                    {
                        cout<<"running "<<"\n";
                        popThenPushStoQ(operatorStack,outputQueue);
                    }
                    operatorStack->pop();
                    inputQueue->Dequeue();
                
                }
            }
            currNode=currNode->getNextNode();
        }
        while(operatorStack->peek()!= string(""))
        {
                popThenPushStoQ(operatorStack,outputQueue);
        }
        return outputQueue;
    }

    void ShuntingYardAlgorithm::popThenPushQtoQ(Queue * q1, Queue *  q2)
    {
        q2->Enqueue(q1->Dequeue());
        q2->display();
        cout<<"\n";
    }

    void ShuntingYardAlgorithm::popThenPushQtoS(Queue * q1, Stack *  s1)
    {
        s1->push(q1->Dequeue());
        s1->display();
        cout<<"\n";
    }

    void ShuntingYardAlgorithm::popThenPushStoQ(Stack * s1, Queue * q1)
    {
        q1->Enqueue(s1->pop());
        q1->display();
        cout<<"\n";
    }

    int ShuntingYardAlgorithm::convertOpToInt(string s)
    {
        cout<<"convert op to int is running" <<"\n";
        if(s == string(1,'*') || s == string(1,'/'))
        {
            //cout<<s<<3<<"n";
            return 3;
        }
        else if(s == string(1,'+') || s == string(1,'-'))
        {
            //cout<<s<<2<<"n";
            return 2;
        }
        else
        {
            //cout<<s<<"error"<<"n";
            return 0;
        }
    }