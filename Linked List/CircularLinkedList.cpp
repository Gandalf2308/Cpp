#include <iostream>
using namespace std;
class Node {
public:
    int val;
    Node* next;

    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};
class CircularLinkedList {
public:
    Node* head;
    Node* tail;
    int size;
    CircularLinkedList() {
        head = tail = NULL;
        size = 0;
    }
    void InsertAtIdx(int idx, int val) {
        if (idx < 0 || idx > size) {
            cout << "Invalid Index" << endl;
            return;
        }
        Node* temp = new Node(val);
        if (idx == 0) {
            if (size == 0) {
                head = tail = temp;
                tail->next = head;
            } else {
                temp->next = head;
                head = temp;
                tail->next = head;
            }
        } 
        else if (idx == size) { 
            tail->next = temp; 
            tail = temp; 
            tail->next = head;  // Maintain circularity
        } 
        else { 
            Node* t = head;
            for (int i = 0; i < idx - 1; i++) {
                t = t->next;
            }
            temp->next = t->next;
            t->next = temp;
        }

        size++;
    }
    void DeleteAtIdx(int idx) {
        if (idx < 0 || idx >= size) {
            cout << "Invalid index" << endl;
            return;
        }
        Node* temp = NULL;
        if (idx == 0) {
            temp = head;
            if (size == 1) {
                head = tail = NULL; 
            } else {
                head = head->next; 
                tail->next = head;  // Maintain circularity
            }
        } else {
            Node* t = head;
            for (int i = 0; i < idx - 1; i++) {
                t = t->next;
            }
            temp= t->next;
            t->next = temp->next;
            if (idx == size - 1) {  
                tail = t; 
                tail->next = head;  // Maintain circularity
            }
        }
        size--;
    }

    void display() {
        if (head == nullptr) {
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
      void search(int val) {
        if (head == NULL) { 
            cout << "No" << endl;
            return; 
        }
        
        Node* temp = head;

        while (true) { 
            if (temp->val == val) { 
                cout << "Yes" << endl; 
                return; 
            }
           temp=temp->next;
            if (temp == head) break;
        }
        cout << "No" << endl; 
    }
};
int main() {
    CircularLinkedList one;
    int choice;
    int idx;
    int val;
    bool flag=true;
    while(true){    
        cout << "1. Insert at Index\n";
        cout << "2. Delete at Index\n";
        cout << "3. Display List\n";
        cout << "4. Get Length of List\n";
        cout << "5. To search a number\n";
         cout << "6. To Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: 
                cout << "Enter index and value to insert(if you want to Insert at head then write Index as Zero): ";
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
                cout << "Length of List is: " << one.size << endl;
                break;
            case 5:
                    cout << "Enter value to search: ";
                    cin >> val;
                    one.search(val);
                    break;
            case 6: 
                cout << "Exiting..." << endl;
                flag=false;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
        if(flag==false) break;
    }
return 0;
}
