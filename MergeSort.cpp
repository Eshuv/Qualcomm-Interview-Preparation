#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &vec, int start, int mid, int end)
{
    vector<int> temp;
    int i = start;
    int j = mid + 1;

    while(i <= mid && j <= end)
    {
        if(vec[i] <= vec[j])
        {
            temp.push_back(vec[i]);
            i++;
        }
        else
        {
            temp.push_back(vec[j]);
            j++;
        }
    }

    while(i <= mid)
    {
        temp.push_back(vec[i]);
        i++;
    }

    while(j <= end)
    {
        temp.push_back(vec[j]);
        j++;
    }

    for(int index = 0; index < temp.size(); index++)
    {
        vec[start + index] = temp[index];
    }
}

void mergeSort(vector<int> &vec, int start, int end)
{
    if(start < end)
    {
        int mid = (start + end) / 2;

        mergeSort(vec, start, mid);
        mergeSort(vec, mid + 1, end);

        merge(vec, start, mid, end);
    }
}

int main()
{
    vector<int> vec = {9,8,7,6,5,4,3,2,1};

    mergeSort(vec, 0, vec.size() - 1);

    for(int num : vec) cout << num << " ";
    cout << endl;
}
