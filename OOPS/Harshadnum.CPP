#include <iostream>
using namespace std;

class Harshadnum{
private:
    int number;

public:
    // Constructor to initialize the number
    Harshadnum(int num) : number(num) {}

    // Method to calculate the sum of digits
    int sumOfDigits() {
        int sum = 0;
        int temp = number;

        while (temp > 0) {
            sum += temp % 10; // Add the last digit
            temp /= 10;       // Remove the last digit
        }
        return sum;
    }
    bool isHarshad() {
        int sum = sumOfDigits();
        return (sum != 0 && number % sum == 0); 
    }
};

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    Harshadnum checker(num);
    if (checker.isHarshad()) {
        cout << num << " is a Harshad number." << endl;
    } 
    else cout << num << " is not a Harshad number." << endl;
    

    return 0;
}