#include<iostream>
using namespace std;
int main(){
    int n; 
    cout<<"Enter size of array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
   int arr1[n];
   for(int i=0;i<n;i++){
    arr1[i]=arr[n-1-i];
   }
    cout<<"Array after Reversal: ";
    for(int k=0;k<n;k++){
        cout<<arr1[k]<<" ";
    }
}

