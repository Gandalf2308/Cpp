#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    int nsp=n-1;
    int nst=1;
    for(int i=1;i<=n;i++){
        //Spaces
        for(int j=1;j<=nsp;j++){
            cout<<" ";
            
    }
      nsp--;
       //Stars
       for(int k=1;k<=nst;k++){
        cout<<"*" ;
       }
     nst+=2;
    cout<<endl;
    }
    return 0;

}