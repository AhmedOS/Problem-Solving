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

int n, k;
char arr[2][100000];
bool vis[2][100000];

struct state {
	int r = 0, c = 0, wat = 0;
};

bool solve() {
	state s;
	queue<state> qu;
	qu.push(s);
	while (!qu.empty()) {
		state fr = qu.front();
		qu.pop();
		if (fr.c < 0 || fr.c < fr.wat || (fr.c >= n ? 0 : arr[fr.r][fr.c] == 'X'))
			continue;
		if (fr.c >= n)
			return 1;
		if (vis[fr.r][fr.c])
			continue;
		vis[fr.r][fr.c] = 1;
		fr.wat++;
		fr.c++;
		qu.push(fr);
		fr.c -= 2;
		qu.push(fr);
		fr.c++;
		fr.r = !fr.r;
		fr.c += k;
		qu.push(fr);
	}
	return 0;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n >> k;
	for (int i = 0; i < 2; i++)
		for (int e = 0; e < n; e++)
			cin >> arr[i][e];
	cout << (solve() ? "YES" : "NO") << '\n';
	return 0;
}
