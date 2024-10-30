#include<iostream>
using namespace std;
int factorial(int a){
    int f=1;
    // for(int i=1;i<=a;i++){
    //     f*=i;
    // }
    while(a>0){
        f*=a;
        a--;
    }
    return f;
}
int combination(int a,int b){
    int combination=factorial(a)/(factorial(b)*factorial(a-b));
    return combination;
}
int main(){
    int n;
    cout<<"Enter number of rows: ";
    cin>>n;
    int nsp=n;
    for(int i=0;i<=n;i++){
        //Spaces
        for(int k=1;k<=nsp;k++){
            cout<<" ";
        }
        nsp--;

        for(int j=0;j<=i;j++){
            cout<<combination(i,j)<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}