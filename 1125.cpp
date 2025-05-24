#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, w;
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

struct DSU {
    vector<int> parent;
    DSU(int n) : parent(n+1) {
        for (int i = 0; i <= n; ++i) parent[i] = i;
    }
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    bool unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return false;
        parent[px] = py;
        // cout << py << " " << parent[px] << endl;
        return true;
    }
};

long long solve(int N, vector<Edge>& edges, int A, int B) {
    int extraNode = N+1;
    vector<Edge> all_edges = edges;
    all_edges.push_back({A, extraNode, 0});
    all_edges.push_back({B, extraNode, 0});

    sort(all_edges.begin(), all_edges.end());

    DSU dsu(N+1);
    long long total = 0, count = 0;
    for (auto& e : all_edges) {
        // cout << e.u << " " << e.v << " " << e.w << endl;
        if (dsu.unite(e.u, e.v)) {
            if (e.w > 0)
                total += e.w;
            count++;
            if (count == N) break; 
        }
    }
    return total;
}

int main() {
    int N, M, Q;
    cin >> N >> M;
    vector<Edge> edges(M);
    for (int i = 0; i < M; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }
    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        int A, B;
        cin >> A >> B;
        cout << solve(N, edges, A, B) << endl;
    }
    return 0;
}