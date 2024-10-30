#include<iostream>
using namespace std;
int sum(int a,int b){
    int c=a+b;
    return c;
}
int main(){
   int m,n;
   cout<<"Enter two numbers: ";
   cin>>m>>n;
   cout<<sum(m,n);
    return 0;
}