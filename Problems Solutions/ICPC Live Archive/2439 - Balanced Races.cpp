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

int n, m, q, arr[10000];

bool ok(int nm) {
	int par = 1, heats = 1, fast = arr[0];
	for (int i = 1; i < q; i++) {
		if (arr[i] - fast <= nm && par < n)
			par++;
		else {
			heats++;
			par = 1;
			fast = arr[i];
		}
	}
	return heats <= m;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int t = 1;
	while (cin >> n >> m >> q && n != -1) {
		for (int i = 0; i < q; i++)
			cin >> arr[i];
		sort(arr, arr + q);
		int s = 0, e = 10000, ans = -1;
		while (s <= e) {
			int mid = (s + e) / 2;
			if (ok(mid)) {
				ans = mid;
				e = mid - 1;
			}
			else
				s = mid + 1;
		}
		cout << "Race " << t << ": ";
		if (ans == -1)
			cout << "Organization Fault!";
		else
			cout << ans;
		cout << '\n';
		t++;
	}
	return 0;
}
