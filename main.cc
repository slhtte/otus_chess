#include "FigureSteps.h"
#include "Tester.h"
#include <iostream>

int main()
{
    std::cout << "Tests for King:\n";
    ITask *task = new KingSteps();
    Tester *tester = new Tester(task, "./King/");
    tester->RunTests();

    std::cout << "\nTests for Horse:\n";
    task = new HorseSteps();
    tester = new Tester(task, "./Horse/");
    tester->RunTests();

    std::cout << "\nTests for Castle:\n";
    task = new CastleSteps();
    tester = new Tester(task, "./Castle/");
    tester->RunTests();

    std::cout << "\nTests for Bishop:\n";
    task = new BishopSteps();
    tester = new Tester(task, "./Bishop/");
    tester->RunTests();

    std::cout << "\nTests for Queen:\n";
    task = new QueenSteps();
    tester = new Tester(task, "./Queen/");
    tester->RunTests();
}