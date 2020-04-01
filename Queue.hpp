#include<iostream>
using namespace std;
#include "Node.hpp"

class Queue
{

    private:
        Node * head;
        

    public:
        Queue();
        void Enqueue(string payload);
        int count;
        string Dequeue();
        void display();

};