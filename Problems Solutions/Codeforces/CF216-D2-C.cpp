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

int n, m, k, arr[100001], off[100001];
vector<int> vec;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n >> m >> k;
	int w = 0;
	for (int d = 1; d <= 10000; d++) {
		w -= d - n >= 1 ? arr[d - n] : 0;
		if (d != 1 && !w) {
			vec.push_back(d - 1);
			arr[d - 1]++;
			w = 1;
		}
		arr[d + m] = d - n >= 1 ? arr[d - n] : 0;
		w += arr[d];
		if (w < k) {
			int dif = k - w;
			arr[d] = dif;
			while (dif--)
				vec.push_back(d);
			w = k;
		}
	}
	cout << vec.size() << '\n';
	for (auto it : vec)
		cout << it << ' ';
	return 0;
}
