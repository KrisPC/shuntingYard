#include "Node.hpp"
#include <string.h>

class LinkedList
{
    private:
        Node* head;
        

    public:
        LinkedList();
        int count;
        void addEnd(string payload);
        string* toStringArray();
        string get(int index);
        void display();
};