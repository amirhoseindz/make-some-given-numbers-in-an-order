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
    int VectorSize = 10;
    vector <int> Numbers(VectorSize);
    cout << " pleas enter the numbers you want to get in a order : " << endl;
    for(auto& Elements : Numbers)
    {
        cin >> Elements;
    }
    vector <int> NumbersInOrder = MakeNumbersInOrder(Numbers);
    for (int i : NumbersInOrder)
    {
        cout << i << ", ";
    }
}