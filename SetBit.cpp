#include <iostream>
using namespace std;

int setBit(int num, int pos)
{
    return (num | (1 << (pos-1)));
}

int main()
{
    int num = 30;

    cout << setBit(num , 6) << endl;
}