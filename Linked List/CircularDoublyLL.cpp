#include <iostream>
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node* prev;
    Node(int val) {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
class CircularDoublyLinkedList{
public:
    Node* head;
    Node* tail;
    int s;

    CircularDoublyLinkedList() {
        head = tail = nullptr;
        s=0;
    }
    void InsertAtIdx(int idx, int val) {
        if (idx < 0 || idx > s) {
            cout << "Invalid Index" << endl;
            return;
        }
        Node* temp = new Node(val);
        if (idx == 0) { 
            if (s == 0) { 
                head = tail = temp; 
                head->next = head;  
                head->prev = head;   
            } else {
                temp->next = head;   
                temp->prev = tail;
                head->prev = temp;   
                tail->next = temp;   
                head = temp;        
            }
        } 
        else if (idx == s) {  // Inserting at the tail
            tail->next = temp; 
            temp->prev = tail; 
            temp->next = head;   
            head->prev = temp;   
            tail = temp; 
        } 
        else { 
            Node* t = head;
            for (int i = 0; i < idx - 1; i++) {
                t = t->next;
            }
            temp->next = t->next;
            temp->prev = t; 
            if (t->next != nullptr) {  
                t->next->prev = temp; 
            }
            t->next = temp;

            if (temp->next == head) { 
                head->prev = temp;
            }
        }

        s++;
    }
    void DeleteAtIdx(int idx) {
        if (idx < 0 || idx >= s) {
            cout << "Invalid index" << endl;
            return;
        }
        Node* temp = NULL;//node to be deleted
        if (idx == 0) {  // Deleting the head
            temp = head;
            if (s== 1) { 
                head = tail = NULL; 
            } else {
                head = head->next; 
                tail->next = head;      
                head->prev = tail;     
            }
        } else {
            Node* t = head;
            for (int i = 0; i < idx - 1; i++) {
                t = t->next;
            }
            temp = t->next;
            if (temp->next != NULL) {  
                temp->next->prev = t; 
            }
            t->next = temp->next;

            if (idx == s - 1) {  
                tail = t; 
                tail->next = head;   
                head->prev = tail;   // Circularity
            }
        }
        s--;
    }
    void display() {
        if (s==0) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        do {
            cout << temp->val << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
    void displayReverse() {
        if (s==0) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = tail;
        do {
            cout << temp->val << " ";
            temp = temp->prev;
        } while (temp != tail);
        
        cout << endl;
    }
        void search(int val) {
        Node* temp = head;
        while (true) {
            if (temp->val == val) {
                cout << "Yes" << endl;
                return;
            }
            temp = temp->next;
            if (temp == head) break;
        }
        cout << "No" << endl;
    }
};
int main() {
    CircularDoublyLinkedList one;
    int choice;
    int idx;
    int val;
    bool flag=true;
    while (flag){
        cout << "1. Insert at Index\n";
        cout << "2. Delete at Index\n";
        cout << "3. Display List\n";
        cout << "4. Display List in Reverse\n";
        cout << "5. Get Length of List\n";
        cout << "6. Search Element\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: 
                cout << "Enter index and value to insert: ";
                cin >> idx >> val;
                one.InsertAtIdx(idx, val);
                break;

            case 2: 
                cout << "Enter index to delete: ";
                cin >> idx;
                one.DeleteAtIdx(idx);
                break;

            case 3: 
                one.display();
                break;

            case 4:
                one.displayReverse();
                break;    
                
            case 5: 
                cout << "Length of List is: " << one.s<< endl;
                break;

            case 6: 
                cout << "Enter value to search: ";
                cin >> val;
                one.search(val); 
                break;
            case 7: 
                cout << "Exiting..." << endl;
                flag=false;
                break;
            default:
                cout << "Invalid choice." << endl;
        }
        if(flag==false) break;
    }
    return 0; 
}