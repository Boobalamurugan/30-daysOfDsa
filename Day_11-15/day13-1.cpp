//Implement a Queue using an array

#include <bits/stdc++.h>
using namespace std;

class Queue{
    int* arr;
    int front ,rear,size;
    public:
    Queue(int x){
        size=x;
        arr=new int[size];
        front=0;
        rear=-1;
    } 
    bool enqueue(int data){
        if(rear==size-1){
            cout<<"Queue is full";
            return false;
        }
        rear++;
        arr[rear]=data;
        cout<<"Element is added: "<<data<<endl;
        return true;
    }

    bool dequeue(){
        if(front>rear){
            cout<<"Queue is {}";
            return false;
        }
        else{
            cout<<"Element removed: "<<arr[front]<<endl;
            front++;
            return true;
        }
    }

    void display();
    
};
void Queue::display(){
        if(front>rear){
            cout<<"Queue is {}";
            return;
        }
        else{
            cout<<"Queue elements: "<<endl;
            for(int i=front;i<=rear;i++){
                cout<<arr[i]<<" ";
            }cout<<endl;
        }
}

int main(){
    Queue que(5);
    que.enqueue(4);
    que.enqueue(8);
    que.dequeue();
    que.enqueue(9);
    que.enqueue(0);
    que.dequeue();
    que.display();
}