#include <iostream>
#include <vector>
using namespace std;

void sort0s1s2s(vector<int> &vec)
{
    int sz = vec.size();
    int low = 0;
    int mid = 0;
    int high = sz-1;

    while(mid <= high)
    {
        if(vec[mid] == 0)
        {
            swap(vec[low++], vec[mid++]);
        }
        else if(vec[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(vec[mid], vec[high--]);
        }
    }
}

int main()
{
    vector<int> vec = { 0, 1, 2, 0, 1, 2 };
    int sz = vec.size();
    
    sort0s1s2s(vec);

    for(int i = 0; i < sz; i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}