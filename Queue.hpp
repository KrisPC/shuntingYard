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


    private:
        Node * head;

};