#include <iostream>
#include <map>
#include <vector>
using namespace std;

vector<pair<int, int>> arr;
int a, b, c, n;
bool ok = false;
void TryAt(int x, int y, int idx)
{
	if ((x + y) % c == 0 || ok)
	{
		ok = true;
		return;
	}
	for (int i = idx; i < n; i++)
	{
		if (arr[i].second)
		{
			arr[i].second -= 1;
			TryAt(x * arr[i].first, y, (i + 1) % n);
			TryAt(x, y * arr[i].first, (i + 1) % n);
			arr[i].second += 1;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int q;
	cin >> q;
	while (q--)
	{
		cin >> a >> b >> c >> n;
		arr.resize(n);
		for (int i = 0; i < n; i++)
			cin >> arr[i].first >> arr[i].second;

		ok = false;
		TryAt(a, b, 0);
		cout << (ok ? "YES\n" : "NO\n");
	}
	return 0;
}
