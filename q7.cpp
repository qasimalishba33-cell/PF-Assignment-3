#include <iostream>
#include <string>
using namespace std;

int main() {
    int decimalNumber, base;

    // Input decimal number
    cout << "Enter Decimal Number: ";
    cin >> decimalNumber;

    // Input and validate base
    cout << "Enter Target Base (2-36): ";
    cin >> base;

    if (base < 2 || base > 36) {
        cout << "Invalid base! Please enter a base between 2 and 36." << endl;
        return 0;
    }

    // Conversion logic using WHILE loop
    int number = decimalNumber;
    string result = "";

    if (number == 0) {
        result = "0";
    } else {
        while (number > 0) {
            int remainder = number % base;
            char digit;

            if (remainder < 10)
                digit = '0' + remainder; // for 0-9
            else
                digit = 'A' + (remainder - 10); // for A-Z

            result = digit + result; // prepend the digit
            number /= base;
        }
    }

    // Display result
    cout << decimalNumber << " in Base " << base << " is: " << result << endl;

    return 0;
}