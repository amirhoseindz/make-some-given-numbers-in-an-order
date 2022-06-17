#include <iostream>
#include <vector>
using namespace std;
vector <int> MakeNumbersInOrder(vector <int> Numbers)
{
    int temp;
    for (int i = 0; i < Numbers.size(); i++)
    {
        for (int j = i; j < Numbers.size(); j++)
        {
            if (Numbers.at(i) > Numbers.at(j))
            {
                temp = Numbers.at(i);
                Numbers.at(i) = Numbers.at(j);
                Numbers.at(j) = temp;
            }
        }
    }
    return Numbers;
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
    vector <int> Numbers;
    cout << " pleas enter the numbers you want to get in a order : " << endl;
    for(int i = 0; i < VectorSize; i++)
    {
        int Elements;
        cin >> Elements;
        __gnu_cxx::__normal_iterator<int *, vector<int, allocator<int>>> ElementsPosition =  Numbers.end();
        for (int j = 0; j < Numbers.size(); j++)
        {
            if (Elements < Numbers.at(j))
            {
                ElementsPosition = Numbers.begin() + j;
                break;
            }
        }
        Numbers.insert(ElementsPosition, Elements);
    }
    int TargetNumber;
    cout << "pleas enter a number to chek if it exist in the list : " << endl;
    cin >> TargetNumber;
    int IndexNumber;
    int TempMiddleIndex = Numbers.size() / 2;
    int MiddleIndex = TempMiddleIndex;
    if (TryFindIndex(Numbers, TempMiddleIndex, MiddleIndex, TargetNumber, IndexNumber))
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
    for (int i : Numbers)
    {
        cout << i << ", ";
    }
}