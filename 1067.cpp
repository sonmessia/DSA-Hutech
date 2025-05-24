#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

bool found;

void dfs(const vector<pair<int, int>> &items, int idx, long long mulA, long long mulB, long long a, long long b, long long c)
{
    if (found)
        return;
    if (idx == items.size())
    {
        if ((a * mulA + b * mulB) % c == 0)
            found = true;
        return;
    }
    int x = items[idx].first, y = items[idx].second;

    for (int i = 0; i <= y; i++) {
        long long pa = 1;
        for (int j = 0; j < i; j++) {
            if (pa > 1e18 / x) {
                pa = 1e18;
                break;
            }
            pa *= x;
        }
        long long pb = 1;
        for (int j = 0; j < y - i; j++) {
            if (pb > 1e18 / x) {
                pb = 1e18;
                break;
            }
            pb *= x;
        }
        dfs(items, idx + 1, mulA * pa, mulB * pb, a, b, c);
        if (found)
            return;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    while (q--)
    {
        long long a, b, c;
        int n;
        cin >> a >> b >> c >> n;
        vector<pair<int, int>> items(n);

        for (int i = 0; i < n; i++)
            cin >> items[i].first >> items[i].second;
        found = false;
        dfs(items, 0, 1, 1, a, b, c);
        cout << (found ? "YES\n" : "NO\n");
    }
    //
    // while (q--) {
    // int a, b, c, n;
    // cin >> a >> b >> c >> n;
    //
    // vector<pair<int, int>> items(n);
    // for (int i = 0; i < n; i++) {
    // cin >> items[i].first >> items[i].second;
    // }
    //
    // queue<pair<int, int>> q;
    // vector<vector<bool>> visited(c, vector<bool>(c, false));
    //
    // q.push({a % c, b % c});
    // visited[a % c][b % c] = true;
    //
    // bool found = false;
    //
    // if ((a + b) % c == 0) {
    // found = true;
    // }
    //
    // while (!q.empty() && !found) {
    // int x = q.front().first;
    // int y = q.front().second;
    // q.pop();
    //
    // if ((x + y) % c == 0) {
    // found = true;
    // break;
    // }
    //
    // for (int i = 0; i < n; i++) {
    // int val = items[i].first;
    // int cnt = items[i].second;
    //
    // for (int j = 1; j <= cnt && !found; j++) {
    // int newX = (1LL * x * val) % c;
    // if (!visited[newX][y]) {
    // visited[newX][y] = true;
    // q.push({newX, y});
    // }
    //
    // int newY = (1LL * y * val) % c;
    // if (!visited[x][newY]) {
    // visited[x][newY] = true;
    // q.push({x, newY});
    // }
    // }
    // }
    // }
    //
    // cout << (found ? "YES\n" : "NO\n");
    // }

    return 0;
}
