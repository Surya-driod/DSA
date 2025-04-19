#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int tsp(int n, vector<vector<int>> &dis) {
    int msk_sz = 1 << n;
    vector<vector<int>> dp(msk_sz, vector<int>(n, INT_MAX));

    dp[1][0] = 0; // start at city 0 with mask 000...1

    for (int msk = 1; msk < msk_sz; ++msk) {
        for (int u = 0; u < n; ++u) {
            if (!(msk & (1 << u))) continue; // u not in mask
            for (int v = 0; v < n; ++v) {
                if (msk & (1 << v)) continue; // v already visited
                int nxt = msk | (1 << v);
                if (dp[msk][u] + dis[u][v] < dp[nxt][v]) {
                    dp[nxt][v] = dp[msk][u] + dis[u][v];
                }
            }
        }
    }

    int ans = INT_MAX;
    for (int i = 1; i < n; ++i) {
        if (dp[msk_sz - 1][i] + dis[i][0] < ans) {
            ans = dp[msk_sz - 1][i] + dis[i][0];
        }
    }

    return ans;
}

int main() {
    // Example: 4 cities with distances
    vector<vector<int>> dis = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    int res = tsp(dis.size(), dis);
    cout << "min cost = " << res << endl;
    return 0;
}
