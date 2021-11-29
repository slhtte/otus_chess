#ifndef _TESTER_
#define _TESTER_

#include "FigureSteps.h"
#include <ctime>

class Tester
{
private:
    ITask *task;
    std::string path;
    
    std::vector<std::string> expect;
    std::vector<std::string> actual;
    
    bool RunTest(std::ifstream &inFile, std::ifstream &outFile);

public:
    Tester(ITask *task, std::string path);
    void RunTests();
};

#endif