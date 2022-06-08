#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int VectorSize;
    cout << "pleas type how many numbers you wanna put : " << endl;
    cin >> VectorSize;
    vector <int> Numbers;
    cout << " pleas enter the numbers you want to get in a order : " << endl;
    int temp;
    for(int i = 0; i < VectorSize; i ++)
    {
        int Elements;
        cin >> Elements;
        Numbers.push_back(Elements);
        for (int j = 0; j < Numbers.size(); j++)
        {
            if (Numbers.at(i) > Numbers.at(j))
            {
                temp = Numbers.at(i);
                Numbers.at(i) = Numbers.at(j);
                Numbers.at(j) = temp;
            }
        }
    }
    for (int i : Numbers)
    {
        cout << i << ", ";
    }
}