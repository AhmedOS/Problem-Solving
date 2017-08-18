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

string str;
int k;
short dp[500][500][501], arr[500][500];

int solve(int s, int e, int k) {
	if (e == str.size()) {
		if (s == e)
			return 0;
		e--;
		return arr[s][e];
	}
	if (dp[s][e][k] != -1)
		return dp[s][e][k];
	int ret = solve(s, e + 1, k);
	if (k < ::k)
		ret = min(ret, arr[s][e] + solve(e + 1, e + 1, k + 1));
	return dp[s][e][k] = ret;
}

bool flag = 0;
void print(int s, int e) {
	if (flag)
		cout << '+';
	flag = 1;
	int sz = e - s + 1;
	for (int i = 0; i < sz / 2; i++)
		if (str[s + i] != str[s + sz - 1 - i])
			str[s + sz - 1 - i] = str[s + i];
	for (int i = s; i <= e; i++)
		cout << str[i];
}

void solve_build(int s, int e, int k) {
	if (e == str.size()) {
		if (s == e)
			return;
		e--;
		print(s, e);
		return;
	}
	int best = solve(s, e, k), ch1 = solve(s, e + 1, k), ch2 = 1 << 30;
	if (k < ::k)
		ch2 = arr[s][e] + solve(e + 1, e + 1, k + 1);
	if (best == ch1)
		solve_build(s, e + 1, k);
	else {
		print(s, e);
		solve_build(e + 1, e + 1, k + 1);
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	memset(dp, -1, sizeof(dp));
	cin >> str >> k;
	for (int s = 0; s < str.size(); s++)
		for (int e = s; e < str.size(); e++) {
			int sz = e - s + 1;
			for (int i = 0; i < sz / 2; i++)
				arr[s][e] += str[s + i] != str[s + sz - 1 - i];
		}
	cout << solve(0, 0, 1) << '\n';
	solve_build(0, 0, 1);
	cout << '\n';
	return 0;
}
