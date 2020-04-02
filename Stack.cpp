#include "Stack.hpp"

Stack::Stack()
{
    this->top = 0;
    this->count = 0;
}

void Stack::push(string s)
{
    Node * n = new Node(s);
    if(this->top)
    {
        n->setNextNode(this->top);
    }
    this->top = n;
    this->count ++;
}

string Stack::pop()
{
    if(this->top)
    {
        Node* temp = this->top;
        this->top = this->top->getNextNode();
        string returnVal = temp->getPayload();
        delete temp;
        return returnVal;
    }
    return 0;
}

string Stack::peek()
{
    return this->top->getPayload();
}

void Stack::display()
{
    Node * currNode = this->top;
    while(currNode)
    {
        cout<<currNode->getPayload();
        currNode = currNode->getNextNode();
    }
}