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

int n, k;
long long t;
pair<long long, int> arr[100000];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n >> k >> t;
	for (int i = 0; i < n - 1; i++) {
		cin >> arr[i].first;
		arr[i].second = i;
	}
	sort(arr, arr + n);
	reverse(arr, arr + n);
	int ans = n;
	long long sum = 0;
	for (int i = 0; i < k - 1; i++)
		sum += arr[i].first;
	for (int i = 0; i < k - 1; i++)
		if (t - (sum - arr[i].first + arr[k - 1].first) < arr[i].first)
			ans = min(ans, arr[i].second + 1);
	for (int i = k - 1; i < n - 1; i++)
		if (t - sum < arr[i].first)
			ans = min(ans, arr[i].second + 1);
	cout << ans << '\n';
	return 0;
}
