#include "StringFactory.hpp"
#include <string.h>
using namespace std;

Queue * StringFactory::split(string s, string delims)
{
    Queue * q = new Queue();
    char* fullChar = StringFactory::stringToCharArray(s);
    char *fullChar2 = StringFactory::stringToCharArray(s);
    char* delimsChar = StringFactory::stringToCharArray(delims);
    char * tokenizer;
    char * delimTokens;
    std::cout<<delimsChar[0];
    string firstTester = string(1,fullChar[0]);
    std::cout<< firstTester;
    bool toggle = false;
    std::size_t found = firstTester.find_first_of(delims);

    tokenizer = strtok(fullChar,delimsChar);
    delimTokens = strpbrk(fullChar2,delimsChar);
    if( found != std::string::npos)
    {
        std::cout<<"running!";
        toggle = true;
    }

    while (tokenizer != 0 || delimTokens !=0)
    {
        if(tokenizer != 0 && delimTokens !=0)
        {
            if(toggle == true)
            {
                string thingToAdd =  string(1,delimTokens[0]);
                q->Enqueue(thingToAdd);
                delimTokens = strpbrk (delimTokens+1 , delimsChar);
                q->Enqueue(tokenizer);
                tokenizer = strtok (NULL, delimsChar);
            }
            else
            {
                string thingToAdd =  string(1,delimTokens[0]);
                q->Enqueue(tokenizer);
                tokenizer = strtok (NULL, delimsChar);
                q->Enqueue(thingToAdd);
                delimTokens = strpbrk (delimTokens+1 , delimsChar);
            }
        }
        else if (tokenizer!=0)
        {
            q->Enqueue(tokenizer);
            tokenizer = strtok (NULL, delimsChar);
        }
        else if (delimTokens != 0)
        {
            string thingToAdd =  string(1,delimTokens[0]);
            q->Enqueue(thingToAdd);
            delimTokens = strpbrk (delimTokens+1 , delimsChar);
        }
    }
       std::cout<<"\n"<<"\n";
       //ll->display();
       std::cout<<"\n"<<"\n";
       return q;
}

char * StringFactory::stringToCharArray(string s)
{
    char * cstr = new char [s.length()+1];
    strcpy (cstr, s.c_str());
    return  cstr;
}

