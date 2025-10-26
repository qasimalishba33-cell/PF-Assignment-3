#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size N: ";
    cin >> n;
    
    // SECTION 1: Upper pyramid with numbers (rows /1\ to /n\)
    int row = 1;
    while (row <= n) {
        // Leading spaces
        int spaces = n - row;
        int s = 0;
        while (s < spaces) {
            cout << " ";
            s++;
        }
        
        // Left slash and number
        cout << "/" << row << "\\";
        
        // Trailing spaces for right number
        int rightSpaces = (row - 1) * 2;
        int rs = 0;
        while (rs < rightSpaces) {
            cout << " ";
            rs++;
        }
        
        // Right number (only if not first row)
        if (row > 1) {
            cout << row << "\\";
        }
        
        cout << endl;
        row++;
    }
    
    // SECTION 2: Top border with carets
    int spaces = 0;
    int s = 0;
    while (s < spaces) {
        cout << " ";
        s++;
    }
    cout << "[*";
    int i = 0;
    while (i < n * 8) {
        cout << "^";
        i++;
    }
    cout << "*]" << endl;
    
    // SECTION 3: Upper internal rows with patterns
    int inRow = 1;
    while (inRow <= n - 1) {
        cout << "[* <";
        
        // Pattern varies by row
        if (inRow == 1) {
            // Row with stars
            int st = 0;
            while (st < n * 3) {
                cout << "*";
                st++;
            }
            cout << " ";
            
            // Middle spaces
            int ms = 0;
            while (ms < n * 2) {
                cout << " ";
                ms++;
            }
            
            // Right stars
            st = 0;
            while (st < n * 3) {
                cout << "*";
                st++;
            }
        } else if (inRow == n / 2) {
            // Middle row with circle
            int leftDots = 0;
            while (leftDots < n * 2) {
                cout << "*";
                leftDots++;
            }
            cout << " *";
            
            // Spaces before circle
            int sp = 0;
            while (sp < n) {
                cout << " ";
                sp++;
            }
            cout << "o";
            
            // Spaces after circle
            sp = 0;
            while (sp < n) {
                cout << " ";
                sp++;
            }
            
            cout << "* ";
            
            // Right dots
            int rightDots = 0;
            while (rightDots < n * 2) {
                cout << "*";
                rightDots++;
            }
        } else {
            // Rows with single dots
            int d = 0;
            while (d < n * 3) {
                cout << " ";
                d++;
            }
            cout << "*";
            
            // Middle spaces
            int ms = 0;
            while (ms < n * 2 + 1) {
                cout << " ";
                ms++;
            }
            
            // Right dot
            cout << "*";
            
            d = 0;
            while (d < n * 3) {
                cout << " ";
                d++;
            }
        }
        
        cout << " > *]" << endl;
        inRow++;
    }
    
    // SECTION 4: Bottom border with vvv
    cout << "[*";
    i = 0;
    while (i < n * 8) {
        cout << "v";
        i++;
    }
    cout << "*]" << endl;
    
    // SECTION 5: Lower pyramid with numbers (rows \n/ to \1/)
    row = n;
    while (row >= 1) {
        // Leading spaces
        spaces = n - row;
        s = 0;
        while (s < spaces) {
            cout << " ";
            s++;
        }
        
        // Left number and slash
        cout << "\\" << row;
        
        // Middle spaces
        int midSpaces = (row - 1) * 2;
        int ms = 0;
        while (ms < midSpaces) {
            cout << " ";
            ms++;
        }
        
        // Right slash and number
        if (row > 1) {
            cout << row;
        }
        cout << "/";
        
        cout << endl;
        row--;
    }
    
    return 0;
}