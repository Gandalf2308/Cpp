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
    // cout<<"Entered Array is: ";
    // for(int i=0;i<n;i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;
    int i=0;
    int j=n-1;
    while(j>=i){
        int temp= arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
        i++;
        j--;
    }
    // for(int i=0,j=n-1;i<=j;i++,j--){
    //     int temp= arr[i];
    //     arr[i]=arr[j];
    //     arr[j]=temp;

    // }
    cout<<"Array after Reversal: ";
    for(int k=0;k<n;k++){
        cout<<arr[k]<<" ";
    }
}

