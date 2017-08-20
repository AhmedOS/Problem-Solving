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

map<string, string> mp;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	mp["void"] = "void";
	int op;
	cin >> op;
	while (op--) {
		string s, a, b;
		cin >> s >> a;
		string na = "";
		int as = 0, am = 0;
		for (int i = 0; i < a.size(); i++) {
			if (a[i] == '*')
				as++;
			else if (a[i] == '&')
				am++;
			else
				na += a[i];
		}
		int c = 0;
		string eq = mp[na], neq = "";
		if (eq != "") {
			for (int i = 0; i < eq.size(); i++)
				if (eq[i] == '*')
					c++;
				else
					neq += eq[i];
			for (int i = 0; i < c + as - am; i++)
				neq += '*';
		}
		if (s == "typedef") {
			cin >> b;
			if (neq.size() && c + as >= am)
				mp[b] = neq;
			else
				mp[b] = "";
		}
		else
			cout << (neq.size() && c + as >= am ? neq : "errtype") << '\n';
	}
	return 0;
}
