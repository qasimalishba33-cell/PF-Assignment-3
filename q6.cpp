#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size (N): ";
    cin >> n;
    
    int size = 2 * n + 1;
    int center = n;
    
    int row = 0;
    while (row < size) {
        int col = 0;
        while (col < size) {
            // Calculate distances from center
            int rowDist = abs(row - center);
            int colDist = abs(col - center);
            int manhattanDist = rowDist + colDist;
            
            // First diamond: traditional diamond shape (Manhattan distance = n)
            bool onDiamond1 = (manhattanDist == n);
            
            // Second diamond: cross/plus pattern through center
            bool onDiamond2 = (row == center && colDist == n) || 
                             (col == center && rowDist == n);
            
            // Check for intersection points
            bool isIntersection = false;
            
            // Intersections occur where both diamonds meet
            if ((row == center - n && col == center) || // top of vertical
                (row == center + n && col == center) || // bottom of vertical
                (row == center && col == center - n) || // left of horizontal
                (row == center && col == center + n)) { // right of horizontal
                isIntersection = true;
            }
            
            // Determine output character
            char output;
            if (isIntersection) {
                output = '+';
            } else if (onDiamond1 || onDiamond2) {
                output = '#';
            } else {
                output = '.';
            }
            
            cout << output;
            col++;
        }
        cout << endl;
        row++;
    }
    
    return 0;
}