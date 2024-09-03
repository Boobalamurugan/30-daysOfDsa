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

// return the intersected nodes 
// TC : O(N1 * N2)
// SC : O(min(N1, N2))
Node* intersectionOfTwoLL(Node*head1, Node* head2){
    Node* L1=head2;
    Node* L2=head1;
    Node* newHead=nullptr;
    Node* temp=nullptr;
    while(L2!=nullptr){
        L1=head2;
        while(L1!=nullptr){
            if(L1->data==L2->data){
                Node* newNode=new Node(L1->data);
                if(newHead==nullptr){
                    newHead=newNode;
                    temp=newHead;
                }
                else{
                    temp->next=newNode;
                    temp=temp->next;
                }
                break;
            }
            L1=L1->next;
        }
        L2 = L2->next;
    }
    return newHead;
}

// return the intersection nodes without create a newLL
// TC : O(N1 * N2)
// SC : O(1)
Node* intersectionOfTwoLL_reduceSC(Node* head1, Node* head2) {
        Node* L1=head1;
        Node* L2=head2;
        Node* dNode=new Node(-1);
        Node* temp=dNode;
        
        while(L1!=nullptr){
            L2=head2;
            while(L2!=nullptr){
                if(L1->data==L2->data){
                    temp->next=new Node(L1->data);
                    temp=temp->next;
                }
                L2=L2->next;
            }
            L1=L1->next;
            
        }
        return dNode->next;
        
    }


// using unoreded set
// TC : O(N1 + N2)
// SC : O(N) for set 
Node* intersectionOfTwoLL_OP_set(Node* head1,Node* head2){
        Node* L1=head1;
        Node* L2=head2;
        Node* dNode=new Node(-1);
        Node* temp=dNode;
        unordered_set<int> set;

        while(L2!=nullptr){
            set.insert(L2->data);
            L2=L2->next;
        }

        while(L1!=nullptr){
            if(set.find(L1->data)!=set.end()){
                temp->next=new Node(L1->data);
                temp=temp->next;
            }
            L1=L1->next;
        }

        return dNode->next;
}

// using map sturture
Node* intersectionOfTwoLL_OP_map(Node* head1,Node* head2){
        Node* L1=head1;
        Node* L2=head2;
        Node* dNode=new Node(-1);
        Node* temp=dNode;
        unordered_map<int,int> mpp;

        while(L2!=nullptr){
            mpp[L2->data]++;
            L2=L2->next;
        }

        while(L1!=nullptr){
            if(mpp[L1->data] > 0){
                temp->next=new Node(L1->data);
                temp=temp->next;
                mpp[L1->data]--;
            }
            L1=L1->next;
        }

        return dNode->next;
}

int main(){
    cout<<"Intersection of two Linked Lists"<<endl;
    LinkedList list1;
    LinkedList list2;
    
    int arr1[]={ 9,6,4,2,3,8};
    for(auto i:arr1){
        list1.append(i);
    }

    int arr2[]={1,2,8,6};
    for(auto i:arr2){
        list2.append(i);
    }

    list1.display();
    list2.display();

/* 
intersectionOfTwoLL
intersectionOfTwoLL_reduceSC 
intersectionOfTwoLL_OP_set
intersectionOfTwoLL_OP_map
*/
    Node* output=intersectionOfTwoLL_OP_map(list1.head,list2.head);
    LinkedList result;
    result.head = output;
    result.display();
}   