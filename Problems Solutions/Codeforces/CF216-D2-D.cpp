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

int n;
vector<int> vec[1000];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		vec[i].resize(k);
		for (int e = 0; e < k; e++)
			cin >> vec[i][e];
	}
	for (int i = 0; i < n; i++)
		sort(vec[i].begin(), vec[i].end());
	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int e = 0; e < vec[i].size() - 1; e++) {
			int brg = vec[i][e], brg2 = vec[i][e + 1];
			int nxt = (i + 1) % n, prv = (i ? i - 1 : n - 1);
			auto it = upper_bound(vec[nxt].begin(), vec[nxt].end(), brg2);
			it--;
			auto it2 = upper_bound(vec[nxt].begin(), vec[nxt].end(), brg);
			int val = it - it2;
			it = upper_bound(vec[prv].begin(), vec[prv].end(), brg2);
			it--;
			it2 = upper_bound(vec[prv].begin(), vec[prv].end(), brg);
			int val2 = it - it2;
			ans += val != val2;
		}
	cout << ans << '\n';
	return 0;
}
