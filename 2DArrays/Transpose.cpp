#include<iostream>
using namespace std;
int main(){
        int m;
    cout<<"Enter number of rows of 1st Matrix: ";
    cin>>m;
    int n;
    cout<<"Enter number of columns of 2nd Matrix: ";
    cin>>n;
int arr[m][n];
    //Input
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==j) arr[i][j]=arr[i][j];
            else if(i<j){
                int temp=arr[i][j];
                arr[i][j]=arr[j][i];
                arr[j][i]=temp;
            }
        }
    }
    // cout<<endl;
    cout<<"Transpose is: "<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
