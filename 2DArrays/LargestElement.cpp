#include<iostream>
#include<climits>
using namespace std;
int main(){
    int m;
    cout<<"Enter number of rows: ";
    cin>>m;
    int n;
    cout<<"Enter number of columns: ";
    cin>>n;
int arr[m][n];
    //Input
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    //Print
    cout<<"Matrix is: "<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
   int max=INT_MIN;
   for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
        if(arr[i][j]>max) max=arr[i][j];
    }
   }
   cout<<"Largest Element is: "<<max<<endl;
   int secmax=INT_MIN;
   for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
        if(arr[i][j]>secmax && arr[i][j]!=max) secmax=arr[i][j];
    }
   }
 cout<<"Second Largest elemnt is: "<<secmax;
    return 0;
}