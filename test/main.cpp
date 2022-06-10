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
bool FindNumber(vector <int> Numbers, int TargetNumber)
{
    for (int Number : Numbers)
    {
        if (TargetNumber == Number)
            return true;
    }
    return false;
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
    if (FindNumber(Numbers, TargetNumber))
    {
        cout << "the number is on the list" << endl;
    }
    else
    {
        cout << "the number is not on the list" << endl;
    }
    cout << "and the number on the list in order are : " << endl;
    for (int i : Numbers)
    {
        cout << i << ", ";
    }
}