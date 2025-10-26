#include <iostream>
#include <cmath>   // for abs()
using namespace std;

int main() {
    int n;
    cout << "Enter odd side length (N): ";
    cin >> n;

    // Ensure N is odd
    if (n % 2 == 0) {
        cout << "Please enter an odd number!" << endl;
        return 0;
    }

    int center = n / 2;  // center index

    // Generate N x N pattern
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // Manhattan distance formula
            int distance = abs(i - center) > abs(j - center) ? abs(i - center) : abs(j - center);
            cout << distance << " ";
        }
        cout << endl;
    }

    return 0;
}
