#include <iostream>
using namespace std;

int main() {
    // Simple pseudo-random generator using arithmetic (no rand or time)
    // We'll base it on user input + loop counter to make it seem random
    int seed;
    cout << "🦁 The Sphinx's Challenge 🦁" << endl;
    cout << "Enter any number to begin your fate: ";
    cin >> seed;

    // Generate pseudo-random digits (1-6)
    int d1 = (seed * 37 + 11) % 6 + 1;
    int d2 = (seed * 53 + 7) % 6 + 1;
    int d3 = (seed * 29 + 19) % 6 + 1;
    int d4 = (seed * 97 + 23) % 6 + 1;

    cout << "\nCrack the 4-digit code (digits 1-6)!" << endl;
    cout << "You have 5 attempts. Good luck, adventurer!\n" << endl;

    int attempt = 1;
    bool solved = false;

    while (attempt <= 5 && !solved) {
        int g1, g2, g3, g4;
        cout << "Attempt " << attempt << "/5 - Enter your guess (4 digits, space-separated): ";
        cin >> g1 >> g2 >> g3 >> g4;

        // Validate input
        if (g1 < 1 || g1 > 6 || g2 < 1 || g2 > 6 || g3 < 1 || g3 > 6 || g4 < 1 || g4 > 6) {
            cout << "❌ Invalid input! Use digits 1-6 only.\n" << endl;
            continue;
        }

        // Black pegs: correct digit & correct position
        int blackPegs = 0;
        bool match1 = false, match2 = false, match3 = false, match4 = false;

        if (g1 == d1) { blackPegs++; match1 = true; }
        if (g2 == d2) { blackPegs++; match2 = true; }
        if (g3 == d3) { blackPegs++; match3 = true; }
        if (g4 == d4) { blackPegs++; match4 = true; }

        // White pegs: correct digit, wrong position
        int whitePegs = 0;
        bool used1 = match1, used2 = match2, used3 = match3, used4 = match4;

        if (!match1) {
            if (g1 == d2 && !used2) { whitePegs++; used2 = true; }
            else if (g1 == d3 && !used3) { whitePegs++; used3 = true; }
            else if (g1 == d4 && !used4) { whitePegs++; used4 = true; }
        }

        if (!match2) {
            if (g2 == d1 && !used1) { whitePegs++; used1 = true; }
            else if (g2 == d3 && !used3) { whitePegs++; used3 = true; }
            else if (g2 == d4 && !used4) { whitePegs++; used4 = true; }
        }

        if (!match3) {
            if (g3 == d1 && !used1) { whitePegs++; used1 = true; }
            else if (g3 == d2 && !used2) { whitePegs++; used2 = true; }
            else if (g3 == d4 && !used4) { whitePegs++; used4 = true; }
        }

        if (!match4) {
            if (g4 == d1 && !used1) { whitePegs++; used1 = true; }
            else if (g4 == d2 && !used2) { whitePegs++; used2 = true; }
            else if (g4 == d3 && !used3) { whitePegs++; used3 = true; }
        }

        cout << "⚫ Black Pegs: " << blackPegs << " | ⚪ White Pegs: " << whitePegs << endl;

        if (blackPegs == 4) {
            cout << "\n🎉 Victory! You cracked the Sphinx's code in " << attempt << " attempts!" << endl;
            cout << "The secret code was: " << d1 << d2 << d3 << d4 << endl;
            solved = true;
        } else {
            cout << endl;
        }

        attempt++;
    }

    if (!solved) {
        cout << "💀 The Sphinx claims another soul..." << endl;
        cout << "The secret code was: " << d1 << d2 << d3 << d4 << endl;
    }

    return 0;
}
 