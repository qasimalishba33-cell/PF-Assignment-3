#include <iostream>
using namespace std;

bool isPrimeNum(int x) {
    if (x <= 1) return false;
    for (int j = 2; j * j <= x; j++) {
        if (x % j == 0) return false;
    }
    return true;
}

// Function to find which number goes at position (row, col) in spiral
int getNumberAtPosition(int n, int row, int col) {
    int layer = min(min(row, col), min(n - 1 - row, n - 1 - col));
    
    // Numbers already filled in outer layers
    int numsFilled = 0;
    for (int i = 0; i < layer; i++) {
        int sideLength = n - 2 * i;
        numsFilled += 4 * sideLength - 4;
    }
    
    // Current layer dimensions
    int top = layer;
    int bottom = n - 1 - layer;
    int left = layer;
    int right = n - 1 - layer;
    
    // Starting number for this layer (counting down from n*n)
    int startNum = n * n - numsFilled;
    
    // Position within the layer
    if (row == top) {
        // Top row, moving right
        return startNum - (col - left);
    } else if (col == right) {
        // Right column, moving down
        return startNum - (right - left) - (row - top);
    } else if (row == bottom) {
        // Bottom row, moving left
        return startNum - (right - left) - (bottom - top) - (right - col);
    } else {
        // Left column, moving up
        return startNum - (right - left) - (bottom - top) - (right - left) - (bottom - row);
    }
}

int main() {
    int n;
    cout << "Enter N: ";
    cin >> n;

    cout << endl;
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            int num = getNumberAtPosition(n, r, c);
            char ch;
            
            if (num == 1) {
                ch = '.';
            } else if (isPrimeNum(num)) {
                ch = 'P';
            } else {
                ch = 'C';
            }
            
            cout << ch;
            if (c < n - 1) cout << " ";
        }
        cout << endl;
    }

    return 0;
}
