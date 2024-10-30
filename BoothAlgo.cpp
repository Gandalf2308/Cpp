#include <iostream>
#include <bitset>

using namespace std;

void nonRestoringDivision(int dividend, int divisor, int &quotient, int &remainder) {
    int n = 4; // We are using 4-bit integers
    remainder = 0;
    quotient = 0;

    for (int i = n - 1; i >= 0; --i) {
        // Shift remainder left and bring down the next bit of the dividend
        remainder = (remainder << 1) | ((dividend >> i) & 1);

        // Subtract divisor from remainder
        remainder -= divisor;

        if (remainder < 0) {
            // If remainder is negative, restore it and set quotient bit to 0
            remainder += divisor;
        } else {
            // If remainder is positive, set quotient bit to 1
            quotient |= (1 << i);
        }
    }
}

int main() {
    int dividend = 10;  
    int divisor = 3;   
    int quotient, remainder;

    cout << "Dividend: " << dividend << " (" << bitset<4>(dividend) << ")" << endl;
    cout << "Divisor: " << divisor << " (" << bitset<4>(divisor) << ")" << endl;

    nonRestoringDivision(dividend, divisor, quotient, remainder);

    cout << "Quotient: " << quotient << " (" << bitset<4>(quotient) << ")" << endl;
    cout << "Remainder: " << remainder << " (" << bitset<4>(remainder) << ")" << endl;

    return 0;
}
// #include <iostream>
// #include <bitset>

// using namespace std;

// void restoringDivision(int dividend, int divisor, int &quotient, int &remainder) {
//     int n = 4; // We are using 4-bit integers
//     remainder = 0;
//     quotient = 0;

//     for (int i = n - 1; i >= 0; --i) {
//         // Shift remainder left and bring down the next bit of the dividend
//         remainder = (remainder << 1) | ((dividend >> i) & 1);

//         // Subtract divisor from remainder
//         remainder -= divisor;

//         if (remainder < 0) {
//             // If remainder is negative, restore it and set quotient bit to 0
//             remainder += divisor;
//         } else {
//             // If remainder is non-negative, set quotient bit to 1
//             quotient |= (1 << i);
//         }
//     }
// }

// int main() {
//     int dividend = 11;  // Example dividend
//     int divisor = 7;    // Example divisor
//     int quotient, remainder;

//     cout << "Dividend: " << dividend << " (" << bitset<4>(dividend) << ")" << endl;
//     cout << "Divisor: " << divisor << " (" << bitset<4>(divisor) << ")" << endl;

//     restoringDivision(dividend, divisor, quotient, remainder);

//     cout << "Quotient: " << quotient << " (" << bitset<4>(quotient) << ")" << endl;
//     cout << "Remainder: " << remainder << " (" << bitset<4>(remainder) << ")" << endl;

//     return 0;
// }