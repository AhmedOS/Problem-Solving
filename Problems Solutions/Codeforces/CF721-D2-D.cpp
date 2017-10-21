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

long long n, k, x;
pair<long long, int> arr[200000], org[200000];
bool sign[200000];

bool cmp(pair<long long, int> &b, pair<long long, int> &a) {
	return a.second > b.second;
}

void maximize() {
	set<pair<long long, int>> st;
	for (int i = 0; i < n; i++) {
		st.insert({ abs(arr[i].first), arr[i].second });
		sign[arr[i].second] = arr[i].first < 0;
	}
	while (k--) {
		pair<long long, int> be = *st.begin();
		st.erase(st.begin());
		be.first += x;
		st.insert(be);
	}
	for (auto it : st) {
		arr[it.second].first = it.first * (sign[it.second] ? -1 : 1);
		arr[it.second].second = it.second;
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n >> k >> x;
	int neg = 0, zero = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].first;
		arr[i].second = i;
		org[i] = arr[i];
		neg += arr[i].first < 0;
		zero += arr[i].first == 0;
	}
	bool ok = 0;
	if (zero == k) {
		ok = 1;
		for (int i = 0; i < n; i++) {
			if (!arr[i].first) {
				if (neg & 1)
					arr[i].first = x;
				else {
					arr[i].first = -x;
					neg++;
				}
			}
			cout << arr[i].first << ' ';
		}
	}
	else if (zero > k) {
		cout << arr[0].first + x * k;
		for (int i = 1; i < n; i++)
			cout << ' ' << arr[i].first;
		ok = 1;
	}
	else {
		//zero < k
		if (neg & 1) {
			ok = 1;
			k -= zero;
			for (int i = 0; i < n; i++)
				if (!arr[i].first)
					arr[i].first = x;
			maximize();
			for (int i = 0; i < n; i++)
				cout << arr[i].first << ' ';
		}
		else {
			//try to (neg & 1 == true && zero == 0)
			sort(arr, arr + n);
			int bst = -1;
			for (int i = 0; i < n; i++)
				if (bst == -1 || abs(arr[i].first) < abs(arr[bst].first))
					bst = i;
			int one = (arr[bst].first < 0 ? 1 : -1);
			long long am = ceil(abs(arr[bst].first - one) / (double)x);
			arr[bst].first += one * x * am;
			for (int i = 0; i < n; i++)
				if (!arr[i].first) {
					arr[i].first = x;
					am++;
				}
			if (am <= k) {
				ok = 1;
				k -= am;
				maximize();
				for (int i = 0; i < n; i++)
					cout << arr[i].first << ' ';
			}
		}
		if (zero && !ok) {
			//result == 0
			for (int i = 0; i < n; i++)
				if (org[i].first) {
					org[i].first += x * k;
					break;
				}
			sort(org, org + n, cmp);
			for (int i = 0; i < n; i++)
				cout << org[i].first << ' ';
		}
		else if (!ok) {
			//try to create a zero
			for (int i = 0; i < n; i++)
				if (abs(org[i].first) % x == 0 && abs(org[i].first) / x <= k) {
					k -= abs(org[i].first) / x;
					org[i].first = 0;
					ok = 1;
					break;
				}
			if (ok) {
				for (int i = 0; i < n; i++) {
					if (org[i].first && k) {
						org[i].first += x * k;
						k = 0;
					}
					cout << org[i].first << ' ';
				}
			}
			else {
				//positive result, minimize as possible
				sort(org, org + n);
				org[0].first += (org[0].first < 0 ? 1 : -1) * x * k;
				sort(org, org + n, cmp);
				for (int i = 0; i < n; i++)
					cout << org[i].first << ' ';
			}
		}
	}
	return 0;
}
