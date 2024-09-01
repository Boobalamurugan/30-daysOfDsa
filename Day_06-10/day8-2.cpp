#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* bottom;

        Node(int x){
            data=x;
            next=nullptr;
            bottom=nullptr;
        }
};

void printOriginalLinkedList(Node* head,int depth){
    while(head!=nullptr){
        cout<< head->data;
        if(head->bottom!=nullptr){
            cout<<" -> ";
            printOriginalLinkedList(head->bottom,depth+1);
        }

        if(head->next!=nullptr){
            cout<<endl;
        }
        head=head->next;
    }
}

void printLinkedList(Node* head){
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->bottom;
    }
    cout << endl;
}

Node* flattenLinkedList_BF(Node* head){
    if(head==nullptr || head->next==nullptr){
        return head;
    }

    vector<int> vec;

    while(head!=nullptr){
        Node* bottom=head;
        while(bottom!=nullptr){
            vec.push_back(bottom->data);
            bottom=bottom->bottom;
        }
        head=head->next;
    }

    sort(vec.begin(),vec.end());

    Node* dNode=new Node(-1);
    Node* temp=dNode;
    for(int i=0;i<vec.size();i++){
        Node* nn=new Node(vec[i]);
        temp->bottom=nn;
        temp=temp->bottom;
    }

    return dNode->bottom;

}

Node* mergeTwoLL(Node* h1,Node* h2){
    Node* dNode=new Node(-1);
    Node* temp=dNode;
    while(h1!=nullptr && h2!=nullptr){
        if(h1->data < h2->data){
            temp->bottom=h1;
            h1=h1->bottom;
        }
        else{
             temp->bottom=h2;
             h2=h2->bottom;
        }
        temp=temp->bottom;
    }
    if(h1!=nullptr) temp->bottom=h1;
    else if (h2!=nullptr) temp->bottom=h2;

    return dNode->bottom;
}
Node* flattenLinkedList_OP(Node* head){
    if(head==nullptr || head->next==nullptr){
        return head;
    }

    Node* mergeLL=flattenLinkedList_OP(head->next);
    Node* newHead=mergeTwoLL(head,mergeLL);
    return newHead;
}

int main(){

    Node* head=new Node(5);
    head->bottom=new Node(7);
    head->bottom->bottom=new Node(8);
    head->bottom->bottom->bottom=new Node(30);


    head->next = new Node(10);
    head->next->bottom = new Node(20);

    head->next->next = new Node(19);
    head->next->next->bottom = new Node(22);
    head->next->next->bottom->bottom = new Node(50);

    head->next->next->next = new Node(20);
    head->next->next->next->bottom = new Node(35);
    head->next->next->next->bottom->bottom = new Node(40);
    head->next->next->next->bottom->bottom->bottom= new Node(45);



    cout << "Original linked list:" << endl;
    printOriginalLinkedList(head, 0);

    Node* flattened = flattenLinkedList_OP(head);
    cout << "\nFlattened linked list: ";
    printLinkedList(flattened);

}

