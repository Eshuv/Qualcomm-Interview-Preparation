#include <iostream>
using namespace std;

int strstr(string str, string target)
{
    int n = str.length();
    int m = target.length();

    if (m == 0) return 0; // Empty target

    for (int i = 0; i <= n - m; i++) // Only go up to n-m
    {
        int j = 0;
        for (; j < m; j++)
        {
            if (str[i + j] != target[j])
                break;
        }
        if (j == m)
            return i; // Found at index i
    }
    return -1; // Not found
}

int main()
{
    string str = "AbhayGautam";
    string target = "tam";

    cout << strstr(str, target) << endl;
}