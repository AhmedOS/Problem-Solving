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

int n, k, arr[30000];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n >> k;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	int s = 0, e = n - 1;
	bool ok = 1;
	while (s <= e && ok) {
		if (arr[s] < arr[e]) {
			sum -= arr[s];
			s++;
		}
		else {
			sum -= arr[e];
			e--;
		}
		ok = sum <= (e - s + 1 + k);
	}
	cout << (ok ? "YES" : "NO") << '\n';
	return 0;
}
