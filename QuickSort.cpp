#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int> &vec, int start, int end)
{
    int pivot = vec[end];
    int idx = start-1;

    for(int i = start; i < end; i++)
    {
        if(vec[i] <= pivot)
        {
            idx++;
            swap(vec[i], vec[idx]);
        }
    }
    idx++;
    swap(vec[end], vec[idx]);
    return idx;
}

void quickSort(vector<int> &vec, int start, int end)
{
    if(start < end)
    {
        int pivotIdx = partition(vec, start, end);

        quickSort(vec, start, pivotIdx-1);
        quickSort(vec, pivotIdx+1, end);
    }
}

int main()
{
    vector<int> vec = {9,8,7,6,5,4,3,2,1};

    quickSort(vec, 0, vec.size() - 1);

    for(int val : vec)
    {
        cout << val << " ";
    }
    cout << endl;
}