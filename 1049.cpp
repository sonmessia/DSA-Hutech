#include <iostream>
#include <vector>
using namespace std;
vector<pair<int, int>> tree;
int n, q;
void build(const vector<int> &arr, int node, int start, int end)
{
    if (start == end)
        tree[node] = {arr[start], start};
    else
    {
        int mid = (start + end) >> 1;
        int left = 2 * node + 1;
        int right = 2 * node + 2;
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
    if (r < start || l > end)
        return {INT_MAX, -1};
    if (l <= start && end <= r)
        return tree[node];
    int mid = (start + end) >> 1;
    int left = 2 * node + 1;
    int right = 2 * node + 2;

    pair<int, int> leftResult = query(left, start, mid, l, r);
    pair<int, int> rightResult = query(right, mid + 1, end, l, r);

    if (leftResult.first < rightResult.first ||
        (leftResult.first == rightResult.first && leftResult.second < rightResult.second))
        return leftResult;
    else
        return rightResult;
}

void update(int node, int start, int end, int idx, int value)
{
    if (start == end)
        tree[node] = {value, idx};
    else
    {
        int mid = (start + end) >> 1;
        int left = 2 * node + 1;
        int right = 2 * node + 1;
        if (idx <= mid)
            update(left, start, mid, idx, value);
        else
            update(right, mid + 1, end, idx, value);

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
        int left = 2 * node + 1;
        int right = 2 * node + 2;
        collectArray(left, start, mid, result);
        collectArray(right, mid + 1, end, result);
    }
}

vector<int> getArray()
{
    vector<int> result(n);
    collectArray(0,0,n-1,result);
    return result;
}
int main()
{
    cin >> n >> q;
    tree.resize(4*n);
    vector<int> arr(n);
    build(arr, 0, 0, n-1);
    while (q--)
    {
        long r, p;
        cin >> r >> p;
        while (p--)
        {
            auto result = query(0,0,n-1,0,r);
            cout << result.first << ' ' <<result.second<<'\n';
            update(0,0,n-1, result.first, result.second + 1);
        }
    }

    arr = getArray();

    for (const int& i : arr)
        cout << i << ' ';
    return 0;
}
