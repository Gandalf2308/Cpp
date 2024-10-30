#include<iostream>
using namespace std;
class Stack{
public:
    int arr[5];
    int idx;
    int size;
    Stack(){
        idx=-1;
        size=0;
    }
    void push(int val){
        if(idx==4){
            cout<<"Overflow";
            return;
        }
        idx++;
        arr[idx]=val;
        size++;
    }
    void pop(){
       if(size==0){
        cout<<"Undeflow"<<endl;
        return;
       }
       else idx--;
       size--;
    }
    int peek(){
         if(size==0){
        cout<<"Undeflow";
        return -1;
       }
       else  return arr[idx];
    }
    void display(){
        if(size==0){
        cout<<"Underflow";
        return ;
       }
        for(int i=0;i<=idx;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};
int main(){
   Stack st;
  st.push(10);
  st.push(20);
  st.push(30);
  st.display();
  st.pop();
  st.display();
  st.push(40);
  st.display();
  cout<<st.peek()<<endl;
  st.pop();
  st.display();
  cout<<st.peek();
  st.push(40);
  st.push(50);
  st.display();
  st.push(60);
st.display();
st.push(70);
st.display();
// st.pop();
}


