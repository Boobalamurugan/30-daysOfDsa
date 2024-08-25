#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

    Node(int val){
        data=val;
        next=nullptr;
    }
};

class Linkedlist{
    public:
        Node* head;

    public:
        Linkedlist(){
            head=nullptr;
        }
    
    void append(int val){
        Node* nn=new Node(val);
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

    void display(){
        Node* temp =head;
        if(temp==nullptr){
            cout<<"{}"<<endl;
            return;
        }
        else{
            int count=0;
            while(temp!=nullptr && count<15){
                cout<<temp->data<<" ";
                temp=temp->next;  
                count++;       
            }
            cout<<"-->"<<endl;

        }
    }

    void createloopedLL(){
        if(head==nullptr || head->next==nullptr){
            cout<<"Cannot create loop LL";
            return;
        }
        Node* temp=head;
        Node* secondNode=temp->next;
        while(temp->next!=nullptr){
            temp=temp->next;
        }
        temp->next=secondNode;
    }

};

bool detect_loop_hashMethod(Node* head){
    if(head==nullptr||head->next==nullptr){
        return false;
    }
    unordered_map<Node*,int> mpp;
    Node* temp=head;
    while(temp!=nullptr)
    {if(mpp.find(temp)!=mpp.end()){
        return true;
    }
    mpp[temp]=1;
    temp=temp->next;
    }
    return false;
}

bool detect_loop_optimal(Node* head){
    if(head==nullptr||head->next==nullptr){
        return false;
    }
    Node* slow=head;
    Node* fast=head;

    while(fast->next!=nullptr && fast!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            return true;
        }
    }
    return false;

}
    

int main(){
    Linkedlist list;
    Linkedlist list1;
    
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);

    list1.append(1);
    list1.append(2);
    list1.append(3);
    list1.append(4);
    
    
    cout<<"Looped Linkedlist using class: ";
    list.createloopedLL();
    list.display();

   if(detect_loop_hashMethod(list.head)) cout<<"Detect a loop in a Linked List"<<endl;
   else cout<<"Not Detect a loop in a Linked List"<<endl;

   if(detect_loop_optimal(list.head)) cout<<"Detect a loop in a Linked List"<<endl;
   else cout<<"Not Detect a loop in a Linked List"<<endl;

}