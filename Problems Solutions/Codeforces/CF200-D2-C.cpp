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

int id, co[4];

struct team {
	int points = 0, sg = 0, mg = 0;
	string name;
};

vector<team> vec(4);
map<string, int> idx;

bool cmp(team &a, team &b) {
	if (a.points != b.points)
		return a.points > b.points;
	int difa = a.sg - a.mg, difb = b.sg - b.mg;
	if (difa != difb)
		return difa > difb;
	if (a.sg != b.sg)
		return a.sg > b.sg;
	return a.name < b.name;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n = 5, bid, opp;
	while (n--) {
		string a, b;
		int sa, sb;
		char ch;
		cin >> a >> b >> sa >> ch >> sb;
		if (!idx[a]) {
			idx[a] = ++id;
			vec[idx[a] - 1].name = a;
		}
		if (!idx[b]) {
			idx[b] = ++id;
			vec[idx[b] - 1].name = b;
		}
		if (a == "BERLAND")
			bid = idx[a];
		if (b == "BERLAND")
			bid = idx[b];
		co[idx[a] - 1]++;
		co[idx[b] - 1]++;
		vec[idx[a] - 1].sg += sa;
		vec[idx[b] - 1].sg += sb;
		vec[idx[a] - 1].mg += sb;
		vec[idx[b] - 1].mg += sa;
		if (sa == sb) {
			vec[idx[a] - 1].points++;
			vec[idx[b] - 1].points++;
		}
		else if (sa > sb)
			vec[idx[a] - 1].points += 3;
		else
			vec[idx[b] - 1].points += 3;
	}
	for (int i = 0; i < 4; i++)
		if (i != bid - 1 && co[i] == 2) {
			opp = i;
			break;
		}
	int ans = -1, bdif = 1 << 30, mg = 1 << 30;
	for (int i = 1; i <= 50; i++) {
		for (int e = 0; e < i; e++) {
			vector<team> tmp;
			tmp = vec;
			tmp[bid - 1].sg += i;
			tmp[bid - 1].mg += e;
			tmp[bid - 1].points += 3;
			tmp[opp].mg += i;
			tmp[opp].sg += e;
			sort(tmp.begin(), tmp.end(), cmp);
			if ((tmp[0].name == "BERLAND" || tmp[1].name == "BERLAND") && (i - e < bdif || (i - e == bdif && e < mg))) {
				ans = i;
				bdif = i - e;
				mg = e;
			}
		}
	}
	if (ans == -1)
		cout << "IMPOSSIBLE\n";
	else
		cout << ans << ':' << mg << "\n";
	return 0;
}
