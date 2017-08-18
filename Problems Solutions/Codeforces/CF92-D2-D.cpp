#pragma warning (disable : 4996 4018)

//#include <thread>
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

int n, bit[100001];
pair<int, int> arr[100000];

int query(int fen[], int idx) {
	int ret = 0;
	for (int i = idx; i; i -= (i & -i))
		ret = max(ret, fen[i]);
	return ret;
}

void update(int fen[], int idx, int val) {
	for (int i = idx; i <= n; i += (i & -i))
		fen[i] = max(val, fen[i]);
}

bool cmp(pair<int, int> &a, pair<int, int> &b) {
	if (a != b)
		if (a.second != b.second)
			return a.second < b.second;
	return 0;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].first;
		arr[i].second = i + 1;
	}
	sort(arr, arr + n);
	int nm = 1;
	for (int i = 0; i < n; i++) {
		int val = arr[i].first;
		arr[i].first = nm;
		if ((i + 1 < n && arr[i + 1].first != val) || i + 1 == n)
			nm++;
	}
	sort(arr, arr + n, cmp);
	vector<int> ans(n);
	for (int i = n - 1; i >= 0; i--) {
		int e = query(bit, arr[i].first - 1);
		ans[i] = e ? e - i - 2 : -1;
		update(bit, arr[i].first, arr[i].second);
	}
	for (auto it : ans)
		cout << it << ' ';
	return 0;
}
