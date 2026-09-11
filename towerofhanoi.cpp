#include<iostream>
using namespace std;
void TowerofHanoi(char source, char aux, char dest, int n){
    if(n==1){
        cout<<"Move disk 1 from "<<source<<" to "<<dest<<endl;
        return;
    }
    TowerofHanoi(source,dest,aux,n-1);
    cout<<"Move disk "<<n<<" from "<<source<<" to "<<dest<<endl;
    TowerofHanoi(aux,source,dest,n-1);
}
int main(){
    int n;
    cout<<"Enter the number of disks: ";
    cin>>n;
    TowerofHanoi('A','B','C',n);
    return 0;
}