#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int n, m, u, v;

vector<vector<int>> graph(200005);

struct DSU {
    vector<int> parent;
    vector<int> size;
    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
        }
    }

    int getSize(int x) {
        return size[find(x)];
    }
};


long long total(int n) {
    return (1LL * n * (n - 1)) / 2;
}

int main() {
    cin >> n >> m;
    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        edges[i] = {u, v};
    }

    DSU dsu(n);
    vector<ll> ans(m + 1);
    ll dis_pairs = total(n);

    for (int i = m - 1; i >= 0; i--) {
        ans[i] = dis_pairs;
        u = edges[i].first;
        v = edges[i].second;

        if (dsu.find(u) == dsu.find(v)) 
            continue;

        int size_u = dsu.getSize(u);
        int size_v = dsu.getSize(v);

        dis_pairs -= (1LL * size_u * size_v);

        dsu.unionSets(u, v);
    }

    for (int i = 0; i < m; i++) 
        cout << ans[i] << '\n';    
    return 0;
}