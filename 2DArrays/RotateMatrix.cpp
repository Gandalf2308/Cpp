#include<iostream>
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
    //Transpose
    cout<<"Transpose is: "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr[j][i]<<" ";
        }
        cout<<endl;
    }
    //Reverse Each Row
    for(int k=0;k<n;k++){
        int i=0;
        int j=n-1;
        while(i<=j){
            int temp=arr[k][i];
            arr[k][i]=arr[k][j];
            arr[k][j]=temp;
            i++;
            j--;
        }
        
    }
   //print
cout<<"Matrix is: "<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}