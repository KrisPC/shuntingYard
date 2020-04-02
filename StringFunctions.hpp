#include <string>
#include "Queue.hpp"


class StringFunctions
{
    private:
        static bool isInString(string searchString, char charToFind);

     

    public:
        static Queue * splitString(string s, string delims);
        static char * stringToCharArray(string s);


       
};