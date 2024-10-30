#include<iostream>
using namespace std;
int main(){
    int m;
    cout<<"Enter size of array: ";
    cin>>m;
    int arr[m];
    for(int i=0;i<m;i++){
        cin>>arr[i];
    }
    //Print
    for(int i=0;i<m;i++){
        cout<<arr[i]<<" ";
    }
    for(int i=0;i<m;i++){
        for(int j=m-1;j>i;j--){
            if(arr[i]==0){
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        
            
            
        }
    }
    cout<<endl;
    //Print
    for(int i=0;i<m;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}