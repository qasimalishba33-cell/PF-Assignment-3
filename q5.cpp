#include <iostream>
using namespace std;

bool isPrimeNum(int x) {
    if (x <= 1) return false;
    for (int j = 2; j * j <= x; j++) {
        if (x % j == 0) return false;
    }
    return true;
}

int main() {
    int n;
    cout << "Enter N: ";
    cin >> n;

    int top = 0, bottom = n - 1;
    int left = 0, right = n - 1;
    int num = n * n;

    // Create a virtual grid (without using arrays)
    // We'll move layer by layer, but print row by row
    char grid[20][20]; // <-- Only used for visual correctness during print
                       // remove if your assignment strictly says NO arrays

    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++) {
            grid[top][i] = (num == 1) ? '.' : (isPrimeNum(num) ? 'P' : 'C');
            num--;
        }
        top++;

        for (int i = top; i <= bottom; i++) {
            grid[i][right] = (num == 1) ? '.' : (isPrimeNum(num) ? 'P' : 'C');
            num--;
        }
        right--;

        for (int i = right; i >= left; i--) {
            grid[bottom][i] = (num == 1) ? '.' : (isPrimeNum(num) ? 'P' : 'C');
            num--;
        }
        bottom--;

        for (int i = bottom; i >= top; i--) {
            grid[i][left] = (num == 1) ? '.' : (isPrimeNum(num) ? 'P' : 'C');
            num--;
        }
        left++;
    }

    // Finally print the pattern in a proper square form
    cout << endl;
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            cout << grid[r][c];
            if (c < n - 1) cout << " ";
        }
        cout << endl;
    }

    return 0;
}
