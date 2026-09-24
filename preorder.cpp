#include<iostream>
using namespace std;
void preorder(int arr[],int n,int i){
    if(i>=n || arr[i]==-1)
    return;
    cout<<arr[i]<<" ";
    preorder(arr,n,2*i+1);
    preorder(arr,n,2*i+2);
}
void inorder(int arr[],int n,int i){
    if(i>=n || arr[i]==-1)
    return;
    inorder(arr,n,2*i+1);
    cout<<arr[i]<<" ";
    inorder(arr,n,2*i+2);
}
void postorder(int arr[],int n,int i){
    if(i>=n || arr[i]==-1)
    return;
    postorder(arr,n,2*i+1);
    postorder(arr,n,2*i+2);
    cout<<arr[i]<<" ";
}
int main(){
    int arr[]={10,20,30,-1,40,50,-1};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"Preorder: ";
    preorder(arr,n,0);
    cout<<"\nInorder: ";
    inorder(arr,n,0);
    cout<<"\nPostorder: ";
    postorder(arr,n,0);
}