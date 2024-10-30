#include<iostream>
using namespace std;
class Queue{
public:
    int arr[5];
    int front;
    int rear;
    int size;
    Queue(){
        front=0;
        rear=0;
        size=0;
    }
    void push(int val){
        if(rear>5){
            cout<<"Overflow";
            return ;
        }
        else{
            arr[rear]=val;
            rear++;
            size++;
        }
    }
    void pop(){
        if(size==0){
            cout<<"Underflow";
            return;
        }
        else{
            front++;
            size--;
        
        }
    }
    int getFront(){
        if(size==0){
            cout<<"Underflow";
            return -1;
        }
        return arr[front];
 }
    int getRear(){
        if(size==0){
            cout<<"Underflow";
            return -1;
        }
        return arr[rear];
 }
     void display(){
        for(int i=front;i<rear;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
     }
};
int main(){
        Queue q;
        q.push(10);
        q.push(20);
        q.push(30);
        q.display();
        q.pop();
        q.display();
//   st.push(40);
//   st.display();
//   cout<<st.peek()<<endl;
//   st.pop();
//   st.display();
//   cout<<st.peek();
//   st.push(40);
//   st.push(50);
//   st.display();
//   st.push(60);
// st.display();
// st.push(70);
// st.display();
}