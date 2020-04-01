
#include "Queue.hpp"

class StringFactory
{
    private:

    public:
        static Queue * split(string s, string delims);
        static char * stringToCharArray(string s);
}; 