#include<iostream>
#include<climits>
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
   int max=INT_MIN;
   for(int j=0;j<=n-1;j++){
    if(arr[j]>max) max=arr[j];
   }
   cout<<"Maximum number in the array is : "<<max;
    return 0;
}