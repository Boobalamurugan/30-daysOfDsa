#include <bits/stdc++.h>
using namespace std;

bool ispar(string str){
    stack<char> st;
    for(int i=0;i<str.size();i++){
        if(str[i]=='{' || str[i]=='[' || str[i]=='('){
            st.push(str[i]);
        }
        else(
        if (st.empty()) return false;
        char ch=st.top();
        if(
        (ch=='(' && str[i]==')') || 
        (ch=='[' && str[i]==']') || 
        (ch='{' && str[i]=='}')
        ){
            st.pop();
        }
        else return false;
        )
    }
    return st.empty();
}


int main(){
    string str="{{}[]}}}";
    if(ispar(str)) cout<< "Balanced"<<endl;
    else cout<<"not balanced"<<endl;   
}