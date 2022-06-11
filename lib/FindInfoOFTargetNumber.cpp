#include "../include/FindInfoOFTargetNumber.h"
FindInfoOFTargetNumber :: FindInfoOFTargetNumber (vector <int> Nums, int TargetNum)
{
    Numbers = std::move(Nums);
    TargetNumber = TargetNum;
}
bool FindInfoOFTargetNumber :: FindExistenceNumber()
{
    for (int Number : Numbers)
    {
        if (TargetNumber == Number)
            return true;
    }
    return false;
}
int FindInfoOFTargetNumber :: FindIndexOfNumber()
{
    for (int i = 0; i < Numbers.size(); i++)
    {
        if (TargetNumber == Numbers.at(i))
            return i;
    }
    return 0;
}
int FindInfoOFTargetNumber :: FindFrequencyOfNumber()
{
    for (int Number : Numbers)
    {
        if (TargetNumber == Number)
            count += 1;
    }
    return count;
}