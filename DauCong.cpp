#include <iostream>
#include <vector>

using namespace std;

void print_cross(int n){
    int size = 2 * n + 1;
    vector<vector<char>> grid(size,vector<char>(size, ' '));

    // Fill the cross with '+'
    for (int i=0; i<size; ++i){
        grid[n][i]= '+';
        grid[i][n]= '+';
    }

    // Print the grid
    for (int i=0; i<size; ++i){
        for (int j=0; j<size; ++j){
            cout << grid[i][j];
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    print_cross(n);

    return 0;
}
