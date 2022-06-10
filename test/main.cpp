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
        __gnu_cxx::__normal_iterator<int *, vector<int, allocator<int>>> ElementsPosition;
        for (int j = 0; j < Numbers.size(); j++)
        {
            if (Elements < Numbers.at(j))
            {
                ElementsPosition = Numbers.begin() + j;
                break;
            }
            else
            {
                ElementsPosition = Numbers.end();
            }
        }
        Numbers.insert(ElementsPosition, Elements);
    }
    for (int i : Numbers)
    {
        cout << i << ", ";
    }
}