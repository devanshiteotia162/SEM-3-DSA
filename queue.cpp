#include <iostream>
using namespace std;
class Queue{
public :
int *arr;
int size;
int front;
int rear;
Queue(int n){
    size = n;
    arr = new int[size];
    front = -1;
    rear = -1;
}
bool isEmpty(){
    return front == -1;
}
bool isFull(){
    return rear == size -1;
}
void enqueue(int val){
    if (isFull()){
        cout << "Queue is full" << endl;
        return;
    }
    if (isEmpty()){
        front = 0;
    }
   arr[++rear] = val;
   cout <<" value inserted "<< val;
}
void dequeue(){
    if (isEmpty()){
        cout << "Queue is empty" << endl;
        return;
    }
    cout <<" deleted value is "<< arr[front];
    front++;
    if (front > rear){
        front = rear = -1;
    }
}
void peek(){
    if (isEmpty()){
        cout << "Queue is empty" << endl;
        return;
    }
    cout <<" front element is "<< arr[front];
}
void display(){
    if (isEmpty()){
        cout << "Queue is empty" << endl;
        return;     
    }
    cout <<" Queue elements are: ";
    for (int i = front; i <= rear; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
};

int main(){
    int n;
    cout <<"Enter the size of queue:";
    cin >> n;
    Queue q(n);
    int choice ;
    int val;
    do{
        cout << "1.Enqueue\n:";
        cout << "2.Dequeue\n:";
        cout << "3.Peek\n:";
        cout << "4.Display\n:";
        cout << "5.Exit\n:";
        cout << "Enter your choice:";
        cin >> choice;
        switch(choice){
            case 1: cout << "Enter the value to be inserted:";
            cin >> val;
            q.enqueue(val);
            break;
            case 2: q.dequeue();
            break;
            case 3: q.peek();
            break;
            case 4: q.display();
            break;
            case 5: cout << "Exiting the program";
            break;
            default: cout << "Invalid choice";

    }
    }while(choice != 5);
    return 0;
}
 