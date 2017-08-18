#include <map>
#include <set>
#include <stack>
#include <queue>
#include <cmath>
#include <vector>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 1001;
int n, k, arr[MAX];
vector<pair<pair<int, int>, int>> vec;
vector<pair<int, int>> ans;
int main() {
	cin >> n;
	vec.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> vec[i].first.second >> vec[i].first.first;
		vec[i].second = i;
	}
	cin >> k;
	for (int i = 0; i < k; i++)
		cin >> arr[i];
	int c = 0, sum = 0;
	sort(vec.begin(), vec.end());
	reverse(vec.begin(), vec.end());
	for (int i = 0; i < n; i++) {
		int slc = -1;
		for (int e = 0; e < k; e++)
			if ((arr[e] >= vec[i].first.second) && ((slc != -1 && arr[e] < arr[slc]) || slc == -1))
				slc = e;
		if (slc != -1) {
			c++;
			sum += vec[i].first.first;
			ans.push_back({ vec[i].second + 1, slc + 1 });
			arr[slc] = -1;
		}
	}
	cout << c << ' ' << sum << '\n';
	for (int i = 0; i < c; i++)
		cout << ans[i].first << ' ' << ans[i].second << '\n';
	return 0;
}
