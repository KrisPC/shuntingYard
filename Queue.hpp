#ifndef Queue_hpp
#define Queue_hpp

#include "Node.hpp"
using namespace std;

class Queue
{

    public:
        Queue();
        void Enqueue(string s);
        string Dequeue();
        int count;
        void display();
        Node * peek();
        void fancyDisplay();


    private:
        Node * head;
        

};

#endif