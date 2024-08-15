//  Move all zeros to the end, Sort an array of 0s, 1s, and 2s
#include <iostream>
using namespace std;

void swap(int* a,int* b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

int* sort012_better(int* arr,int n){
    int count0=0, count1=0,count2=0;
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            count0++;
        }
        else if(arr[i]==1){
            count1++;
        }
        else if(arr[i]==2){
            count2++;
        }
    }
    int i=0;
    for(;i<count0;i++){
        arr[i]=0;
    }
    for(;i<count1+count0;i++){
        arr[i]=1;
    }
    for(;i<count2+count1+count0;i++){
        arr[i]=2;
    }

    return arr;

}

void sort012_optimal(int arr[], int n)
{
    // code here 
    int low = 0;
    int high = n-1;
    int mid =0;
    
    while(mid<=high){
        switch(arr[mid]){
            case 0:
                swap(&arr[low],&arr[mid]);
                low++;
                mid++;
                break;
            case 1:
                mid++;
                break;
            case 2:
                swap(&arr[mid],&arr[high]);
                high--;
                break;
        }       
    }
    // display
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int* zero_at_end(int* arr, int n){
    int * result=new int[n];
    int idx=0;
    for(int i=0;i<n;i++){
        if(arr[i]!=0){
            result[idx]=arr[i];
            idx++;
        }
    }
    while(idx<n){
        result[idx++]=0;
    }
    return result;
}

int main(){
    int arr[]={0,2,0,1,2,0};
    int n=sizeof(arr)/sizeof(int);

    sort012_optimal(arr,n);

    int* better=sort012_better(arr,n);
    for(int i=0;i<n;i++){
        cout<<better[i]<<" ";
    }cout<<endl;
    
    int* zeros=zero_at_end(arr,n);
    for(int i=0;i<n;i++){
        cout<<zeros[i]<<" ";
    }cout<<endl;
}