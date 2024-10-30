#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
void printBinary(unsigned int n, int bits) {
    for (int i = bits - 1; i >= 0; i--) {
        cout << ((n >> i) & 1);
    }
}
void printIEEE754(float number) {
    if (number == 0.0) {
        cout << "Sign: 0" << endl;
        cout << "Exponent: 00000000" << endl;
        cout << "Mantissa: 00000000000000000000000" << endl;
        return;
    }

    // Determine the sign
    int sign = (number < 0) ? 1 : 0;
    number = fabs(number); // Work with the absolute value

    // Find the exponent
    int exponent = 0;
    while (number >= 2.0) {
        number /= 2.0;
        exponent++;
    }
    while (number < 1.0) {
        number *= 2.0;
        exponent--;
    }
    // Adjust exponent for bias (127 for single precision)
    int biasedExponent = exponent + 127;
    // Calculate mantissa
    number -= 1.0; // Remove the leading 1
    unsigned int mantissa = 0;
    for (int i = 0; i < 23; i++) {
        number *= 2.0;
        if (number >= 1.0) {
            mantissa |= (1 << (22 - i)); 
            number -= 1.0; 
        }
    }

    cout << "Sign: " << sign << endl;
    cout << "Exponent: ";
    printBinary(biasedExponent, 8);
    cout << endl;
    cout << "Mantissa: ";
    printBinary(mantissa, 23);
    cout << endl;
}
int main() {
    float number = 3066.25;
    cout << "IEEE 754 representation of " << number << " is:" << endl;
    printIEEE754(number);
    return 0;
}
// #include <iostream>
// #include <cmath>
// #include <iomanip>
// using namespace std;
// void printBinary(unsigned long long n, int bits) {
//     for (int i = bits - 1; i >= 0; i--) {
//         cout << ((n >> i) & 1);
//     }
// }
// void printIEEE754(double number) {
//     // Handle special case for zero
//     if (number == 0.0) {
//         cout << "Sign: 0" << endl;
//         cout << "Exponent: 00000000000" << endl;
//         cout << "Mantissa: 0000000000000000000000000000000000000000000000000000" << endl;
//         return;
//     }
//     // Determine the sign
//     int sign = (number < 0) ? 1 : 0;
//     number = fabs(number);

//     // Find the exponent
//     int exponent = 0;
//     while (number >= 2.0) {
//         number /= 2.0;
//         exponent++;
//     }
//     while (number < 1.0) {
//         number *= 2.0;
//         exponent--;
//     }

//     // Adjust exponent for bias (1023 for double precision)
//     int biasedExponent = exponent + 1023;

//     // Calculate mantissa
//     number -= 1.0; 
//     unsigned long long mantissa = 0;
//     for (int i = 0; i < 52; i++) {
//         number *= 2.0;
//         if (number >= 1.0) {
//             mantissa |= (1ULL << (51 - i)); 
//             number -= 1.0; 
//         }
//     }
//     // Print the results
//     cout << "Sign: " << sign << endl;
//     cout << "Exponent: ";
//     printBinary(biasedExponent, 11);
//     cout << endl;
//     cout << "Mantissa: ";
//     printBinary(mantissa, 52);
//     cout << endl;
// }
// int main() {
//     double number = 3066.25; // Example number
//     cout << "IEEE 754 representation of " << number << " is:" << endl;
//     printIEEE754(number);
//     return 0;
// }
