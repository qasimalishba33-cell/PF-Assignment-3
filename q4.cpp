#include <iostream>
using namespace std;

int main() {
    int N, K;
    cout << "Enter the number of people (N): ";
    cin >> N;
    cout << "Enter the step (K): ";
    cin >> K;

    // Create an array to mark eliminated people
    int people[1000];  // supports up to 1000 people (can adjust)
    int i = 0;

    // Initialize all people as alive (1)
    while (i < N) {
        people[i] = 1;
        i++;
    }

    int alive = N;      // total remaining people
    int index = 0;      // current position
    int count = 0;      // counter for step

    // Keep eliminating until only 2 remain
    while (alive > 2) {
        if (people[index] == 1) { // if person is still alive
            count++;
            if (count == K) {     // eliminate this person
                people[index] = 0;
                alive--;
                count = 0;        // reset counter
            }
        }
        index++;                  // move to next person
        if (index == N) index = 0; // wrap around the circle
    }

    // Display the two survivors (1-based positions)
    cout << "The two last companions are at positions: ";

    int j = 0;
    int first = -1, second = -1;
    while (j < N) {
        if (people[j] == 1) {
            if (first == -1)
                first = j + 1;
            else
                second = j + 1;
        }
        j++;
    }

    cout << first << " and " << second << endl;

    return 0;
}
