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

int n, w, h;
short dp[5002][5002];

struct env {
	int w = 0, h = 0, id = -1;
};

vector<env> vec;
env arr[5001];

bool cmp(env &b, env &a) {
	if (b.w != a.w)
		return a.w > b.w;
	return a.h > b.h;
}

vector<int> ans;

int solve(int nxt, int prv) {
	if (nxt == vec.size())
		return 0;
	if (dp[nxt][prv] != -1)
		return dp[nxt][prv];
	int ret = solve(nxt + 1, prv);
	if (vec[nxt].h > arr[prv].h && vec[nxt].w > arr[prv].w)
		ret = max(ret, 1 + solve(nxt + 1, vec[nxt].id));
	return dp[nxt][prv] = ret;
}

void build(int nxt, int prv) {
	if (nxt == vec.size())
		return;
	int op1 = solve(nxt + 1, prv), op2 = -1;
	if (vec[nxt].h > arr[prv].h && vec[nxt].w > arr[prv].w)
		op2 = 1 + solve(nxt + 1, vec[nxt].id);
	int bst = solve(nxt, prv);
	if (bst == op1) {
		build(nxt + 1, prv);
	}
	else {
		ans.push_back(vec[nxt].id);
		build(nxt + 1, vec[nxt].id);
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	memset(dp, -1, sizeof(dp));
	cin >> n >> w >> h;
	env en;
	en.w = w;
	en.h = h;
	en.id = 0;
	vec.push_back(en);
	arr[0] = en;
	for (int i = 1; i <= n; i++) {
		int a, b;
		cin >> a >> b;
		env en;
		en.w = a;
		en.h = b;
		en.id = i;
		vec.push_back(en);
		arr[i] = en;
	}
	sort(vec.begin(), vec.end(), cmp);
	int st = n + 1;
	for (int i = 0; i < vec.size(); i++)
		if (!vec[i].id) {
			st = i + 1;
			break;
		}
	solve(st, 0);
	build(st, 0);
	cout << ans.size() << '\n';
	for (auto it : ans)
		cout << it << ' ';
	return 0;
}
