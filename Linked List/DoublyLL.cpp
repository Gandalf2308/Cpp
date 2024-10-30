#include<iostream>
using namespace std;
class Node{
public:
    int val;
    Node* next;
    Node* prev;
    Node(int val){
        this->val=val;
        this->next=NULL;
        this->prev=NULL;
    }
};
class DoublyLinkedList{
public:
    Node* head;
    Node* tail;
    DoublyLinkedList(){
        head=NULL;
        tail=NULL;
    }
     void InsertAtStart(int val){
         Node* temp=new Node(val);
         if(head==NULL){
             head=tail=temp;
             return;
         }
         else{
             temp->next=head;
             head->prev=temp;
             head=temp;
             return;
         }
     }
    void InsertAtTail(int val){
         Node* temp=new Node(val);
         if(head==NULL){
             head=tail=temp;
             return;
         }
         else{
             tail->next=temp;
             temp->prev=tail;
             tail=temp;
             return;
         }
     }
     void InsertAtIndex(int val,int idx){
        Node* temp= new Node(val);
        Node* t=head;
        for(int i=1;i<idx-1;i++){
            t=t->next;
        }
        temp->next=t->next;
        t->next=temp;
        temp->prev=t;
        temp->next->prev=temp;
         return;
        
     }
     void DeleteAtStart(){
        if(head==NULL){
            cout<<"List is already Empty";
            return;
        }
        else{
            if(head->next==NULL) {
            tail=NULL;
            return;
        }
            head=head->next;
            head->next->prev=NULL;
            return;
        }
     }
    void DeleteAtTail(){
        if(head==NULL){
            cout<<"List is already Empty";
            return;
        }
        else{
            Node* temp=tail;
            tail=tail->prev;
            if(tail==NULL){
                head=NULL;
            }
            else{
                tail->next=NULL;
            }
        }
     }
     void Display(){
         Node* temp=head;
         while(temp!=NULL){
             cout<<temp->val<<" ";
             temp=temp->next;
         }
         cout<<endl;
     }
     
    
};
int main(){
    DoublyLinkedList dll;
    dll.InsertAtStart(1);
    dll.InsertAtStart(2);
     dll.InsertAtStart(3);
    dll.Display();
    // dll.InsertAtTail(45);
    // dll.Display();
    //  dll.InsertAtIndex(6,1);
    // dll.Display();
    dll.DeleteAtStart();
    dll.Display();
    return 0;
}