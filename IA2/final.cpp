#include <iostream>
#include <string>
using namespace std;
class Node {
public:
    string stockName;
    float priceStart;
    float priceEnd;
    float priceDifference;
    Node* next;
    Node(string name, float start, float end) {
        stockName = name;
        priceStart = start;
        priceEnd = end;
        priceDifference = priceEnd - priceStart;
        next = NULL;
    }
};
class Stock {
public:
    Node* head;
    Stock() {
        head = NULL;
    }
    void enqueue(string name, float start, float end) {
        Node* newNode = new Node(name, start, end);
        if (head == NULL || newNode->priceDifference > 0) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != NULL && current->next->priceDifference > 0) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }
    void dequeue() {
        if (head == NULL) {
            cout << "Queue is empty." << endl;
            return;
        } else {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Stock Deleted." << endl;
        }
    }
    void Details(Node* current) {
        while (current != NULL) {
            cout << "Stock Name: " << current->stockName << endl;
            cout << "Start Price: " << current->priceStart << endl;
            cout << "End Price: " << current->priceEnd << endl;
            cout << "Price Difference: " << current->priceDifference << endl;
            float percentage = (current->priceDifference / current->priceStart) * 100;
            if (current->priceDifference > 0) {
                cout << "$$ PROFIT $$: " << percentage << "%" << endl;
            } else {
                cout << "LOSS: " << percentage << "%" << endl;
            }
            cout << "------------------------" << endl;
            current = current->next; 
        }
    }
    void swap(Node* a, Node* b) {
        std::swap(a->stockName, b->stockName);
        std::swap(a->priceStart, b->priceStart);
        std::swap(a->priceEnd, b->priceEnd);
        std::swap(a->priceDifference, b->priceDifference);
    }
    void bubbleSort() {
        if (!head) return; // If the list is empty
        bool swapped;
        do {
            swapped = false;
            Node* current = head;
            while (current && current->next) {
                if (current->priceDifference < current->next->priceDifference) { // Sort in descending order
                    swap(current, current->next);
                    swapped = true;
                }
                current = current->next;
            }
        } while (swapped);
    }
    void displaySortedDetails() {
        bubbleSort(); 
        Details(head); // Display sorted details
        analyzeStocks(); // Perform analysis after displaying details
    }
    void analyzeStocks() {
        Node* current = head;
        int count = 0;
        float totalProfitLoss = 0.0;
        while (current != NULL) {
            totalProfitLoss += current->priceDifference;
            count++;
            current = current->next;
        }
        if (count > 0) {
            cout << "*******************" << endl; 
            cout << "Total Stocks: " << count << endl;
            float averageProfitLossPercentage = (totalProfitLoss / count); 
            cout << "Total Profit/Loss: $" << totalProfitLoss << endl;
            if (totalProfitLoss > 0) {
                cout << "$$ Total Profit $$: " 
                     << (averageProfitLossPercentage / count * 100) 
                     << "%" 
                     << endl; 
            } else if (totalProfitLoss < 0) {
                cout << "$$ Total Loss $$: "
                     << (-averageProfitLossPercentage / count * 100)
                     << "%"
                     << endl; 
            } else {
                cout << "No Profit or Loss." << endl; 
            }
            cout << "*******************" << endl;
        } else {
            cout << "No stocks available for analysis." << endl; 
        }
    }
};
int main() {
    Stock st;
    int choice;
    bool flag = true;
 cout<<"**STOCK MONITORING SYSTEM**\n";
    while (flag) {
        cout << "Enter 1 to Add a new Stock" << endl;
        cout << "Enter 2 to Sell the Stock" << endl;
        cout << "Enter 3 to Display All Stocks Sorted by Profit and Analysis" << endl; // Updated option
        cout << "Enter any other number to exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
        cout<<endl;
        switch (choice) {
            case 1: {
                string stock;
                float a, b;
                cout << "Enter Name of the Stock: ";
                getline(cin, stock);
                cout << "Enter price at Start of the day: ";
                cin >> a;
                cout << "Enter price at End of the day: ";
                cin >> b;
                st.enqueue(stock, a, b);
                break;
            }
            case 2:
                st.dequeue();
                break;

            case 3:
                st.displaySortedDetails(); 
                break;

            default:
                flag = false; 
                break;
        }
        if(flag==false) break;
    }
    return 0; 
}