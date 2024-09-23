// Implement a Stack using an array

#include<bits/stdc++.h>
using namespace std;

class Stack{
    
    int top;
    int size;
    int* arr;

    public:

    Stack(int x){
        size=x;
        arr=new int[size];
        top=-1;

    }

    int getSize(){
        return size;
    }

    int getArr(int x){
        return arr[x];
    }

    int getTop(){
        return top;
    }

    bool push(int x){
        if(top>=size-1){
            cout<<"Stack Overflow"<<endl;
            return false;
        }
        else{
        top++;
        arr[top]=x;
        cout<<"pushed element"<<endl;
        return true;
        }
    }

    bool pop();
    int peek();
    bool isEmpty();
 
};

bool Stack::pop(){
        if(top<0){
            cout<<"Stack is empty"<<endl;
            return false;
        }
        else{
            cout<<"poped element "<<arr[top]<<endl;
            top--;
            return true;
        }
}

int Stack::peek(){
    if(top<0){
        cout<<"Stack is empty"<<endl;
        return 0;
    }
    else{
        int x=arr[top];
        return x;
    }
}

bool Stack::isEmpty(){
    if(top>=0) return false;
    else return true;
}

void display(Stack stack_imple){

    for(int i=0;i<=stack_imple.getTop();i++){
    cout<<stack_imple.getArr(i)<<" ";
    }
    cout<<endl;
}

int main(){
    Stack stack_imple(5);
    stack_imple.push(5);
    stack_imple.push(1);
    stack_imple.push(3);
    stack_imple.push(2);
    stack_imple.pop();
    cout << "Is stack empty? " << stack_imple.isEmpty() << endl;
    cout << "Top element: " << stack_imple.peek() << endl;
    cout << "Current top index: " << stack_imple.getTop() << endl;
    display(stack_imple);
    
}