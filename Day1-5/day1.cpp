#include <iostream>
using namespace std;

void Reverse(int arr[],int n){
    int rev[n];
    int j=0;
    for(int i=n-1;i>=0;i--){
        rev[j]=arr[i];
        j++;
    }
    cout<<"Reverse array: ";
    for(int i=0;i<n;i++){
        cout<<rev[i]<<" ";
    }
    cout<<endl;
}

void MaxMin(int arr[],int n){
    int max=arr[0];
    int min=arr[0];
    for(int i=0; i<n;i++){
        if(max<arr[i]){
            max=arr[i];
        }
        if(min>arr[i]){
            min=arr[i];
        }
    }
    cout<<"Max: "<<max<<endl;
    cout<<"Min: "<<min<<endl;
}

int main(){
    int arr[5]={1,2,3,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    Reverse(arr,n);
    MaxMin(arr,n);
}