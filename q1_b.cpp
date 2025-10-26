#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    // Step 1: Generate Tribonacci sequence
    int t1 = 0, t2 = 0, t3 = 1;
    int sum = 0;
    bool isTribonacci = false;
    int count = 0; // count of terms printed

    cout << "Tribonacci sequence up to " << n << ": ";

    while (t1 <= n) {
        cout << t1;
        // print comma only if next printed term will still be <= n
        // We'll just decide by peeking next value:
        int nextPeek = t1 + t2 + t3;
        if (nextPeek <= n) cout << ", ";

        sum += t1;
        count++;               // increment terms count
        if (t1 == n) isTribonacci = true;

        int next = t1 + t2 + t3;
        t1 = t2;
        t2 = t3;
        t3 = next;
    }

    cout << endl;

    if (!isTribonacci) {
        cout << n << " is NOT a Tribonacci number!" << endl;
        return 0;
    }

    cout << "Accumulated Sum (S): " << sum << endl;
    cout << "Pattern:" << endl;

    // Convert sum to string to easily access digits
    string s = to_string(sum);
    int len = (int)s.length();

    // Step 4: Right-aligned triangle
    int i = 1;
    while (i <= count) {               // rows = number of tribonacci terms
        int space = count - i;         // leading spaces for right alignment
        while (space > 0) {
            cout << " ";
            space--;
        }

        int j = 0;
        while (j < i) {               // print exactly i digits for row i
            cout << s[j % len];       // cycle through digits if needed
            j++;
        }

        cout << endl;
        i++;
    }

    return 0;
}
