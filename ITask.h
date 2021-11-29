#ifndef _ITASK_
#define _ITASK_

#include <string>
#include <vector>

class ITask
{
public:
    virtual std::vector<std::string> Run(std::vector<std::string> &data) { return {""}; };
    
    int popcnt(unsigned long int M) const
    {
        int result = 0;
        
        while (M > 0)
        {
            M &= M - 1;
            ++result;
        }
        
        return result;
    }
};

#endif