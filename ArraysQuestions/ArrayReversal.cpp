#include<iostream>
using namespace std;
int main(){
    int m;
    cout<<"Enter size of array: ";
    cin>>m;
    int arr[m];
    //Input
    for(int i=0;i<m;i++){
        cin>>arr[i];
    }
    //Print
    for(int i=0;i<m;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int x;
    cout<<"Enter Target sum: ";
    cin>>x;
    for(int i=0;i<m-1;i++){
        for(int j=i+1;j<m;j++){
            if(arr[i]+arr[j]==x) cout<<"["<<i<<","<<j<<"]"<<endl;
            
            }
      
    }
cout<<endl;
    return 0;
}