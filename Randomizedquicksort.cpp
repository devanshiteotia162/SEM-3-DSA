#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int partition(vector<int>& arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++)
    {
        if(arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);

    return i + 1;
}

int random_partition(vector<int>& arr, int low, int high)
{
    int r = low + rand() % (high - low + 1);

    swap(arr[r], arr[high]);

    return partition(arr, low, high);
}

void Randomized_QuickSort(vector<int>& arr, int low, int high)
{
    if(low >= high)
        return;

    int pivotIdx = random_partition(arr, low, high);

    Randomized_QuickSort(arr, low, pivotIdx - 1);
    Randomized_QuickSort(arr, pivotIdx + 1, high);
}

int main()
{
    int n;

    cout << "Enter the no of elements: ";
    cin >> n;

    vector<int> arr(n);

    for(int i = 0; i < n; i++)
    {
        cout << "Enter element: ";
        cin >> arr[i];
    }

    Randomized_QuickSort(arr, 0, n - 1);

    cout << "The Sorted Array is: ";

    for(int x : arr)
    {
        cout << x << " ";
    }

    return 0;
}