#include <bits/stdc++.h>
using namespace std;

//Create a Node using struct
struct Node{
    int data;
    struct Node* next;
};

// Add a Node at the beginning of the list
void add(Node*& head,int data){
    Node* nn=new Node;
    nn->data=data;
    nn->next=head;
    head=nn;
}

//Display the LinkedList
void display(const Node* head){
    if(head==nullptr){
        cout<<"{}"<<endl;
        return;
    }
    const Node* temp=head;
        while(temp!=nullptr){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
}

//Sort the LinkedList
Node* sortLinkedList(Node* head){
    if(!head){
        return 0;
    }
    
    Node* temp=head;
    for(Node* i=temp;i!=nullptr;i=i->next){
        for(Node* j=i->next;j!=nullptr;j=j->next){
            if(i->data > j->data){
                int change=i->data;
                i->data=j->data;
                j->data=change;
            }
        }
    }
    return head;
}

// Return the Length of the LinkedList
int lengthOfLinkedList(const Node* head){
    const Node* temp=head;
    int count=0;
    while(temp!=nullptr){
        count++;
        temp=temp->next;
    }
    return count;
}

// Converts a linked list to a vector
vector<int> convertLinkedListToArray(const Node* head){
    const Node* temp=head;
    int n=lengthOfLinkedList(head);
    vector<int> arr;

    for(int i=0;i<n;i++){
        arr.push_back(temp->data);
        temp=temp->next;
    } 
    return arr;
}

// Print the vector 
void printVec(vector<int> arr){
    for(int i=0;i<arr.size();i++){
    cout<<arr[i]<<" ";
    }cout<<endl;
}

//Megre the vector in sorted
vector<int> mergeArrays(const vector<int>& arr1,const vector<int>& arr2){
    int i=0;
    int j=0;
    vector<int> megred;
    while(i<arr1.size() && j<arr2.size()){
        if(arr1[i]<arr2[j]){
            megred.push_back(arr1[i]);
            i++;
        }
        else{
            megred.push_back(arr2[j]);
            j++;
        }
    }
        while(i<arr1.size()){
            megred.push_back(arr1[i]);
            i++;
        }
        while(j<arr2.size()){
            megred.push_back(arr2[j]);
            j++;
        }
    return megred;
}

//Convert the array to LinkedList
Node* convertArrayToLinkedList(vector<int> arr){
    int n=arr.size();
    Node* newhead=nullptr;
    for(int i=n-1;i>=0;i--){
        add(newhead,arr[i]);
    }
    return newhead;
}

// Return the sorted LinkedList but in O(1) space complexity because of dummy node
Node* mergeLinkedList(Node* head1 , Node* head2){
    Node* t1=head1;
    Node* t2=head2;
    Node* dNode=new Node{-1,nullptr};
    Node* temp=dNode;
    while(t1!=nullptr && t2!=nullptr){
        if(t1->data < t2->data){
            temp->next=t1;
            temp = t1;    // Move temp to point to the newly added node t1
            t1 = t1->next;  
            }  
        else{
            temp->next=t2;
            temp=t2;
            t2=t2->next;
        }
    }
    if(t1!=nullptr){
        temp->next=t1;
    }
    else{
        temp->next=t2;
    }

    return dNode->next;
}


int main(){
    Node* head1=nullptr;
    vector<int> data1 = {8, 6, 7, 4, 5, 3, 2, 1};
    for (int data : data1) {
        add(head1, data);
    }

    Node* head2 = nullptr;
    vector<int> data2 = {11, 12, 9, 10, 13, 14};
    for (int data : data2) {
        add(head2, data);
    }

    cout << "Input: " << endl;
    cout << "Original List 1: ";
    display(head1);

    cout << "Original List 2: ";
    display(head2);

    Node* sortedLL1=sortLinkedList(head1);
    Node* sortedLL2=sortLinkedList(head2);

    vector<int> arr1 = convertLinkedListToArray(sortedLL1);
    // printVec(arr1);
    vector<int> arr2 = convertLinkedListToArray(sortedLL2);
    // printVec(arr2);

    vector<int> merged_arr = mergeArrays(arr1, arr2);
    // printVec(merged_arr);

    Node* mergedHead = convertArrayToLinkedList(merged_arr);
    cout << "Output 1: " << endl;
    display(mergedHead);

    Node* newhead=mergeLinkedList(sortedLL1,sortedLL2);
    cout << "Output 2: " << endl;
    display(newhead);
}