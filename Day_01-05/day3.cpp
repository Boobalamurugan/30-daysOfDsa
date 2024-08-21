#include <iostream>
using namespace std;

void revesre(string s){
    for(int i=s.length()-1;i>=0;i--){
        cout<<s[i];
    }cout<<endl;
}

string revesre_removedSpace(string s){
    string result="";
    for(int i=0;i<s.length();i++){
        string temp="";
        while(i<s.length()&& s[i]!=' '){
            temp+=s[i];
            i++;
        }
        for(int j=temp.length()-1;j>=0;j--){
            result=result+temp[j];
        }
    }
    return result;
}

string revesre_without_repeting(string s){
    string result="";
    for(int i=s.length()-1;i>=0;i--){
        char ch=s[i];
        
        if(ch==' ') continue ;
        
        bool present=false;
        for(auto i:result){
            if(i==ch){
                present=true;
                break; 
            }
        }
        if(!present){
            result+=ch;
        }
    }
        return result;
}

string palindome_for(string s){
    for(int i=0;i<=(s.length()-1)/2;i++){
        if(s[i]!=s[s.length()-1-i]){
            return "No";
        }
    }
    return "Yes";
}

string palindome_while(string s){
    int start=0;
    int end=s.length()-1;
    while(start<end){
        if(s[start]!=s[end]){
            return "No";
        }
        start++;
        end--;
    }
    return "Yes";
}


        
int main() {
    string S = "ababa";

    cout << "Output: ";
    revesre(S);

    string removedSpace = revesre_removedSpace(S);
    cout << "Output: " << removedSpace << endl;

    string without_repeting = revesre_without_repeting(S);
    cout << "Output: " << without_repeting << endl;

    string palindome_varf = palindome_for(S);
    cout << "palindome : " << palindome_varf << endl;

    string palindome_varw = palindome_while(S);
    cout << "palindome : " << palindome_varw << endl;
    
    return 0;
}
