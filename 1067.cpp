#include <iostream>
#include <vector>
#include <map>


using namespace std;
vector<pair<int, int>> arr;
map<tuple<int,int,int>, bool> memo;
int a, b, c, n;
bool ok = false;

bool TryAt(int x, int y, int idx) {
    x = x % c;
    y = y % c;
    
    if ((x + y) % c == 0) return true;
    if (idx >= n) return false;
    
    auto state = make_tuple(x, y, idx);
    if (memo.count(state)) return memo[state];
    
    bool result = false;
    for (int i = idx; i < n && !result; i++) {
        if (arr[i].second > 0) {
            arr[i].second--;
            
            result |= TryAt((1LL * x * arr[i].first) % c, y, i);
            if (!result) {
                result |= TryAt(x, (1LL * y * arr[i].first) % c, i);
            }
            
            arr[i].second++;
        }
    }
    
    return memo[state] = result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> q;
    while (q--) {
        cin >> a >> b >> c >> n;
        arr.resize(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i].first >> arr[i].second;
        memo.clear();
        cout << (TryAt(a % c, b % c, 0) ? "YES\n" : "NO\n");
    }
    return 0;
}
