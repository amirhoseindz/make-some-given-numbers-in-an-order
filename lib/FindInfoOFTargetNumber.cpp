#include "../include/FindInfoOFTargetNumber.h"
FindInfoOFTargetNumber :: FindInfoOFTargetNumber (vector <int> Nums, int TargetNum)
{
    Numbers = std::move(Nums);
    TargetNumber = TargetNum;
}
int FindInfoOFTargetNumber :: FindIndexOfNumber()
{
    for (int i = 0; i < Numbers.size(); i++)
    {
        if (TargetNumber == Numbers.at(i))
        {
            ListIncludingNumber = true;
            return i;
        }
    }
    return -1;
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