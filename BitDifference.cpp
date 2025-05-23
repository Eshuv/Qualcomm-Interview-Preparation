#include <iostream>
using namespace std;

int bitDiffernece(int a, int b)
{
    int res = a^b;
    int count = 0;
    while(res)
    {
        res = res & (res-1);
        count++;
    }
    return count;
}

int main()
{
    int a = 10;
    int b = 20;

    cout << bitDiffernece(a, b) << endl;
}