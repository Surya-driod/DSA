#include <iostream>
using namespace std;

int get_max_row(int mat[][4], int row, int col) {
    int idx = 0;
    for (int i = 1; i < row; i++) {
        if (mat[i][col] > mat[idx][col]) {
            idx = i;
        }
    }
    return idx;
}

pair<int, int> find_peak(int mat[][4], int row, int col) {
    int low = 0, hig = col - 1;

    while (low <= hig) {
        int mid = low + (hig - low) / 2;
        int r = get_max_row(mat, row, mid);

        int lft = (mid == 0) ? -1 : mat[r][mid - 1];
        int rit = (mid == col - 1) ? -1 : mat[r][mid + 1];

        if (mat[r][mid] >= lft && mat[r][mid] >= rit) {
            return {r, mid};
        }
        else if (lft > mat[r][mid]) {
            hig = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return {-1, -1};
}

int main() {
    int mat[4][4] = {
        {10, 8, 10, 10},
        {14, 13, 12, 11},
        {15, 9, 11, 21},
        {16, 17, 19, 20}
    };

    pair<int, int> pos = find_peak(mat, 4, 4);
    cout << "2D peak at row: " << pos.first << ", col: " << pos.second
         << ", val: " << mat[pos.first][pos.second] << endl;

    return 0;
}
