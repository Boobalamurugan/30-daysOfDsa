#include <bits/stdc++.h>
using namespace std;

//Create a class Node
class Node{
    public:
    int data=10;
    Node* next;

    Node(int x){
        data=x;
        next=nullptr;
    }
};

//Create a LinkedList Class
class LinkedList{
    //Access spicfier
    public:
        Node* head=nullptr;

    //Node add at end function
    void insert(int data){
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

    //LinkedList Display function
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
            cout << endl;
        }
    }

    // Time Complexity is O(N)+O(N)=O(2N);
    // Space Complexity is O(1);
    Node* RemoveKthFromEnd_BF(int k){
    // Remove the Kth node from the end (Brute Force)
    Node* temp=head;
    int count=0;
    while(temp!=nullptr){
        count++;
        temp=temp->next;
    }

    int delPos=count-k;

    if(k>count || k<=0){
        cout<<"K is Out Of Range ";
        return head;
    }

    if(delPos==0){
        Node* delNode=head;
        head=head->next;
        delete delNode;
        return head;
    }
    temp=head;
    for(int i=1;i<delPos;i++){
        temp=temp->next;
    }
    Node* delNode=temp->next;
    temp->next=temp->next->next;
    delete delNode;
    return head;
}   
    //Time complexity is O(N);
    // Space Complexity is O(1);
    Node* RemoveKthFromEnd_OP(int k){
        // Remove the Kth node from the end (Optimized)
        Node* fast=head;
        for(int i=0;i<k;i++){
            if(!fast){
                cout<<"Out Of Range"<<endl;
                return head;
            }
            fast=fast->next;
        }

        if(fast==nullptr){
            Node* delNode = head;
            head = head->next;
            delete delNode;
            return head;
        }
        Node* slow=head;
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }

        Node* delNode = slow->next;
        slow->next = slow->next->next;
        delete delNode;

        return head;

    }

};




int main(){
    //create a object
    LinkedList list;

    //inilize the linkedlist using insert fn
    int arr[]={1,2,3,4,5};
    for(int i=0;i<5;i++){
        list.insert(arr[i]);
    }

    cout<<"Input: "<<endl;
    list.display();
    int k;
    cout<<"Enter the K element: ";
    cin>>k;
    cout<<"k = "<<k<<endl;

    cout<<"Input: "<<endl;

    // Uncomment the line below to use the brute force method
    // list.RemoveKthFromEnd_BF(k);
    // list.display();

    list.RemoveKthFromEnd_OP(k);
    list.display();

}