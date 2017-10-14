#pragma comment (linker, "/STACK:256000000")
#pragma warning (disable : 4996 4018)

#include <map>
#include <set>
#include <stack>
#include <queue>
#include <cmath>
#include <cstdio>
#include <vector>
#include <bitset>
#include <limits>
#include <iomanip>
#include <sstream>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

string str;
set<string> ans;
int vis[10000][4];

bool solve(int nxt, int prv) {
	if (nxt == str.size())
		return 1;
	if (vis[nxt][prv] != -1)
		return vis[nxt][prv];
	if (str.size() - nxt == 1)
		return 0;
	bool ret = 0;
	string tmp = "";
	for (int i = nxt; i <= nxt + 1; i++)
		tmp += str[i];
	bool ok = 0;
	if (prv == 2)
		for (int i = nxt - 2, c = 0; i < nxt && !ok; i++, c++)
			ok = str[i] != tmp[c];
	if (!prv || prv == 3 || ok) {
		bool a = solve(nxt + 2, 2);
		if (a)
			ans.insert(tmp);
		ret |= a;
	}
	if (nxt + 2 < str.size()) {
		tmp += str[nxt + 2];
		bool ok = 0;
		if (prv == 3)
			for (int i = nxt - 3, c = 0; i < nxt && !ok; i++, c++)
				ok = str[i] != tmp[c];
		if (!prv || prv == 2 || ok) {
			bool b = solve(nxt + 3, 3);
			if (b)
				ans.insert(tmp);
			ret |= b;
		}
	}
	return vis[nxt][prv] = ret;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	memset(vis, -1, sizeof(vis));
	cin >> str;
	for (int i = 5; i < str.size(); i++)
		solve(i, 0);
	cout << ans.size() << '\n';
	for (auto it : ans)
		cout << it << '\n';
	return 0;
}
