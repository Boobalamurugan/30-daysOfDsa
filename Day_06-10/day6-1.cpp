#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* link;
};

void append(Node*& head,int data){
    Node* nn=new Node;
    nn->data=data;
    nn->link=nullptr;
    if(head==nullptr){
        head=nn;
        return;
    }
    else{
        Node* temp=head;
        while(temp->link!=nullptr){
            temp=temp->link;
        }
        temp->link=nn;
    } 
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
            temp=temp->link;
        }cout<<endl;
    }
}

Node* reveser_using_stack(Node* head){
    stack<Node*> nodeStack;
    Node*temp=head;
    while(temp!=nullptr){
        nodeStack.push(temp);
        temp=temp->link;
    }
    head=nodeStack.top();
    nodeStack.pop();
    temp=head;
    while(!nodeStack.empty()){
        temp->link=nodeStack.top();
        nodeStack.pop();
        temp=temp->link;
    }
    temp->link=nullptr;
    return head;
}

Node* reveser_optimal(Node* head){
    Node* current=head;
    Node* next=nullptr;
    Node* prev=nullptr;

    while(current!=nullptr){
        next=current->link;
        current->link=prev;
        prev=current;
        current=next;
    }

    return prev;
}

Node* reveser_recursion(Node *head){
    if(head==nullptr || head->link==nullptr){
        return head;
    }
    Node* nn=reveser_recursion(head->link);
    Node* front=head->link;
    front->link=head;
    head->link=nullptr;
    return nn;
}





int main(){
    Node* head=nullptr;
    append(head,1);
    append(head,2);
    append(head,3);
    append(head,4);

    cout<<"LinkedList: ";
    display(head);

    Node* rev=reveser_optimal(head);
    cout<<"ReveserLinkedList: ";
    display(rev);

    Node* Stackrev=reveser_using_stack(rev);
    cout<<"ReveserLinkedList using Stack: ";
    display(Stackrev);

    Node* revRecursion=reveser_recursion(Stackrev);
    cout<<"ReveserLinkedList using Recursion: ";
    display(revRecursion);

}  