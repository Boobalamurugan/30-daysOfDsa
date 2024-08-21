#include <iostream>
#include <vector>
using namespace std;

int max_sum_subarr_k_BruteForce(vector<int>& arr,int k){
    int n=arr.size();
    int max_sum=0;
    for(int i=0;i<=n-k;i++){
        int curr_sum=0;
        for(int j=i;j<i+k;j++){
            curr_sum+=arr[j];
        }
        max_sum=max(max_sum,curr_sum);
    }
    return max_sum;
}

int max_sum_subarr_k_Optimal(vector<int> arr,int k){
    int n=arr.size();
    int curr_sum=0;
    for(int i=0;i<k;i++){
        curr_sum+=arr[i];
    }
    int max_sum=curr_sum;
    for(int i=k;i<n;i++){
        curr_sum+=arr[i]-arr[i-k];
        if(max_sum<curr_sum){
            max_sum=curr_sum;
        }
    }
    return max_sum;
}

int longest_substr_without_repetation_BF(string s){
    
    int max_ans=0;
    for(int i=0;i<s.length();i++){
        vector<int> hash(256,0);
        for(int j=i;j<s.length();j++){
            if(hash[s[j]]!=0){
                break;
            }
            hash[s[j]]=1;
            max_ans=max(max_ans,j-i+1);
        }
    }
    return max_ans;
}

int longest_substr_without_repetation_OP(string s){
    int l=0;
    int r=0;
    int len=0;
    int n=s.length();
    vector<int> hash(256,-1);
    while(r<n){
        if(hash[s[r]]!=-1){
            l=max(hash[s[r]]+1,l);
        }
        hash[s[r]]=r;
        len=max(len,r-l+1);
        r++;
    }
    return len;
}



int main(){
    vector<int> arr={1,2,3,4,5};
    int k=3;
    int max_bf=max_sum_subarr_k_BruteForce(arr,k);
    cout<<"max_sum_subarr_k_BruteForce: "<<max_bf<<endl;

    int max_op=max_sum_subarr_k_Optimal(arr,k);
    cout<<"max_sum_subarr_k_Optimal: "<<max_op<<endl;

    string str="abcabcbb";
    int substr_bf=longest_substr_without_repetation_BF(str);
    cout<<"longest_substr_without_repetation_BF: "<<substr_bf<<endl;

    int substr_op=longest_substr_without_repetation_OP(str);
    cout<<"longest_substr_without_repetation_OP: "<<substr_op<<endl;
}