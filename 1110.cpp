#include <iostream> 
#include <algorithm>

using namespace std;
long long dp[3][200005];

int t, ans = 0, n;

bool check(int l, int r)
{
    t = (r - l + 1) / 2 + 1;
    return (dp[0][r] - dp[0][l - 1] >= t) || (dp[1][r] - dp[1][l - 1] >= t) || (dp[2][r] - dp[2][l - 1] >= t);
}

int main()
{
    cin >> n;
    string s;
    cin >> s;
    dp[0][0] = dp[1][0] = dp[2][0] = 0; 
    for (int i = 0; i < n; i++)
    {
        dp[0][i + 1] = dp[0][i] + (s[i] == 'a');
        dp[1][i + 1] = dp[1][i] + (s[i] == 'b');
        dp[2][i + 1] = dp[2][i] + (s[i] == 'c');
    }

    for (int i = 1; i <= n - ans; i++)
    {
        for (int j = n; j >= i + ans; j--)
        {
            if (check(i, j))
            {
                ans = max(ans, j - i + 1);
                break;
            }
        }
    }

    cout << ans << endl;
    return 0;
}