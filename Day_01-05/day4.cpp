#include <iostream>
#include <vector>
using namespace std;

string LCP(vector<string> str){
    if(str.empty()) return "";
    string prefix=str[0];
    for(int i=0;i<str.size();i++){
        int j=0;
        while(j<prefix.size()&&j<str[i].size()&&prefix[j]==str[i][j]){
            j++;
        }
        prefix=prefix.substr(0,j);
        if(prefix.empty()) return "";
     }
     return prefix;
}

string count_and_say(int n){
    if(n==1) return "1";
    string say="1";
    for(int i=1;i<n;i++){
        int count=1;
        string temp="";
        for(int j=0;j<say.size()-1;j++){
            if(say[j]==say[j+1]){
                count++;
            }
            else{
                temp+=to_string(count)+say[j];
                count=1;
            }
            
        }
        temp+=to_string(count)+say.back();
        say=temp;
    }
    return say;
}

int main(){
    vector<string> str={"abcd","abc","abd"};
    string lcp=LCP(str);
    cout<<"LCP: "<<lcp<<endl;

    int n=5;
    string CAS=count_and_say(n);
    cout<<"count_and_say: "<<CAS<<endl;
}