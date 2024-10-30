// #include <iostream>
// using namespace std;
// class LinearHashing {
// private:
//     int* hashTable; 
//     int m; 
//     static const int DELETED = -1;
// public:
//     LinearHashing(int size) : m(size) {
//         hashTable = new int[m];
//         for (int i = 0; i < m; i++) {
//             hashTable[i] = NULL; 
//         }
//     }
//     // Hash function
//     int h(int k) {
//         return k % m;
//     }
//     void insert(int k) {
//         int index = h(k);
//         if (hashTable[index] == NULL || hashTable[index] == DELETED) {

//             hashTable[index] = k;
//             cout << "Inserted " << k << " at index " << index << endl;
//         } else {

//             int i = 1;
//             while (hashTable[(index + i) % m] != NULL && hashTable[(index + i) % m] != DELETED) {
//                 i++;
//             }
//             hashTable[(index + i) % m] = k;
//             cout << "Inserted " << k << " at index " << ((index + i) % m) << endl;
//         }
//     }

//     int search(int k) {
//         int index = h(k);
//         if (hashTable[index] != NULL && hashTable[index] == k) {
//             return index; 
//         } else {
//             int i = 1;
//             while (hashTable[(index + i) % m] != NULL) {
//                 if (hashTable[(index + i) % m] == k) {
//                     return (index + i) % m; 
//                 }
//                 i++;
//             }
//         }
//         return -1; 
//     }
//     void deleteKey(int k) {
//         int index = search(k);
//         if (index != -1) {
//             hashTable[index] = DELETED; 
//             cout << "Deleted " << k << " from index " << index << endl;
//         } else {
//             cout << k << " not found in the hash table." << endl;
//         }
//     }

//     void display() {
//         cout << "Hash Table:" << endl;
//         for (int i = 0; i < m; i++) {
//             if (hashTable[i] == NULL) {
//                 cout << "NULL ";
//             } else if (hashTable[i] == DELETED) {
//                 cout << "DELETED ";
//             } else {
//                 cout << hashTable[i] << " ";
//             }
//         }
//         cout << endl;
//     }
// };
// int main() {
//     int size;
//     cout << "Enter size of hash table: ";
//     cin >> size;
//     LinearHashing linearHashing(size); 
//     bool Flag = true; 
//     while (Flag) {
//         cout << "1. Insert" << endl;
//         cout << "2. Search" << endl;
//         cout << "3. Delete" << endl;
//         cout << "4. Display" << endl;
//         cout << "5. Exit" << endl;    
//         int choice;
//         cout << "Enter your choice: ";
//         cin >> choice;
//         switch (choice) {
//             case 1: { 
//                 int value;
//                 cout << "Enter value to insert: ";
//                 cin >> value;
//                 linearHashing.insert(value);
//                 break;
//             }
//             case 2: { 
//                 int value;
//                 cout << "Enter value to search: ";
//                 cin >> value;
//                 int index = linearHashing.search(value);
//                 if (index != -1)
//                     cout << value << " found at index " << index << endl;
//                 else
//                     cout << value << " not found in the hash table." << endl;
//                 break;
//             }
//             case 3: { 
//                 int value;
//                 cout << "Enter value to delete: ";
//                 cin >> value;
//                 linearHashing.deleteKey(value);
//                 break;
//             }
//             case 4: { 
//                 linearHashing.display();
//                 break;
//             }
//             case 5: {
//                 Flag = false;  
//                 cout << "Exiting... " << endl;
//                 break;
//             }
//             default:
//                 cout << "Invalid choice! Please try again." << endl;
//         }
//     }
//     return 0;
// }
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