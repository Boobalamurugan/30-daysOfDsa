// Next Greater Element 

#include <bits/stdc++.h>
using namespace std;

vector<int> NGE_BF(int arr[],int n){
    vector<int> new_arr(n);
    for(int i=0;i<n;i++){
        if(i==n){
            new_arr[i]=-1;
            break;
        }
        int cnt=0;
        for(int j=i+1;j<n;j++){
            if(arr[i]<arr[j]){
                new_arr[i]=arr[j];
                break;
            }
            else cnt++;
        }
        if((n-1)-i==cnt) new_arr[i]=-1;
    }
    return new_arr;
}

vector<int> NGE_OP(int arr[],int n){
    vector<int> new_arr(n);
    stack<int> st;
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && st.top()<=arr[i]){
            st.pop();
        }
        if(st.empty()) new_arr[i]=-1;
        else new_arr[i]=st.top();
        st.push(arr[i]);
    }
    return new_arr;
}

void PrintArr(vector<int> arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}

int main(){
    int arr[]={4,5,6,1,2,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    vector<int> nge_bf=NGE_BF(arr,n);
    PrintArr(nge_bf);
    vector<int> nge_op=NGE_OP(arr,n);
    PrintArr(nge_op);

}