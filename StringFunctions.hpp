#ifndef StringFunctions_hpp
#define StringFunctions_hpp

#include <string>
#include "Queue.hpp"


class StringFunctions
{
    private:
        

     

    public:
        static Queue * splitString(string s, string delims);
        static char * stringToCharArray(string s);
        static bool isInString(string searchString, string charToFind);

       
};

#endif