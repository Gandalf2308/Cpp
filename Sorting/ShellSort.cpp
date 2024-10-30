#include <iostream>
using namespace std;
int main() {
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout << "Original array: ";
    for (int i=0;i<n;i++) {
        cout << arr[i] << " ";
    }
cout<<endl;    
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;       
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
          cout << "Pass " << gap << ": ";
        for (int k = 0; k < n; k++) {
            cout << arr[k] << " "; 
        }
        cout<<endl;
    }
    cout << "Sorted array: ";
 for (int i=0;i<n;i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}