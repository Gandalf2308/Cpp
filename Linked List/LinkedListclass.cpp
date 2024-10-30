#include<iostream>
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

class Linkedlist {
public:
    Node* head;
    Node* tail;
    int size;

    Linkedlist() {
        head = tail = NULL;
        size = 0;
    }

    void InsertAtIdx(int idx, int val) {
        if (idx < 0 || idx > size) {
            cout << "Invalid Index" << endl;
            return;
        }
        Node* temp = new Node(val);
        if (idx == 0) {  // Inserting at the head
            temp->next = head;
            head = temp;
            if (size == 0) {
                tail = temp;
            }
        } 
        else if (idx == size) {  // Inserting at the tail
            tail->next = temp;
            tail = temp;
        } 
        else {  // Inserting in the middle
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
        if (idx < 0 || idx >= size) {  // Changed to allow deletion of the last element
            cout << "Invalid index" << endl;
            return;
        }
        Node* toDelete = nullptr;

        if (idx == 0) {  // Deleting the head
            toDelete = head;
            head = head->next;
            if (size == 1) {  // If the list becomes empty
                tail = NULL;
            }
        } else {
            Node* t = head;
            for (int i = 0; i < idx - 1; i++) {
                t = t->next;
            }
            toDelete = t->next;
            t->next = toDelete->next;
            if (idx == size - 1) {  // If we are deleting the tail
                tail = t;
            }
        }

        delete toDelete;  
        size--;
    }

    void display() {
        Node* temp = head;
        if (temp == NULL) {
            cout << "List is empty." << endl;
            return;
        }
        while (temp != NULL) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Linkedlist one;
    int choice, idx, val;

    do {
        
        cout << "1. Insert at Index\n";
        cout << "2. Delete at Index\n";
        cout << "3. Display List\n";
        cout << "4. Get Length of List\n";
        cout << "5. Exit\n";
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
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
