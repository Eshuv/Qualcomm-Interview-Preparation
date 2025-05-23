#include<iostream>
using namespace std;

int evenBitsToZeroO1(int num)
{
    return (num & 0xAAAAAAAA);
}

int evenBitsToZeroOn(int num)
{
    
}

int main()
{
    int num = 30;

    cout << evenBitsToZeroO1(num) << endl;
}