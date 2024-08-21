// Reverse an array, Find the maximum and minimum in an array

#include <iostream>
#include <vector>
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

int* Reverse_dynamic(int* arr,int n){
    int* rev=new int[n];
    for(int i=0;i<n;i++){
        rev[i]=arr[n-i-1];
    }
    return rev;

}

vector<int> Reverse_vector(vector<int>& vec){
    int n=vec.size();
    cout<<"Original vector";
    for(auto i:vec){
        cout<<i<<" ";
    }
    cout<<endl;
    vector<int> rev;
    cout<<"Reverse array: ";
    for(int i=0;i<n;i++){
        rev.push_back(vec[n-i-1]);
    }
    return rev;
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

int* MaxMin_dynamic(int* arr,int n){
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
    int* merge=new int[2];
    merge[0]=max;
    merge[1]=min;
    return merge;

}

vector<int> MaxMin_vector(int arr[],int n){
    vector<int> max_min(2);
    max_min[0]=arr[0];
    max_min[1]=arr[0];
    for(int i=0; i<n;i++){
        if(max_min[0]<arr[i]){
            max_min[0]=arr[i];
        }
        if(max_min[1]>arr[i]){
            max_min[1]=arr[i];
        }
    }
    return max_min;
    
}

int main(){
    int arr[5]={1,2,3,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    Reverse(arr,n);
    MaxMin(arr,n);

    // Dynamic array return type
    int* rev = Reverse_dynamic(arr,n);
    cout<<"Reverse array: ";
    for(int i=0;i<n;i++){
        cout<<rev[i]<<" ";
    }
    cout<<endl;

    int* max_min=MaxMin_dynamic(arr,n);
    cout<<"Max: "<<max_min[0]<<endl;
    cout<<"Min: "<<max_min[1]<<endl; 

    // Create a dynamic array
    int* d_arr=new int[n];
    cout<<"Enter the value for dynamic array ";
    for (int i=0;i<n;i++){
        cin>>d_arr[i];
    }
    Reverse(d_arr,n);

    //Create a vector 
    vector<int> vec;
    vec={1,2,3};
    vec.push_back(4);
    vec.emplace_back(5);
    vector<int> vec_rev=Reverse_vector(vec);
    for(auto i:vec_rev){
        cout<<i<<" ";
    }
    cout<<endl;

    vector<int> vec_mm=MaxMin_vector(arr,n);
    cout<<"Max: "<<vec_mm[0]<<"Min: "<<vec_mm[1]<<endl;
}