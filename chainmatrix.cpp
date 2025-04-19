#include <iostream>
#include <vector>
#include <climits>
#include <functional>

using namespace std;

void mcm(vector<int> &p) {
    int n = p.size() - 1;
    vector<vector<int>> dp(n, vector<int>(n, 0));
    vector<vector<int>> cut(n, vector<int>(n, -1));

    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; ++k) {
                int val = dp[i][k] + dp[k+1][j] + p[i]*p[k+1]*p[j+1];
                if (val < dp[i][j]) {
                    dp[i][j] = val;
                    cut[i][j] = k;
                }
            }
        }
    }

    cout << "min ops = " << dp[0][n-1] << endl;

    // print optimal parenthesization
    function<void(int, int)> par = [&](int i, int j) {
        if (i == j) {
            cout << "A" << i+1;
            return;
        }
        cout << "(";
        par(i, cut[i][j]);
        par(cut[i][j]+1, j);
        cout << ")";
    };

    cout << "opt = ";
    par(0, n-1);
    cout << endl;
}

int main() {
    // Example input: matrix A1(30x35), A2(35x15), A3(15x5), A4(5x10), A5(10x20), A6(20x25)
    vector<int> p = {30, 35, 15, 5, 10, 20, 25}; // 6 matrices
    mcm(p);
    return 0;
}
