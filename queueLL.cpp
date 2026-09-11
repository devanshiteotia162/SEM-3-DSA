#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
};
class Queue {
    private:
        Node* front;
        Node* rear;
        public:
        Queue(){
            front = NULL;
            rear = NULL;
        }
        bool isEmpty(){
            return front == NULL;
        }
        void enqueue(int val){
            Node* newNode = new Node(val);
            if (isEmpty()){
                front = newNode;
                rear = newNode;
            }
            else {
                rear->next = newNode;
                rear = newNode;
            }
            cout << "Inserted : "<< val << endl;
        }
        void dequeue(){
            if (isEmpty()){
                cout << "Empty"<< endl;
                return;
            }
            Node* temp = front;
            cout<< "Deleted :"<< front -> data << endl;
            front = front -> next ;
            if (front == NULL)
            rear = NULL;
            delete temp;
        }
        void Peek(){
            if (isEmpty()){
                cout<<"Empty "<< endl;
                return ;
            }
            cout << "Front element  : "<< front -> data << endl; 
        }
        void display(){
            if (isEmpty()){
                cout<< "Empty"<< endl;
                return;
            }
            Node* temp = front ;
            cout<<"Elements : ";
            while (temp != NULL){
                cout<< temp -> data << " ";
                temp = temp -> next ;
            }
            cout << endl;
        }
};
int main (){
    Queue q;
    int choice ; int value;
    do{
        cin>> choice ;
        switch (choice ){
            case 1:
            cin >> value ;
            q.enqueue(value);
            break;
            case 2:
            q.dequeue ();
            break;
            case 3:
            q.Peek();
            break;
            case 4:
            q.display();
            break;
            case 5:
            cout <<"Exit "<< endl;
            break ;
            default :
            cout<< "Invalid choice "<< endl;


        }
    }
    while (choice != 5);
    
}

