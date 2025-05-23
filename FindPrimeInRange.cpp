#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

bool isPrime(int num) {
    if (num <= 1)
        return false;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0)
            return false;
    }
    return true;
}

// Function to print all primes in a given range [low, high]
void printPrimesInRange(int low, int high) {
    for (int i = low; i <= high; i++) {
        if (isPrime(i)) {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main()
{
    int low = 0;
    int high = 10000000;

    printPrimesInRange(low , high);
}