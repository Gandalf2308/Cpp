#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter any number:";
    cin>>n;
    int reverse=0;
    int a;
    while(n>0){
        a=n%10;
        reverse*=10;
        reverse+=a;
        
        n=n/10;
        
    }
    cout<<reverse;
    return 0;
}
