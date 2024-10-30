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
 int p;
    cout<<"Enter number of rows in 2nd Matrix: ";
    cin>>p;
    int q;
    cout<<"Enter number of columns in 2nd Matrix: ";
    cin>>q;
int arr1[p][q];
    
    for(int i=0;i<p;i++){
        for(int j=0;j<q;j++){
            cin>>arr1[i][j];
        }
    }
//Multiplication
int res[m][q];
for(int i=0;i<m;i++){
    for(int j=0;j<q;j++){
        res[i][j]=0;
        for(int k=0;k<p;k++){
            res[i][j]+=arr[i][k]*arr1[k][j];
        }
    }

}
cout<<"Matrix after multiplication is: "<<endl;
//print
for(int i=0;i<m;i++){
    for(int j=0;j<q;j++){
       cout<<res[i][j]<<" ";
    }
   cout<<endl;
}
}