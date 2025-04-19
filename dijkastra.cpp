#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> pr;

void djk(int src, vector<vector<pr>> &adj, vector<int> &dis) {
    int n = adj.size();
    dis.assign(n, INT_MAX);
    dis[src] = 0;

    priority_queue<pr, vector<pr>, greater<pr>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        int dst = pq.top().second;
        int wgt = pq.top().first;
        pq.pop();

        if (wgt > dis[dst]) continue;

        for (auto &nbr : adj[dst]) {
            int nxt = nbr.first;
            int cost = nbr.second;

            if (dis[dst] + cost < dis[nxt]) {
                dis[nxt] = dis[dst] + cost;
                pq.push({dis[nxt], nxt});
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
    adj[1].push_back({2, 1});
    adj[1].push_back({3, 7});
    adj[2].push_back({4, 3});
    adj[3].push_back({4, 1});

    vector<int> dis;
    djk(0, adj, dis);

    for (int i = 0; i < vtx; ++i) {
        cout << "dis[" << i << "] = " << dis[i] << endl;
    }

    return 0;
}
