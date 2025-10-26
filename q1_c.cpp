

#include <iostream>
using namespace std;

int main() {
    long long num;
    cout << "Enter the Catalan code: ";
    cin >> num;

    // Step 1: Generate Catalan numbers
    long long catalan = 1; // C0 = 1
    int n = 0;
    bool found = false;

    while (catalan <= num) {
        if (catalan == num) {
            found = true;
            break;
        }
        n++;
        catalan = catalan * 2 * (2 * n - 1) / (n + 1);
    }

    // Step 2: Check if found
    if (!found) {
        cout << "The number is NOT a Catalan number." << endl;
        return 0;
    }

    cout << "Catalan Index (n): " << n << endl;
    cout << "Pattern:" << endl;

    int totalRows = n * 2 + 1;  // full height of hourglass
    int row = 0;

    // Step 3: Hourglass pattern (hollow)
    while (row < totalRows) {
        int col = 0;
        while (col < totalRows) {
            if (row == col || row + col == totalRows - 1 || row == 0 || row == totalRows - 1)
                cout << "#";
            else
                cout << " ";
            col++;
        }
        cout << endl;
        row++;
    }

    return 0;
}
