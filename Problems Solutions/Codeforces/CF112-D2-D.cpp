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
vector<int> vec[100001];
set<int> ist[100001];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	for (int i = 2; i <= 100000; i++)
		for (int e = i; e <= 100000; e += i)
			vec[e].push_back(i);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		int ans = 0;
		for (int e = 0; e < vec[a].size(); e++) {
			ans += ist[vec[a][e]].upper_bound(i - b - 1) == ist[vec[a][e]].end();
			ist[vec[a][e]].insert(i);
		}
		cout << ans + !b << '\n';
	}
	return 0;
}
