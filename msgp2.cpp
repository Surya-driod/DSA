#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class mgp {
public:
    int vtx;
    vector<vector<pair<int, int>>> adj;

    mgp(int v) {
        vtx = v;
        adj.resize(vtx);
    }

    void add(int u, int v, int w) {
        adj[u].push_back({v, w});
    }

    void spf(int src, int snk) {
        vector<int> cst(vtx, INT_MAX);
        vector<int> pth(vtx, -1);

        cst[snk] = 0;

        for (int i = vtx - 1; i >= 0; i--) {
            for (auto edg : adj[i]) {
                int v = edg.first;
                int w = edg.second;
                if (cst[v] != INT_MAX && cst[i] > w + cst[v]) {
                    cst[i] = w + cst[v];
                    pth[i] = v;
                }
            }
        }

        cout << "min cost: " << cst[src] << endl;
        cout << "path: ";
        int n = src;
        while (n != -1) {
            cout << n << " ";
            n = pth[n];
        }
        cout << endl;
    }
};

int main() {
    int vtx = 8;
    mgp g(vtx);

    g.add(0, 1, 1);
    g.add(0, 2, 2);
    g.add(1, 3, 2);
    g.add(1, 4, 3);
    g.add(2, 5, 2);
    g.add(3, 6, 3);
    g.add(4, 6, 2);
    g.add(5, 6, 1);
    g.add(6, 7, 1);

    int src = 0, snk = 7;
    g.spf(src, snk);

    return 0;
}
