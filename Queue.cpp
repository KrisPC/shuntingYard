#include "Queue.hpp"


Queue::Queue()
{
    this->head = 0;
    this->count = 0;
}

void Queue::Enqueue(string payload)
{
    Node * n = new Node(payload);
    if(!this->head)
    {
        this->head = n;
    }
    else
    {
        //run to end of the list
        Node* currNode = this->head;
        while(currNode->getNextNode())
        {
            currNode=currNode->getNextNode();
        }
        currNode->setNextNode(n);
    }
    this->count ++;
    
}

string Queue::Dequeue()
{
    if(this->count ==0)
    {
        return "Empty Queue, can't remove";
    }
    else if(this->count==1)
    {
        string temp = head->getPayload();
        this->head = 0;
        this->count=0;
        return temp;
    }

    else
    {
        string returnVal = this->head->getPayload();
        this->head = this->head->getNextNode();
        return returnVal;
    }
    
    
}

void Queue::display()
{
    Node * currNode = this->head;
    while(currNode->getNextNode())
    {
        cout << currNode->getPayload()<<", ";
        currNode = currNode->getNextNode();
    }
    cout << currNode->getPayload();
    cout<<"\n";
}

void Queue::fancyDisplay()
{
    Node * currNode = this->head;
    while(currNode->getNextNode())
    {
        cout << currNode->getPayload()<<", ";
        currNode = currNode->getNextNode();
    }
    cout << currNode->getPayload();
    cout<<"\n";
}


Node * Queue::peek()
{
    if(this->head)
    {
        return this->head;
    }
    else return 0;
}