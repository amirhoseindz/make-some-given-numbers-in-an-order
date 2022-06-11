#ifndef MAKE_SOME_GIVEN_NUMBERS_IN_AN_ORDER_FINDINFOOFTARGETNUMBER_H
#define MAKE_SOME_GIVEN_NUMBERS_IN_AN_ORDER_FINDINFOOFTARGETNUMBER_H
#include <vector>
using namespace std;
class FindInfoOFTargetNumber
{
private :
    vector <int> Numbers;
    int TargetNumber;
public :
    FindInfoOFTargetNumber (vector <int> Nums, int TargetNum);
    bool FindExistenceNumber();
    int FindIndexOfNumber();
    int count = 0;
    int FindFrequencyOfNumber();
};
#endif
