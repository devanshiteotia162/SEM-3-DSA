#include<iostream>
using namespace std;
class CircularQueue{
    private:
    int *arr;
    int front ;
    int rear;
    int size;
    public:
    CircularQueue(int n){
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;

    }
    bool isfull(){
        return (rear+1)%size == front ;
    }
    bool isempty(){
        return front == -1;
    }
   void enqueue(int n){
    if(isfull()){
        cout<<"Overflow"<<endl;
        return ;
    }
    if(isempty()){
        front = 0; rear = 0;

    }else {
        rear = (rear +1)%size ;
    }
    arr [rear] = n;
    cout<< "Value inserted : "<< n << endl;

 }
 void dequeue (){
    if (isempty()){
        cout<<"Empty "<< endl;
        return ;
    }
    cout<< "Value deleted is : "<< arr[front] << endl;
    if (front == rear ){
        front = -1;
        rear = -1;
    }else {
        front = (front + 1) % size;
    }
 }
void Peek(){
    if (isempty()){
        cout<< "Empty "<<endl;
        return ;
    }
    cout<< arr[front] << endl;
}
void display (){
    if (isempty()){
        cout<<"Empty "<< endl;
        return ;
    }
    int i = front ;
    while (true ){
        cout<< arr[i] << " ";
        if (i == rear )
        break ;
        i = (i+1)%size ;
    }
    cout << endl;
}
CircularQueue (){
delete [] arr;

}
};
int main (){
    int n;
    cin >> n;
    CircularQueue q(n);
    int choice , val;
    do{
        cin>> choice ;
       switch (choice){
        case 1:
        cin>> val;
        q.enqueue(val);
        break;
        case 2:
        q.dequeue();
        break;
        case 3:
        q.Peek();
        break;
        case 4:
        q.display();
        break;  
        default:
        cout<<"Invaild "<< endl;
       } 
    }
    while (choice != 5);
}