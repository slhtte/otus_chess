#ifndef _KINGSTEPS_
#define _KINGSTEPS_

#include "ITask.h"

class KingSteps : public ITask
{
    virtual std::vector<std::string> Run(std::vector<std::string> &data) override;
};

class HorseSteps : public ITask
{
    virtual std::vector<std::string> Run(std::vector<std::string> &data) override;
};

class CastleSteps : public ITask
{
    virtual std::vector<std::string> Run(std::vector<std::string> &data) override;
};

class BishopSteps : public ITask
{
    virtual std::vector<std::string> Run(std::vector<std::string> &data) override;
};

class QueenSteps : public ITask
{
    virtual std::vector<std::string> Run(std::vector<std::string> &data) override;
};

#endif