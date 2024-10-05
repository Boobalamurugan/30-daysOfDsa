//Implement a Queue using an LinkedList

#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int x){
            data=x;
            next=nullptr;
        }
};

void enqueue(Node*& head,int data){
    Node* nn=new Node(data);
    if(head==nullptr){
        head=nn;
        return;
    }
    else{
        Node* temp=head;
        while(temp->next!=nullptr){
            temp=temp->next;
        }
        temp->next=nn;
    }
}

void dequeue(Node*& head){
    if(head==nullptr){
        cout<<"queue is empty"<<endl;
        return;
    }
    Node* temp=head;
    head=head->next;
    delete temp;
}

void display(Node* head){
    if(head==nullptr){
        cout<<"{}"<<endl;
        return;
    }
    else{
        Node* temp=head;
        while(temp!=nullptr){
            cout<<temp->data<<" ";
            temp=temp->next;
        }cout<<endl;
    }
}

int main(){
    Node* head=nullptr;
    enqueue(head,12);
    enqueue(head,2);
    enqueue(head,1);
    enqueue(head,3);
    dequeue(head);
    display(head);
}