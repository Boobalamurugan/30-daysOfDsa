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

class LinkedList{
    public:
    Node* head=nullptr;

    void append(int data){
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

    void display(){
        if(head==nullptr){
            cout<<"{}"<<endl;
            return;
        }
        else{
            Node* temp=head;
            while(temp!=nullptr){
                cout<<temp->data<<" ";
                temp=temp->next;
            }
            cout<<endl;
        }
    }

};

Node* intersectionOfTwoLL(Node*head1, Node* head2){
    Node* L1=head1;
    Node* L2=head2;
    Node* newHead=nullptr;
    Node* temp=nullptr;
    while(L2!=nullptr){
        L1=head1;
        while(L1!=nullptr){
            if(L1->data==L2->data){
                Node* newNode=new Node(L1->data);
                if(temp!=nullptr){
                    newHead=newNode;
                    temp=newHead;
                }
                else{
                    temp->next=temp;
                    temp=temp->next
                }
            }
        }
    }

     
}


int main(){
    cout<<"Intersection of two Linked Lists"<<endl;
    LinkedList list1;
    LinkedList list2;
    int arr1[]={1,2,5,6,4,3,2};
    for(auto i:arr1){
        list1.append(i);
    }
    

    int arr2[]={1,2,7,3,2,4,3,2};
    for(auto i:arr2){
        list2.append(i);
    }


    list1.display();
    list2.display();

    
    
}