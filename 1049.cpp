#include <iostream>
#include <vector>
using namespace std;
const int maxn = 200005;
vector<pair<int, int>> tree;
int n, q;
void build(const vector<int> &arr, int node, int start, int end)
{
    if (start == end)
        tree[node] = {arr[start], start};
    else
    {
        int mid = (start + end) >> 1;
        int left = 2 * node;
        int right = 2 * node + 1;
        build(arr, left, start, mid);
        build(arr, right, mid + 1, end);

        if (tree[left].first < tree[right].first ||
            (tree[left].first == tree[right].first && tree[left].second < tree[right].second))
            tree[node] = tree[left];
        else
            tree[node] = tree[right];
    }
}

pair<int, int> query(int node, int start, int end, int l, int r)
{
    if (r < start || end < l)
        return {INT_MAX, INT_MAX};
    if (l <= start && end <= r)
        return tree[node];
    
    int mid = (start + end) >> 1;
    int left = 2 * node;
    int right = 2 * node + 1;
    auto leftResult = query(left, start, mid, l, r);
    auto rightResult = query(right, mid + 1, end, l, r);

    if (leftResult.first < rightResult.first ||
        (leftResult.first == rightResult.first && leftResult.second < rightResult.second))
        return leftResult;
    return rightResult;
}

void update(int node, int start, int end, int pos, int value)
{
    if (start == end)
        tree[node] = {tree[node].first + value, pos};
    else
    {
        int mid = (start + end) >> 1;
        int left = 2 * node;
        int right = 2 * node + 1;
        if (pos <= mid)
            update(left, start, mid, pos, value);
        else
            update(right, mid + 1, end, pos, value);

        if (tree[left].first < tree[right].first ||
            (tree[left].first == tree[right].first && tree[left].second < tree[right].second))
            tree[node] = tree[left];
        else
            tree[node] = tree[right];
    }
}

void collectArray(int node, int start, int end, vector<int>& result)
{
    if (start == end)
        result[start] = tree[node].first;
    else
    {
        int mid = (start + end) >> 1;
        int left = 2 * node;
        int right = 2 * node + 1;
        collectArray(left, start, mid, result);
        collectArray(right, mid + 1, end, result);
    }
}

vector<int> getArray()
{
    vector<int> result(n);
    collectArray(1,0,n-1,result);
    return result;
}
int main()
{
    cin >> n >> q;
    tree.resize(4*maxn);
    vector<int> arr(n);
    build(arr, 1, 0, n-1);
    while (q--)
    {
        long r, p;
        cin >> r >> p;
        while (p--)
        {
            auto result = query(0,0,n-1,0,r-1);
            cout << result.first << ' ' <<result.second<<'\n';
            update(1,0,n-1, result.first - 1, 1);
        }
    }

    arr = getArray();

    for (const int& i : arr)
        cout << i << ' ';
    return 0;
}
