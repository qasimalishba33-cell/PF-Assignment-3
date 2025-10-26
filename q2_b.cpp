#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N;
    cout << "Enter odd side length (N): ";
    cin >> N;

    // Ensure N is odd
    if (N % 2 == 0) {
        cout << "Please enter an odd number." << endl;
        return 0;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            // Distance from main diagonal (i == j)
            int distMain = abs(i - j);
            // Distance from anti-diagonal (i + j == N - 1)
            int distAnti = abs(i + j - (N - 1));
            // Print the minimum of the two distances
            cout << min(distMain, distAnti) << " ";
        }
        cout << endl;
    }

    return 0;
}
