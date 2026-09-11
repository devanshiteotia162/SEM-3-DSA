#include <iostream>
using namespace std;
class Node{
    public:
        int data;
        int pr;
        Node *next; 
        Node(int val, int priority){                  //constructor
            data=val;
            pr=priority;
            next=NULL;
        }
};
class PriorityQueue{
    private:
        Node *front;
    public:                          //constructor
        PriorityQueue(){
            front=NULL;
        }
        bool isEmpty(){
            return front==NULL;
        }
        void enqueue(int val, int priority){
            Node *newNode=new Node(val, priority);
            if(isEmpty()){
                front=newNode;
            }
            else if(newNode->pr>front->pr){
                newNode->next=front;
                front=newNode;
            }
            else{
                    Node *temp=front;
                    while(temp->next!=NULL && temp->next->pr>=newNode->pr){
                        temp=temp->next;
                    }
                    newNode->next=temp->next;
                    temp->next=newNode;
                    }
                }
                void dequeue(){
                    if(isEmpty()){
                        cout<<"Underflow"<<endl;
                        return;
                    }
                    Node *temp=front;
                    front=front->next;
                    cout<<"The value is deleted"<<endl;
                    cout<<"The deleted priority is: "<<temp->pr<<endl;
                    delete temp;
                }
                void peek(){
                    if(isEmpty()){
                        cout<<"Underflow"<<endl;
                        return;
                    }
                    cout<<"The value is: "<<front->data<<endl;
                    cout<<"The priority is: "<<front->pr<<endl;
                }
                void display(){
                    if(isEmpty()){
                        cout<<"Underflow"<<endl;
                        return;
                    }
                    Node *temp=front;
                    while(temp!=NULL){
                        cout<<"The value is: "<<temp->data<<endl;
                        cout<<"The priority is: "<<temp->pr<<endl;
                        temp=temp->next;
                    }
                }
};
int main(){
    PriorityQueue pq;
    int choice, value, priority;
    while(1){
        cout<<"1. Enqueue"<<endl;
        cout<<"2. Dequeue"<<endl;
        cout<<"3. Peek"<<endl;
        cout<<"4. Display"<<endl;
        cout<<"5. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter the value: ";
                cin>>value;
                cout<<"Enter the priority: ";
                cin>>priority;
                pq.enqueue(value, priority);
                break;
            case 2:
                pq.dequeue();
                break;
            case 3:
                pq.peek();
                break;
            case 4:
                pq.display();
                break;
            case 5:
                exit(0);
            default:
                cout<<"Invalid choice"<<endl;
        }
    }
    return 0;
}
