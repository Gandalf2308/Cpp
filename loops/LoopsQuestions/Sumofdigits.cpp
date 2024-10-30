#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter any number:";
    cin>>n;
    int sum=0;
    int a;
    while(n!=0){
        a=n%10;
        sum+=a;
        n=n/10;
    }
    cout<<sum;
    return 0;
}