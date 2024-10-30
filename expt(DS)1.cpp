#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter size of Array: ";
    cin>>n;
    int arr[n];
    int count,sum=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    //Print
    cout<<"Entered Array is: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
        count++;
        sum+=arr[i];
    }
    //Count
    cout<<"Number of elements in array is: ";
   cout<<count;
    //Sum
    cout<<"Sum of elements in array is: ";
    cout<<sum;
    return 0;
}