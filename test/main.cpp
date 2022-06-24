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
vector <int> MakeNumbersInOrderUsingMergeSort(vector <int> Numbers, int SmallestNumbersIndex, int MiddleIndex, int BiggestNumbersIndex)
{
    int n1 = MiddleIndex - SmallestNumbersIndex + 1;
    int n2 = BiggestNumbersIndex - MiddleIndex;
    vector <int> FirstHalf;
    FirstHalf.reserve(n1);
    vector <int> SecondHalf;
    SecondHalf.reserve(n2);
    for (int i = 0; i < n1; i++)
    {
        FirstHalf.push_back(Numbers.at(SmallestNumbersIndex + i));
    }
    for (int i = 0; i < n1; i++)
    {
        SecondHalf.push_back(Numbers.at(MiddleIndex + 1 + i));
    }
    int i, j, k;
    i = 0;
    j = 0;
    k = SmallestNumbersIndex;
    while (i < n1 && j < n2)
    {
        if (FirstHalf.at(i) <= SecondHalf.at(j))
        {
            Numbers.at(k) = FirstHalf.at(i);
            i++;
        }
        else
        {
            Numbers.at(k) = SecondHalf.at(j);
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        Numbers.at(k) = FirstHalf.at(i);
        i++;
        k++;
    }
    while (j < n2)
    {
        Numbers.at(k) = SecondHalf.at(j);
        j++;
        k++;
    }
    return Numbers;
}
void DivideMainVectorToTwoVectors(const vector <int>& VectorNumbers, int FirstIndex, int LastIndex)
{
    if (FirstIndex < LastIndex)
    {
        int MiddleIndex =(LastIndex + FirstIndex) / 2;
        DivideMainVectorToTwoVectors(VectorNumbers, FirstIndex, MiddleIndex);
        DivideMainVectorToTwoVectors(VectorNumbers, MiddleIndex + 1, LastIndex);
        MakeNumbersInOrderUsingMergeSort(VectorNumbers, FirstIndex, MiddleIndex, LastIndex);
    }

}
bool TryFindIndex(vector <int> const& Numbers, int FirstIndex, int LastIndex, int TargetNumber, int &IndexNum)
{
    if (FirstIndex > LastIndex)
    {
        return false;
    }
    int MiddleIndex =(LastIndex + FirstIndex) / 2;
    if (TargetNumber > Numbers.at(MiddleIndex))
    {
        return TryFindIndex(Numbers, MiddleIndex + 1, LastIndex, TargetNumber, IndexNum);
    }
    else if ((TargetNumber < Numbers.at(MiddleIndex)))
    {
        return TryFindIndex(Numbers, FirstIndex, MiddleIndex - 1, TargetNumber, IndexNum);
    }
    IndexNum = MiddleIndex;
    return true;
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
    int TargetNumber;
    cout << "pleas enter a number to chek if it exist in the list : " << endl;
    cin >> TargetNumber;
    int IndexNumber;
    int FirstIndex = 0;
    int LastIndex = Numbers.size() - 1;
    DivideMainVectorToTwoVectors (Numbers, FirstIndex, LastIndex);
    vector <int> NumbersInOrder = MakeNumbersInOrderUsingInsert(Numbers);
    if (TryFindIndex(NumbersInOrder, FirstIndex, LastIndex, TargetNumber, IndexNumber))
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