#include "StringFunctions.hpp"
using namespace std;

Queue * StringFunctions::splitString(string s, string delims)
{
    //string s = "123+42-8*2";
    //string ops = "+-*/()";
    Queue* answerQ = new Queue();
    string temp;
    for(int i = 0; i < s.length(); i++)
    {
        if(isInString(delims, (string)+""+s[i]))
        {
            if(temp.length() >0)
            {
                answerQ->Enqueue(temp);
            }
            answerQ->Enqueue((string)"" + s[i]);
            temp = "";
        }
        else
        {
            temp = temp + s[i];
        }
    }
    answerQ->Enqueue(temp);
    return answerQ;
}


bool StringFunctions::isInString(string searchString, string charToFind)
{
    for(int i = 0; i <searchString.length(); i++)
    {
        if ( string(1, searchString[i]) == charToFind)
        {
            return 1;
        }
    }
}