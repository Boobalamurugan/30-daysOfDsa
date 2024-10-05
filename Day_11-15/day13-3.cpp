// Implement a Circular Queue

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

void enqueue(Node*& last,int data){
    Node* nn=new Node(data);
    if(last==nullptr){
        last=nn;
        nn->next=last;
        return;
    }
    else{
        Node* head=last->next;
        last->next=nn;
        nn->next=head;
        last=nn;
    }
}
void dequeue(Node*& last){
    if(last==nullptr){
        cout<<"Empty Queue"<<endl;
        return;
    }
    Node* head=last->next;
    if(head==last){
        last=nullptr;
        delete head;
        return;
    }
    last->next=head->next;
    delete head;
}

void display(Node* last){
    if(last==nullptr){
        cout<<"{}"<<endl;
        return;
    }
    else{
        Node* head=last->next;
        while(true){
            cout<<head->data<<" ";
            head=head->next;
            if(head==last->next) break;
        }cout<<endl;
    }
}
    
int main(){
    Node* last=nullptr;
    enqueue(last,1);
    enqueue(last,2);
    enqueue(last,5);
    enqueue(last,3);
    dequeue(last);
    dequeue(last);
    dequeue(last);
    display(last);
}