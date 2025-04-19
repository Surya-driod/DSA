#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> pr;

void prm(int src, vector<vector<pr>> &adj, vector<bool> &vis, vector<int> &key, vector<int> &par) {
    int n = adj.size();
    key.assign(n, INT_MAX);
    par.assign(n, -1);
    vis.assign(n, false);

    priority_queue<pr, vector<pr>, greater<pr>> pq;
    key[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (vis[u]) continue;
        vis[u] = true;

        for (auto &nbr : adj[u]) {
            int v = nbr.first;
            int w = nbr.second;

            if (!vis[v] && w < key[v]) {
                key[v] = w;
                par[v] = u;
                pq.push({key[v], v});
            }
        }
    }
}

int main() {
    int vtx = 5;
    vector<vector<pr>> adj(vtx);

    // Example edges: (u, v, w)
    adj[0].push_back({1, 2});
    adj[0].push_back({2, 4});
    adj[1].push_back({0, 2});
    adj[1].push_back({2, 1});
    adj[1].push_back({3, 7});
    adj[2].push_back({0, 4});
    adj[2].push_back({1, 1});
    adj[2].push_back({4, 3});
    adj[3].push_back({1, 7});
    adj[3].push_back({4, 1});
    adj[4].push_back({2, 3});
    adj[4].push_back({3, 1});

    vector<bool> vis;
    vector<int> key, par;
    prm(0, adj, vis, key, par);

    int sum = 0;
    for (int i = 1; i < vtx; ++i) {
        cout << "use (" << par[i] << "," << i << ") w=" << key[i] << endl;
        sum += key[i];
    }

    cout << "tot = " << sum << endl;
    return 0;
}
