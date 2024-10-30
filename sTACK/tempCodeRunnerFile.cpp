#include <iostream>
using namespace std;
class Node{
public:
    int val;
    Node* next;
    Node(int val){
        this->val=val;
        this->next=NULL;
    }
};
class Stack{
public:
  Node* Head;
  Stack(){
      Head=NULL;
  }
  void push(int val){
      Node* temp=new Node(val);
      temp->next=Head;
      Head=temp;
  }
  void pop(){
    if(Head==NULL) cout<<"Stack is Empty."<<endl;
    else{
         Node* temp=Head;
         Head=Head->next;
         delete temp;

          }
   }
   void peek(){
       cout<<Head->val;
       cout<<endl;
   }
   void Search(int val){
    Node* temp= new Node(val);
    while(temp!=NULL){
        if(temp->val==val){
            cout<<"Present"<<endl;
                break;
        }
        else {
                temp=temp->next;

    }
   }
   }
};
int main() {
    Stack A;
    int choice;
    bool flag=true;
    while(flag){
          cout<<"Enter 1 for Insertion"<<endl;
          cout<<"Enter 2 to Delete"<<endl;
          cout<<"Enter 3 to peek"<<endl;
          cout<<"Enter 4 to SEARCH for an element in the Stack"<<endl;
          cout<<"Enter ANY NUMBER to exit"<<endl;
          cout<<"Enter your Choice: ";
          cin>>choice;
          switch(choice)
          {
            case 1:
                int a;
                cout<<"Enter the number you want to insert: ";
                cin>>a;
                A.push(a);
                cout<<endl;
                break;
            case 2:
                A.pop();
                cout<<endl;
                break;
            case 3:
                A.peek();
                cout<<endl;
                break;
            case 4:
                int b;
                cout<<"Enter the value you want to search: ";
                cin>>b;
                A.Search(b);
                cout<<endl;
                break;
            default:
                flag=false;
                break;
          }
        if(flag==false) break;

    }
  return 0;
}