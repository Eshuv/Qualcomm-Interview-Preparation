#include <iostream>
using namespace std;

int swapNibble(int num)
{
    int right = (num & 0x0F);
    right = (right << 4);
    int left = (num & 0xF0);
    left = (left >> 4);

    return (left | right);
}

int main()
{
    int num = 30;

    cout << swapNibble(num) << endl;
}