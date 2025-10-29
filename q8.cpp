7#include <iostream>
using namespace std;

int main() {
    int N;
    cout << "Enter size of the fish (N): ";
    cin >> N;

    // Upper half of the fish (diamond body)
    for (int i = 1; i <= N; i++) {
        // Leading spaces (to center the fish)
        for (int j = i; j < N; j++)
            cout << " ";

        // Body of fish (left half)
        for (int j = 1; j <= (2 * i - 1); j++)
            cout << "*";

        // Tail connector space
        for (int j = 1; j <= N - i + 1; j++)
            cout << " ";

        // Tail (right triangle)
        for (int j = 1; j <= i; j++)
            cout << "*";

        cout << endl;
    }

    // Lower half of the fish
    for (int i = N - 1; i >= 1; i--) {
        // Leading spaces
        for (int j = N; j > i; j--)
            cout << " ";

        // Body of fish (left half)
        for (int j = 1; j <= (2 * i - 1); j++)
            cout << "*";

        // Tail connector space
        for (int j = 1; j <= N - i + 1; j++)
            cout << " ";

        // Tail (right triangle)
        for (int j = 1; j <= i; j++)
            cout << "*";

        cout << endl;
    }

    return 0;
}
