#include <iostream>
using namespace std;
class QuadraticHashing {
private:
    int* hashTable; 
    int m; 
    const int EMPTY = -1;
    const int DELETED = -2; 

    int h(int k) {
        return k % m;
    }
public:
    QuadraticHashing(int size) : m(size) {
        hashTable = new int[m]; // Allocate memory for the hash table
        for (int i = 0; i < m; ++i) {
            hashTable[i] = EMPTY; // Initialize all slots to EMPTY
        }
    }
    void insert(int k) {
        int index = h(k);
        if (hashTable[index] == EMPTY) {
            hashTable[index] = k;
            return;
        }
        int i = 1;
        while (hashTable[(index + i * i) % m] != EMPTY) {
            i++;
        }
        hashTable[(index + i * i) % m] = k;
    }
    int search(int k) {
        int index = h(k);
        if (hashTable[index] == k) {
            return index;
        }

     
        int i = 1;
        while (hashTable[(index + i * i) % m] != EMPTY) {
            if (hashTable[(index + i * i) % m] == k) {
                return (index + i * i) % m;
            }
            i++;
        }
        
        return -1; 
    }
    void remove(int k) {
        int index = search(k);
        if (index != -1) {
            hashTable[index] = DELETED; // Mark as deleted
            cout << "Key " << k << " deleted from index " << index << ".\n";
        } else {
            cout << "Key " << k << " not found.\n";
        }
    }
    void display() {
        for (int i = 0; i < m; ++i) {
            if (hashTable[i] == EMPTY) {
                cout << "Slot " << i << ": EMPTY\n";
            } else if (hashTable[i] == DELETED) {
                cout << "Slot " << i << ": DELETED\n";
            } else {
                cout << "Slot " << i << ": " << hashTable[i] << "\n";
            }
        }
    }
};
int main() {
    int size;
    cout << "Enter the size of the hash table: ";
    cin >> size;
    QuadraticHashing qh(size); 
    int choice, key;
    do {
        cout << "1. Insert Key\n";
        cout << "2. Search Key\n";
        cout << "3. Delete Key\n";
        cout << "4. Display Hash Table\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter key to insert: ";
                cin >> key;
                qh.insert(key);
                break;

            case 2:
                cout << "Enter key to search: ";
                cin >> key;
                int index;
                index = qh.search(key);
                if (index != -1) {
                    cout << "Key " << key << " found at index: " << index << "\n";
                } else {
                    cout << "Key " << key << " not found.\n";
                }
                break;

            case 3:
                cout << "Enter key to delete: ";
                cin >> key;
                qh.remove(key);
                break;

            case 4:
                qh.display();
                break;

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
                break;
        }
    } while (choice != 5);

    return 0;
}