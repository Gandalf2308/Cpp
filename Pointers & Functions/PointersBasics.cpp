#include<iostream>
using namespace std;
int main(){
   int m,n;
   cout<<"Enter two numbers: ";
   cin>>m>>n;
   int* p1=&m;
   int* p2=&n;
   cout<<*p1+*p2;
    return 0;
}
