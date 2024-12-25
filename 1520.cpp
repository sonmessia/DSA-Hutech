#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, a, b;
    int finishTimeA = 0, finishTimeB = 0;
    cin >> n >> a >> b;
    if (a > b)
        swap(a, b);
    map<int, bool, greater<int>> mp;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        mp[x] = false;
    }

    for (auto &p : mp)
    {
        if (p.first % a == 0 && p.first % b == 0)
        {
            if (finishTimeA <= finishTimeB)
            {
                finishTimeA += p.first / a;
                p.second = true;
            }
            else
            {
                finishTimeB += p.first / b;
                p.second = false;
            }
        }
    }
    for (auto& p : mp)
    {
        cout << p.first << " " << p.second << endl;
    }
    cout << finishTimeA << " " << finishTimeB << endl;
    return 0;
}