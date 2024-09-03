#include <bits/stdc++.h>
using namespace std;

// Create a Node for DLL
struct Node{
    int data;
    Node* next;
    Node* back;

    // Constructor with one paramter (data)
    Node(int x){
         data=x;
         next=nullptr;
         back=nullptr;
    }

    // Constructor with all the paramters
    Node(int x,Node* next1,Node* back1){
        data=x;
        next=next1;
        back=back1;
    }
};

// Convert the Array to DLL
Node* array2DoublyLL(vector<int> arr,Node*& head){
    Node* nn=new Node(arr[0]);
    head=nn;
    Node* prev=head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i],nullptr,prev);
        prev->next=temp;
        prev=prev->next;
    }
    return head;
}

    /*  DELETION:
            1.del head
            2.del tail
            3.del kth element
            4.del the node
    */

// Delete at Being or Head
void deleteAtBegin(Node*& head) {
    if (head == nullptr){
        cout << "Linked list is empty" << endl;
        return;
    }
    
    Node* temp = head;
    head = head->next;
    if (head != nullptr){
        head->back = nullptr;
    }
    delete temp;
}


// Delete at End or Tail
void deleteAtEnd(Node*& head){
    if (head == nullptr){
        cout << "Linked list is empty" << endl;
        return;
    }
    Node* temp=head;
    if(temp->next==nullptr){
        delete temp;
        head=nullptr;
        return;
    }
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    
    // temp->back->next=nullptr;
    Node* prev=temp->back;
    temp->back=nullptr;
    prev->next=nullptr;
    delete temp;
}

// Delete at Kth postion
void deleteKthElement(Node*& head,int k){
    
    if(head == nullptr || k <= 0){
        cout << "Invalid position or empty list" << endl;
        return;
    }

    int count=1;
    Node* temp=head;
    while(temp != nullptr && count < k){
        temp = temp->next;
        count++;
    }

    if(temp==nullptr){
        cout<<"OutOfRange"<<endl;
        return;
    }

    Node* prev=temp->back;
    Node* front=temp->next;

    if(prev==nullptr && front==nullptr){
        delete temp;
        head=nullptr;
    }
    else if(prev==nullptr){
        head=head->next;
        head->back=nullptr;
        delete temp;
        return;
    }
    else if(front==nullptr){
        prev->next=nullptr;
        delete temp;
        return;
    }
    else{
        prev->next=front;
        front->back=prev;
        // temp->next=nullptr;
        // temp->back=nullptr;
        delete temp;
    }

}

// Delete The Node 
// we can't delete the head in this fn
void deleteNode(Node* temp){
    if (temp==nullptr) return;
    Node* prev=temp->back;
    Node* front=temp->next;

    if(front==nullptr){
        prev->next=nullptr;
        temp->back=nullptr;
        delete temp;
    } 
    else{
        prev->next=front;
        front->back=prev;
        delete temp;
    }
}

// Display the DLL 
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
        }
        cout<<endl;
    }
}

int main(){

    // Create the head of DLL
    Node* head=nullptr;
    
    // Array to DLL
    vector<int> arr={1,2,3,4,5};
    Node* newHead=array2DoublyLL(arr,head);
    display(newHead);

    //Delete At Begin
    deleteAtBegin(head);
    display(head);

    //Delete At End
    deleteAtEnd(head);
    display(head);

    //Delete Kth element
    deleteKthElement(head,2);
    display(head);

    //Delete the Node expect HeadNode 
    deleteNode(head->next);
    display(head);

}