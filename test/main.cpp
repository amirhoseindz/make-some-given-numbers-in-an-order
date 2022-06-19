#include <iostream>
#include <vector>
using namespace std;
vector <int> MakeNumbersInOrder(vector <int> VectorNumbers)
{
    int temp;
    for (int i = 0; i < VectorNumbers.size(); i++)
    {
        for (int j = i; j < VectorNumbers.size(); j++)
        {
            if (VectorNumbers.at(i) > VectorNumbers.at(j))
            {
                temp = VectorNumbers.at(i);
                VectorNumbers.at(i) = VectorNumbers.at(j);
                VectorNumbers.at(j) = temp;
            }
        }
    }
    return VectorNumbers;
}
vector <int> MakeNumbersInOrderUsingInsert(const vector <int>& Numbers)
{
    vector <int> NumbersInOrder;
    for(int Number : Numbers)
    {
        __gnu_cxx::__normal_iterator<int *, vector<int, allocator<int>>> ElementsPosition =  NumbersInOrder.end();
        for (int j = 0; j < NumbersInOrder.size(); j++)
        {
            if (Number < NumbersInOrder.at(j))
            {
                ElementsPosition = NumbersInOrder.begin() + j;
                break;
            }
        }
        NumbersInOrder.insert(ElementsPosition, Number);
    }
    return NumbersInOrder;
}
bool TryFindIndex(vector <int> Numbers,int TempMiddleIndex, int MiddleIndex,  int TargetNumber, int &IndexNum)
{
    if ((MiddleIndex < 0) || (MiddleIndex == Numbers.size()))
    {
        return false;
    }
    else
    {
        if ( TargetNumber > Numbers.at(MiddleIndex) )
        {
            TempMiddleIndex = TempMiddleIndex/ 2;
            MiddleIndex = MiddleIndex + TempMiddleIndex;
            if (TempMiddleIndex < 1)
            {
                return TryFindIndex(Numbers, TempMiddleIndex, MiddleIndex + 1 , TargetNumber, IndexNum);
            }
            else
            {
                return TryFindIndex(Numbers, TempMiddleIndex, MiddleIndex, TargetNumber, IndexNum);
            }
        }
        else if ( TargetNumber < Numbers.at(MiddleIndex) )
        {
            TempMiddleIndex = TempMiddleIndex/ 2;
            MiddleIndex = MiddleIndex - TempMiddleIndex;
            if (TempMiddleIndex < 1)
            {
                return TryFindIndex(Numbers, TempMiddleIndex, MiddleIndex -1 , TargetNumber, IndexNum);
            }
            else
            {
                return TryFindIndex(Numbers, TempMiddleIndex, MiddleIndex, TargetNumber, IndexNum);
            }
        }
        else if (TargetNumber == Numbers.at(MiddleIndex))
        {
            IndexNum = MiddleIndex;
            return true;
        }
    }
    return false;
}
int FindFrequencyOfNumber(const vector <int>& Numbers, int TargetNumber)
{
    int count = 0;
    for (int Number : Numbers)
    {
        if (TargetNumber == Number)
            count += 1;
    }
    return count;
}
int main()
{
    int VectorSize;
    cout << "pleas type how many numbers you wanna put : " << endl;
    cin >> VectorSize;
    vector <int> Numbers(VectorSize);
    cout << " pleas enter the numbers you want to get in a order : " << endl;
    for(auto& Elements : Numbers)
    {
        cin >> Elements;
    }
    vector <int> NumbersInOrder = MakeNumbersInOrderUsingInsert(Numbers);
    int TargetNumber;
    cout << "pleas enter a number to chek if it exist in the list : " << endl;
    cin >> TargetNumber;
    int IndexNumber;
    int TempMiddleIndex = Numbers.size() / 2;
    int MiddleIndex = TempMiddleIndex;
    if (TryFindIndex(NumbersInOrder, TempMiddleIndex, MiddleIndex, TargetNumber, IndexNumber))
    {
        cout << "the target number is on the list" << endl;
        cout << "and its index on the list is : " << IndexNumber << endl;
        int FrequencyOfNumber = FindFrequencyOfNumber(Numbers, TargetNumber);
        cout << "the target number appears on the list " << FrequencyOfNumber << " time(s)" << endl;
    }
    else
    {
        cout << "the target number is not on the list" << endl;
    }
    cout << "and the numbers on the list in order are : " << endl;
    for (int i : NumbersInOrder)
    {
        cout << i << ", ";
    }
}