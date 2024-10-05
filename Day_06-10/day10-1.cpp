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

void insertAtBegin(Node*& last,int val){
    Node* nn=new Node(val);
    if(last==nullptr){
        last=nn;
        nn->next=nn;
        return;
    }

    nn->next=last->next;
    last->next=nn;
    return;
}


void insertAtEnd(Node*& last,int val){
    Node* nn=new Node(val);

    if(last==nullptr){
        last=nn;
        nn->next=nn;
    }
    else{
        nn->next=last->next;
        last->next=nn;
        last=nn;
    }
}

void insertAtPos(Node*& last,int val,int pos){

    if(last == nullptr){
        if(pos != 1){
            cout << "Invalid position!" << endl;
            return;
        }
        Node *nn = new Node(val);
        last = nn;
        last->next = last;
        return;
    }

    Node* nn=new Node(val);
    if(pos==1){
        nn->next=last->next;
        last->next=nn;
        return;
    }    
    Node *curr = last->next;
    for (int i = 1; i < pos - 1; ++i){
        curr = curr->next;
        if(curr==last->next){
            cout << "Invalid position!" << endl;
            return;
        }
    }
    nn->next = curr->next;
    curr->next=nn;

    if (curr == last) last=nn;

}

void display(Node* last){
  if(last == NULL) return;
  
    Node* head = last->next;
    while (true) {
        cout << head->data << " ";
        head = head->next;
        if (head == last->next)
            break;
    }
    cout << endl;
}

int main(){
    Node* last=nullptr;
    insertAtBegin(last,1);
    insertAtBegin(last,2);
    insertAtBegin(last,3);
    insertAtEnd(last,4);
    insertAtEnd(last,5);
    insertAtEnd(last,6);
    insertAtPos(last,7,7);
    display(last);
}