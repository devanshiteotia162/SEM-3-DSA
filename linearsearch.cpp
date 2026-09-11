#include <iostream>
using namespace std;

int linearsearch(int arr[], int n, int key, int index) {
    if (index == n)
        return -1;
    if (arr[index] == key)
        return index;
    return linearsearch(arr, n, key, index + 1);
}

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int n = 5;
    int key = 0;

    cout << "Enter the key to search: ";
    cin >> key;

    int result = linearsearch(arr, n, key, 0);

    if (result == -1)
        cout << "Element not found" << endl;
    else
        cout << "Element found at index " << result << endl;

    return 0;
}