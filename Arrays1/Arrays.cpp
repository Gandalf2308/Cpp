#include<iostream>
using namespace std;
int main(){
    int arr[10]={23,45,67,78,90,22,62,12,21,40};
    int n;
    cout<<"Enter index: ";
    cin>>n;
    for(int i=0;i<10;i++){
        if(i==n) cout<<arr[i];
    }
    return 0;
}