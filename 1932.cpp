#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    bool isKnown[n + 1] = {};
    queue<int> q;
    for (int i = 0; i < m; i++)
    {
        int x; cin >> x;
        isKnown[x] = true;
        q.push(x);
    }
    int arr[n + 1];
    for (int i = 1; i <= n; i++)
        arr[i] = i;
    if (n == m)
        cout << 0;
    else
    {
        int cntTime = 0;
        while(!q.empty())
        {
            int qSize = q.size();
            for (int i = 0; i < qSize; i++)
            {
                int x = q.front();
                q.pop();
                if (x - 1 >= 1 && !isKnown[x - 1])
                {
                    isKnown[x - 1] = true;
                    q.push(x - 1);
                }
                if (x + 1 <= n && !isKnown[x + 1])
                {
                    isKnown[x + 1] = true;
                    q.push(x + 1);
                }
            }
            cntTime++;
        }
        cout << cntTime - 1;
    }
    return 0;
}