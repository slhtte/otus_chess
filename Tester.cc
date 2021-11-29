#include <fstream>
#include <vector>
#include <iostream>
#include "Tester.h"

Tester::Tester(ITask *task, std::string path)
{
    this->task = task;
    this->path = path;
}

void Tester::RunTests()
{
    int nr = 0;

    while (true)
    {
        std::string inFile_path = this->path +  "test." + std::to_string(nr) + ".in";
        std::string outFile_path = this->path +  "test." + std::to_string(nr) + ".out";
        std::ifstream inFile(inFile_path);
        std::ifstream outFile(outFile_path);
        
        if (!inFile || !outFile)
        {
            break;
        }

        unsigned int start_time = std::clock();
        bool result = RunTest(inFile, outFile);
        unsigned int end_time = std::clock();
        std::cout << "Test #" + std::to_string(nr) + (result ? " true," : " false,") << " " << "run time:" << end_time - start_time <<  std::endl;
        
        if (!result)
        {
            std::cout << "expect: " << expect[0] << " " << expect[1] << "\n"
                      << "result: " << actual[0] << " " << actual[1] << "\n";
        }
        
        expect.clear();
        actual.clear();
        nr++;
    }
}

bool Tester::RunTest(std::ifstream &inFile, std::ifstream &outFile)
{
    try
    {
        std::vector<std::string> data;
        while (!inFile.eof())
        {
            std::string s;
            inFile >> s;
            data.push_back(s);
        }

        while (!outFile.eof())
        {
            std::string s;
            outFile >> s;
            expect.push_back(s);
        }
        actual = task->Run(data);
        return (actual[0] == expect[0]) && (actual[1] == expect[1]);
    }
    catch(...)
    {
        std::cout << "Error!" << std::endl;
        return false;
    }
}