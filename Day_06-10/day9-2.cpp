#include <bits/stdc++.h>
using namespace std;

// Create Node using class
class Node{
    public:
        int data;
        Node* next;
        Node* back;
        
        //Constructor without parameter
        Node(){
            data = 0;
            next = nullptr;
            back = nullptr;
        }

        //Constructor with one parameter
        Node(int x){
            data = x;
            next = nullptr;
            back = nullptr;
        }

        //Constructor with multiple parameters
        Node(int x, Node* next1, Node* back1){
            data = x;
            next = next1;
            back = back1;
        }
};

/*     INSERTION
            1. Add at begin
            2. Add at end
            3. Add at kth position
            4. Add after a given node
            5. Add before a given node
*/

// Add at begin
void addAtBegin(Node*& head, int value){
    Node* nn = new Node(value); 
    if(head != nullptr){  
        head->back = nn;
        nn->next = head;
    }
    head = nn;   
}

// Add at end
void addAtEnd(Node*& head, int value){
    Node* nn = new Node(value);
    if(head == nullptr){
        head = nn;
        return; 
    }
    Node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = nn;
    nn->back = temp;
}

// Add at Kth Position
void addKthPosition(Node*& head, int k, int value){
    if(head == nullptr || k <= 0){
        cout << "DLL is empty or k value no valid" << endl;
        return;
    }

    // If k is 1 we need to add the Node in before head (AddAtBegin)
    if(k == 1){
        Node* nn = new Node(value);
        if(head != nullptr){
            head->back = nn;
            nn->next = head;
        }
        head = nn;
        return;
    }

    // Traverse the temp to before the node
    Node* temp = head;
    for(int i = 1; i < k-1 && temp != nullptr ; i++){
        temp = temp->next;
    }

    // If temp is empty that means k is out of range
    if(temp == nullptr){
        cout << "OutOfRange" << endl;
        return;
    }

    // If the node is the last node, we need to add at end (AddAtEnd)
    if(temp->next == nullptr){
        Node* nn = new Node(value);
        temp->next = nn;
        nn->back = temp;
        return;
    }

    // If the k is present in between two nodes 
    Node* nn = new Node(value);
    Node* front = temp->next;
    front->back = nn;
    temp->next = nn;
    nn->next = front;
    nn->back = temp;
}

// Add After a given Node
void addAfterNode(Node*& head, Node* after, int value){
    if(head == nullptr || after == nullptr){
        cout << "Any one of Node is Empty" << endl;
        return;
    }

    // Traverse temp to afterNode
    Node* temp = head;
    while(temp != nullptr){
        if(temp == after) break;
        temp = temp->next;
    }

    // If temp next is null, we use add at end (AddAtEnd)
    if(temp->next == nullptr){
        addAtEnd(head, value);
        return;
    }

    // If Node is in between the two nodes 
    Node* nn = new Node(value);
    Node* front = temp->next;
    front->back = nn;
    temp->next = nn;
    nn->next = front;
    nn->back = temp;
}

// Add Before a given Node
void addBeforeNode(Node*& head, Node* before, int value){
    if(head == nullptr || before == nullptr){
        cout << "Any one of Node is Empty" << endl;
        return;
    }

    // If beforeNode is head, use AddAtBegin
    if(head == before){
        addAtBegin(head, value);
        return;
    }

    // Traverse temp to beforeNode
    Node* temp = head;
    while(temp != nullptr){
        if(temp == before) break;
        temp = temp->next;
    }

    // If Node is in between the two nodes 
    Node* nn = new Node(value);
    Node* prev = temp->back;
    prev->next = nn;
    nn->next = temp;
    temp->back = nn;
    nn->back = prev;
}

// Display Function
void display(Node* head){
    if(head == nullptr){
        cout << "{}" << endl;
        return;
    }
    else{
        Node* temp = head;
        while(temp != nullptr){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

// Display in Reverse Order
void ReverseDLL_display(Node* head){
    if(head == nullptr){
        return;
    }
    Node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->back;
    }
    cout << endl;
}

// Reverse Using Stack
Node* ReverseUsingStack_Node(Node* head){
    if (head == nullptr) return nullptr;

    stack<Node*> s;
    Node* temp = head;

    // Push all nodes onto the stack
    while (temp != nullptr) {
        s.push(temp);
        temp = temp->next;
    }

    // Pop nodes from stack and reverse the pointers
    Node* newHead = s.top();
    s.pop();
    temp = newHead;
    temp->back = nullptr; // The new tail should have its back pointer set to nullptr

    while (!s.empty()) {
        temp->next = s.top();
        s.top()->back = temp;
        temp = s.top();
        s.pop();
    }
    temp->next = nullptr; // End of new list

    return newHead;
}

Node* ReverseUsingStack_data(Node* head){
    if (head == nullptr) return nullptr;

    stack<int> s;
    Node* temp = head;

    // Push all nodes onto the stack
    while (temp != nullptr) {
        s.push(temp->data);
        temp = temp->next;
    }

    temp = head;

    while (!s.empty()) {
        temp->data = s.top();
        s.pop();
        temp=temp->next;
    }
    // temp->next = nullptr; // End of new list

    return head;
}


// Reverse Using Pointer Manipulation
Node* reverseDLL_OP(Node*& head){
    if (head == nullptr) return nullptr;

    Node* temp = head;
    Node* prev = nullptr;

    while (temp != nullptr){
        prev = temp->back;
        temp->back = temp->next;
        temp->next = prev;
        temp = temp->back;
    }
    
    head = prev->back; // Update head to the last non-null node

    return head;
}

int main(){
    Node* head = nullptr;
    addAtBegin(head, 1); // 1
    addAtBegin(head, 2); // 2 1
    addAtEnd(head, 3);   // 2 1 3
    addKthPosition(head, 1, 5); // 5 2 1 3 
    addAfterNode(head, head->next->next->next, 3); //  5 2 1 3 3
    addBeforeNode(head, head->next->next->next->next, 1); // 5 2 1 3 1 3
    display(head);

    // Display the DLL in reverse order
    ReverseDLL_display(head);

    // Reverse using stack
    Node* reverseNode = ReverseUsingStack_Node(head);
    head = reverseNode; // Update the head after reversing
    display(head);

    // Reverse using stack
    Node* reverse = ReverseUsingStack_data(head);
    head = reverse; // Update the head after reversing
    display(head);

    // Reverse using pointer manipulation
    Node* reverse_OP = reverseDLL_OP(head);
    head = reverse_OP; // Update the head after reversing
    display(head);
}
