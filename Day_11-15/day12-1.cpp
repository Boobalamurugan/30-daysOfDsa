//Evaluate Reverse Polish Notation

#include <bits/stdc++.h>
using namespace std;

void evalRPN(vector<string> str){
    stack<int> st;
    for(string i:str){
        if(i=="+"){
            int a=st.top();
            st.pop();
            int b=st.top();
            st.pop();
            st.push(b+a);
        }
        else if(i=="-"){
            int a=st.top();
            st.pop();
            int b=st.top();
            st.pop();
            st.push(b-a);
        }
        else if(i=="*"){
            int a=st.top();
            st.pop();
            int b=st.top();
            st.pop();
            st.push(b*a);
        }
        else if(i=="/"){
            int a=st.top();
            st.pop();
            int b=st.top();
            st.pop();
            st.push(b/a);
        }
        else{
            st.push(stoi(i));
        }
    }
    cout<<"Answer: "<<st.top()<<endl;
    
}

int main(){
    vector<string> str={"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    evalRPN(str);
}