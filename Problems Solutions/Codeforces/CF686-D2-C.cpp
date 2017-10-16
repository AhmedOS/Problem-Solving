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

int n, m;
long long n7, m7;
bool vis[654322];
vector<int> hour, minute;

int getBit(int msk, int idx) {
	return (msk >> idx) & 1;
}

int setBit(int msk, int idx, int val) {
	if (val)
		return msk | (1 << idx);
	return msk & ~(1 << idx);
}

int diff(long long a, long long b) {
	stringstream ss;
	ss << a;
	string sa;
	ss >> sa;
	ss.clear();
	ss << b;
	string sb;
	ss >> sb;
	return abs((int)sa.size() - (int)sb.size());
}

long long convert_base(int nm, int base) {
	if (!nm)
		return 0;
	string str = "";
	while (nm) {
		str += (nm % base) + '0';
		nm /= base;
	}
	reverse(str.begin(), str.end());
	stringstream ss;
	ss << str;
	long long ret;
	ss >> ret;
	return ret;
}

void gen(int msk, int nm, long long limit, vector<int> &mv) {
	if (nm > 654322 || nm > limit || vis[nm])
		return;
	if (nm && diff(limit, nm) == 1 && !getBit(msk, 0)) {
		int nmsk = setBit(msk, 0, 1);
		mv.push_back(nmsk);
	}
	else if (nm && !diff(limit, nm))
		mv.push_back(msk);
	vis[nm] = 1;
	for (int i = 0; i < 7; i++)
		if (!getBit(msk, i)) {
			if (!i && !nm)
				continue;
			int nnm = nm * 10 + i;
			int nmsk = setBit(msk, i, 1);
			gen(nmsk, nnm, limit, mv);
		}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n >> m;
	n7 = convert_base(n - 1, 7);
	m7 = convert_base(m - 1, 7);
	if (!diff(0, n7))
		hour.push_back(1);
	if (!diff(0, m7))
		minute.push_back(1);
	gen(0, 0, n7, hour);
	memset(vis, 0, sizeof(vis));
	gen(0, 0, m7, minute);
	long long ans = 0;
	for (int i = 0; i < hour.size(); i++)
		for (int e = 0; e < minute.size(); e++) {
			bool ok = 1;
			for (int s = 0; s < 7 && ok; s++)
				ok = !getBit(hour[i], s) || !getBit(minute[e], s);
			ans += ok;
		}
	cout << ans << '\n';
	return 0;
}
