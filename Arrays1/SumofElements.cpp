#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;
    int arr[n];
    cout<<"Enter elements: ";
    for(int i=0;i<=n-1;i++){
        cin>>arr[i];
    }
    int sum=0;
    for(int j=0;j<=n-1;j++){
        sum+=arr[j];
    }
    cout<<"Sum is: "<<sum;
    return 0;
}