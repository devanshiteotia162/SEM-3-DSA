#include<iostream>
using namespace std ;
int binarysearch(int arr[] , int low , int high , int key){
    if (low > high)
    return -1;
    int mid = low + (high - low) / 2;
    if (arr[mid] == key)
    return mid;
    if(key < arr[mid])
    return binarysearch(arr, low, mid - 1, key);
    return binarysearch(arr, mid + 1, high, key);
}
int main (){
    int arr [] = {10,20,30,40,50,60,70,80,90};
    int target;
    cin >> target ;
    int result , low =0 , high =0;
    result = binarysearch(arr, low,high,target);
    if (result == -1)
    cout<< "Unsuccessful search ";
    else 
    cout<< "Target is found at position "<< result +1;
    return 0;

}