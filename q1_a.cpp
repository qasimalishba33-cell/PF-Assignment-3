#include <iostream>
using namespace std;

int main() {
    int target, l1 = 2, l2 = 1, acc = 21, next;
    bool found = false;
    
    cout << "Enter a number to check: ";
    cin >> target;
    
    if (target == 2 || target == 1) {
        found = true;
        if (target == 2) acc = 2;
    } else {
        next = l1 + l2;
        while (next <= target) {
            int temp = next, mult = 1;
            while (temp > 0) {
                mult *= 10;
                temp /= 10;
            }
            acc = acc * mult + next;
            
            if (next == target) {
                found = true;
                break;
            }
            l1 = l2;
            l2 = next;
            next = l1 + l2;
        }
    }
    
    if (found) {
        cout << "Number: " << acc << endl;
        cout << "Pattern:" << endl;
        
        int size = acc % target;
        if (size < 3) size = 5;
        if (size % 2 == 0) size++;
        
        int digitCount = 0, temp = acc;
        while (temp > 0) {
            digitCount++;
            temp /= 10;
        }
        
        int row = 1;
        while (row <= size) {
            int s = 0;
            while (s++ < size - row) cout << " ";
            
            int n = 0, pos = 0;
            while (n++ < 2 * row - 1) {
                int div = 1, p = 0, idx = digitCount - 1 - (pos++ % digitCount);
                while (p++ < idx) div *= 10;
                cout << (acc / div) % 10;
            }
            cout << endl;
            row++;
        }
        
        row = size - 1;
        while (row >= 1) {
            int s = 0;
            while (s++ < size - row) cout << " ";
            
            int n = 0, pos = 0;
            while (n++ < 2 * row - 1) {
                int div = 1, p = 0, idx = digitCount - 1 - (pos++ % digitCount);
                while (p++ < idx) div *= 10;
                cout << (acc / div) % 10;
            }
            cout << endl;
            row--;
        }
    } else {
        cout << target << " is not in the Lucas Sequence." << endl;
    }
    
    return 0;
}