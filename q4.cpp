#include <iostream>
using namespace std;

// Josephus function: finds survivor position when eliminating every K-th person
int josephus(int n, int k) {
    if (n == 1)
        return 0;
    else
        return (josephus(n - 1, k) + k) % n;
}

int main() {
    int N, K;
    cout << "Enter the number of people (N): ";
    cin >> N;
    cout << "Enter the step (K): ";
    cin >> K;

    // Find the last survivor (when only 1 remains)
    int lastSurvivor = josephus(N, K) + 1; 
    
    // Survivor when reduced to 2 people
    int pos1 = josephus(N, K);
    
    int pos2 = josephus(N - 1, K);  
    
    // Adjust for the actual positions
    int survivor1 = (josephus(N, K) + 1);
    int survivor2 = (josephus(N - 1, K) + 1);
    
    // Ensure survivor2 accounts for wrap-around
    if (survivor2 >= survivor1) {
        survivor2++;
    }
    
    if (survivor1 > survivor2) {
        int temp = survivor1;
        survivor1 = survivor2;
        survivor2 = temp;
    }

    cout << "The two last companions are at positions: ";
    cout << survivor1 << " and " << survivor2 << endl;

    return 0;
}