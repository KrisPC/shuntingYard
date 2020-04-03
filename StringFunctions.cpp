#include "StringFunctions.hpp"
using namespace std;

Queue * StringFunctions::splitString(string s, string delims)
{
    Queue * q = new Queue();
    char* fullChar = StringFunctions::stringToCharArray(s);
    char *fullChar2 = StringFunctions::stringToCharArray(s);
    char* delimsChar = StringFunctions::stringToCharArray(delims);
    char * tokenizer;
    char * delimTokens;
    string firstTester = string(1,fullChar[0]);
    bool toggle = false;
    std::size_t found = firstTester.find_first_of(delims);

    tokenizer = strtok (fullChar,delimsChar);
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
    
       return q;
}

char * StringFunctions::stringToCharArray(string s)
{

    char * cstr = new char [s.length()+1];
    strcpy (cstr, s.c_str());




    return  cstr;
}

bool StringFunctions::isInString(string searchString, string charToFind)
{
    for(int i = 0; i <searchString.length(); i++)
    {
        if( string (1, searchString[i]) == charToFind)
        {
            return 1;
        }
    }
}