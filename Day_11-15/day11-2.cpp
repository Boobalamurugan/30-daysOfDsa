// Implement a Stack using a Linked List

#include <bits/stdc++.h>
using namespace std;

class Stack{
    public: 
    int data;
    Stack* next;

    Stack(int x){
        data=x;
        next=nullptr;
    }
};

void push(Stack*& head,int data){
    Stack* nn=new Stack(data);
    nn->next=head;
    head=nn;
}

void pop(Stack*& head){
    if(head==nullptr){
        cout<<"empty"<<endl;
        return;
    }
    if(head->next==nullptr){
        delete head;
        head=nullptr;
        return;
    }
    else{
        Stack* temp=head;
        head=head->next;
        delete temp;
    }
}

void peek(Stack*& head){
    cout<<"peek is "<<head->data<<endl;
}

void display(Stack*& head){
    if(head==nullptr){
        cout<<"{}"<<endl;
        return;
    }
    else{
        Stack* temp=head;
        while(temp!=nullptr){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
}

bool isEmpty(Stack*& head){
    if(head==nullptr) return true;
    else return false;
}

int main(){
    Stack* stack_container=nullptr;
    push(stack_container,1);
    push(stack_container,2);
    push(stack_container,3);
    push(stack_container,4);
    pop(stack_container);
    display(stack_container);
    peek(stack_container);
    cout<<"isEmpty "<<isEmpty(stack_container)<<endl;
    
}