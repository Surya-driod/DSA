#include <iostream>
#include <vector>
using namespace std;

bool saf(int row, int col, vector<string>& brd, int n) {
    // Check upper column
    for (int i = 0; i < row; i++) {
        if (brd[i][col] == 'Q') return false;
    }

    // Check upper left diag
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (brd[i][j] == 'Q') return false;
    }

    // Check upper right diag
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
        if (brd[i][j] == 'Q') return false;
    }

    return true;
}

bool sol(int row, vector<string>& brd, int n) {
    if (row == n) {
        for (int i = 0; i < n; i++) {
            cout << brd[i] << endl;
        }
        cout << endl;
        return true;  // return false here if you want all solutions
    }

    for (int col = 0; col < n; col++) {
        if (saf(row, col, brd, n)) {
            brd[row][col] = 'Q';
            if (sol(row + 1, brd, n)) return true;
            brd[row][col] = '.';
        }
    }

    return false;
}

int main() {
    int n;
    cout << "Enter board size (n): ";
    cin >> n;

    vector<string> brd(n, string(n, '.'));
    if (!sol(0, brd, n)) {
        cout << "No solution found.\n";
    }

    return 0;
}
