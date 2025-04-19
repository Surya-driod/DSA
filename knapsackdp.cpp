#include <iostream>
#include <vector>
using namespace std;

int kns(int n, int w, vector<int> &wt, vector<int> &val) {
    vector<vector<int>> dp(n + 1, vector<int>(w + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= w; ++j) {
            if (wt[i-1] <= j)
                dp[i][j] = max(dp[i-1][j], val[i-1] + dp[i-1][j - wt[i-1]]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    return dp[n][w];
}

int main() {
    // Example: 4 items, capacity = 7
    vector<int> wt = {1, 3, 4, 5};
    vector<int> val = {1, 4, 5, 7};
    int W = 7;

    int res = kns(wt.size(), W, wt, val);
    cout << "max val = " << res << endl;
    return 0;
}
