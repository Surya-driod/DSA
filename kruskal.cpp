#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct edg {
    int u, v, w;
};

bool cmp(edg a, edg b) {
    return a.w < b.w;
}

struct dsu {
    vector<int> par;

    dsu(int n) {
        par.resize(n);
        for (int i = 0; i < n; ++i) par[i] = i;
    }

    int fnd(int x) {
        if (par[x] == x) return x;
        return par[x] = fnd(par[x]);
    }

    bool uni(int a, int b) {
        int pa = fnd(a), pb = fnd(b);
        if (pa == pb) return false;
        par[pa] = pb;
        return true;
    }
};

int main() {
    int vtx = 5;
    vector<edg> edg_lst = {
        {0, 1, 2},
        {0, 2, 4},
        {1, 2, 1},
        {1, 3, 7},
        {2, 4, 3},
        {3, 4, 1}
    };

    sort(edg_lst.begin(), edg_lst.end(), cmp);
    dsu d(vtx);
    int sum = 0;

    for (auto &e : edg_lst) {
        if (d.uni(e.u, e.v)) {
            sum += e.w;
            cout << "use (" << e.u << "," << e.v << ") w=" << e.w << endl;
        }
    }

    cout << "tot = " << sum << endl;
    return 0;
}
