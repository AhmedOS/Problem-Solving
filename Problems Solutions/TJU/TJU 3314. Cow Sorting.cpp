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
long long bit[100001], sum[100002], bit2[100001];
pair<pair<int, int>, int> arr[100001];

long long getsum(long long fen[], int idx) {
	long long ret = 0;
	for (int i = idx; i; i -= (i & -i))
		ret += fen[i];
	return ret;
}

void update(long long fen[], int idx, long long val) {
	for (int i = idx; i <= n; i += (i & -i))
		fen[i] += val;
}

long long range_query(long long fen[], int s, int e) {
	if (s > e)
		return 0;
	return getsum(fen, e) - getsum(fen, s - 1);
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].first.first;
		arr[i].first.second = i;
		update(bit, i + 1, arr[i].first.first);
	}
	//arr[i].first.first -> value
	//arr[i].first.second -> index
	//arr[i].second -> alternative value to avoid number repetition in prefix sum array 
	sort(arr, arr + n);
	for (int i = 1; i <= min(100000, n); i++) {
		arr[i - 1].second = i;
		sum[i] = 1;
	}
	for (int i = 1; i <= 100000; i++)
		sum[i] += sum[i - 1];
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		//ans += all_numbers_bigger_than_arr[i].second - (all_numbers_comes_after_i - all_numbers_comes_after_i_and_smaller) * arr[i].first.first
		ans += (sum[100000] - sum[arr[i].second] - (n - 1 - arr[i].first.second - range_query(bit2, arr[i].first.second + 2, n))) * arr[i].first.first;
		ans += getsum(bit, arr[i].first.second);
		update(bit, arr[i].first.second + 1, -arr[i].first.first);
		update(bit2, arr[i].first.second + 1, 1);
	}
	cout << ans << '\n';
	return 0;
}
