#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, a, b;
    int finishTimeA = 0, finishTimeB = 0;
    cin >> n >> a >> b;
    if (a > b)
        swap(a, b);
    map<int, bool> mp;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        mp[x] = false;
    }
    for (auto &p : mp)
    {
        if (p.first % b == 0)
        {
            p.second = true;
            finishTimeB += p.first / b;
        }
    }
    for (auto &p : mp)
    {
        if (p.first % a == 0 && !p.second)
        {
            p.second = true;
            finishTimeA += p.first / a;
        }
    }
    int t = 0;
    for (auto &p : mp)
    {
        if (!p.second)
        {
            t += p.first;
            p.second = true;
        }
    }
    t = ceil((double)t / (a+b));
    cout << t << " " << finishTimeA << " "<< finishTimeB << endl;
    if (finishTimeA + t < finishTimeB)
        finishTimeA += t;
    else
        finishTimeB += t;
    cout << max(finishTimeA, finishTimeB) << endl;
    return 0;
}