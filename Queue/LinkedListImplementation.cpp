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
class Queue {
public:
    Node* head;
    Node* tail;
    int size;

    Queue() {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    void push(int val) {
        Node* temp = new Node(val);
        if (size == 0) {
            head = tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
        size++;
    }

    void pop() {
        if (head == NULL) {
            cout << "Queue is empty" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        size--;
    }

    int Front() {
        if (head == NULL) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return head->val;
    }

    int length() {
        return size;
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.display();
    cout << q.Front() << endl;
    q.pop();
    q.display();
    cout<<q.length();
    return 0;
}
