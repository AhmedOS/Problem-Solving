#include <map>
#include <set>
#include <stack>
#include <queue>
#include <cmath>
#include <math.h>
#include <vector>
#include <bitset>
#include <climits>
#include <sstream>
#include <stdio.h>
#include <iomanip>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

const int MAX = 100000 + 9;
const double PI = 3.14159265358979323846;
int n, k, p, evc, odc;
queue<int> ev, od;
vector<vector<int>> ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> k >> p;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		if (tmp & 1)
			od.push(tmp);
		else
			ev.push(tmp);

	}
	for (; evc < p; evc++) {
		if (ev.size()) {
			int tp = ev.front();
			ev.pop();
			ans.push_back({ tp });
		}
		else if (od.size() > 1) {
			int tp = od.front();
			od.pop();
			int tp2 = od.front();
			od.pop();
			ans.push_back({ tp,tp2 });
		}
		else
			break;
	}
	for (; odc < k - p && od.size(); odc++) {
		int tp = od.front();
		od.pop();
		ans.push_back({ tp });
	}
	while (ev.size()) {
		int tp = ev.front();
		ev.pop();
		if (ans.size())
			ans[0].push_back(tp);
		else
			break;
	}
	if ((od.size() & 1) == 0)
		while (od.size()) {
			int tp = od.front();
			od.pop();
			if (ans.size())
				ans[0].push_back(tp);
			else
				break;
		}
	if (ev.size() || od.size() || evc != p || odc != k - p)
		cout << "NO\n";
	else {
		cout << "YES\n";
		for (auto it : ans) {
			cout << it.size() << ' ';
			for (auto it2 : it)
				cout << it2 << ' ';
			cout << '\n';
		}
	}
	return 0;
}
