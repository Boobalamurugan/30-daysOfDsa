#include <bits/stdc++.h>
using namespace std;

class Node{
    public :
        int data;
        Node* next;

        Node(int x){
            data=x;
            next=nullptr;
        }
};

void arr2CLL(int* arr,int n,Node*& last){
    if(n==0) return ;

    Node* head=new Node(arr[0]);
    Node* temp=head;
    last=head;

    for(int i=1;i<n;i++){
        Node* nn=new Node(arr[i]);
        temp->next=nn;
        temp=nn;
        last=nn;
    }

    last->next=head;
}

void deleteAtBegin(Node*& last){
    if(last==nullptr) return;
    
    if(last==last->next){
        delete last->next;
        last=nullptr;
        return;
    }

    Node* head=last->next;
    Node* temp=head->next;
    last->next=temp;
    delete head;
}

void deleteAtPos(Node*& last,int key){
    if(last==nullptr || key<=0) return ;

    Node* head = last->next;
    if(key==1){
        if(head==last){
            last=nullptr;
            return;
        }
        last->next=head->next;
        return;
    }

    Node* temp=last->next;
    Node* prev=last;

    for(int i=2;i<=key;i++){
        prev=temp;
        temp=temp->next;
    }
    if(temp==head){
        cout<<"OutOfRange"<<endl;
        return;
    }

    prev->next=temp->next;
    if(temp==last){
        last=prev;
    }
    delete temp;

}

void deleteAtEnd(Node*& last){
    if(last==nullptr) return;
    
    if(last->next==last){
        delete last;
        last=nullptr;
        return;
    }
    Node* head=last->next;
    Node* temp=head;
    Node* prev=nullptr;
    while(temp->next!=last){
        temp=temp->next;
    }
    prev=temp;
    prev->next=head;
    delete last;
    last=prev;
}

void display(Node* last){
    if(last==nullptr || last->next==nullptr) return;
    Node*head=last->next;
    Node* temp=head;

    while(1){
        cout<<temp->data<<" ";
        temp=temp->next;
        if(temp==head){
            break;
        }
    }
    cout<<endl;
}

int main(){
    int arr[]={1,2,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    Node* last=nullptr;
    arr2CLL(arr,n,last);
    display(last);
    deleteAtPos(last,3);
    display(last);
}