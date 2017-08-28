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

struct edge {
	int from, to, cost;
};
bool operator < (const edge &b, const edge &a) {
	if (b.cost != a.cost)
		return b.cost > a.cost;
	return 0;
}

class DateFieldCorrection {
public:
	int n = 37;
	vector<edge> vec[40];
	int dijkstra(int src, int gol) {
		int inf = 1 << 30;
		vector<int> dist(n, inf);
		dist[src] = 0;
		priority_queue<edge> qu;
		qu.push({ -1, src, 0 });
		while (!qu.empty()) {
			edge nxt = qu.top();
			qu.pop();
			if (nxt.cost > dist[nxt.to])
				continue;
			if (nxt.to == gol)
				return nxt.cost;
			for (int i = 0; i < vec[nxt.to].size(); i++) {
				edge ne = vec[nxt.to][i];
				if (dist[ne.from] + ne.cost < dist[ne.to]) {
					dist[ne.to] = dist[ne.from] + ne.cost;
					ne.cost = dist[ne.to];
					qu.push(ne);
				}
			}
		}
	}
	string key[5] = {
		"1234567890",
		"qwertyuiop",
		"asdfghjkl",
		"zxcvbnm",
		" "
	};
	int pen[40][40];
	int idx(char ch) {
		if (ch >= 'a' && ch <= 'z')
			return ch - 'a';
		if (ch >= '0' && ch <= '9')
			return 26 + ch - '0';
		return 36;
	}
	string correctDate(string input) {
		for (int i = 0; i < 5; i++)
			for (int e = 1; e < key[i].size(); e++) {
				vec[idx(key[i][e])].push_back({ idx(key[i][e]), idx(key[i][e - 1]), 1 });
				vec[idx(key[i][e - 1])].push_back({ idx(key[i][e - 1]), idx(key[i][e]), 1 });
			}
		for (int i = 0; i < 4; i++)
			for (int e = 0; e < key[i].size(); e++) {
				if (i == 3 && !e)
					continue;
				if (i == 3) {
					vec[idx(key[i][e])].push_back({ idx(key[i][e]), 36, 3 });
					vec[36].push_back({ 36, idx(key[i][e]), 3 });
					continue;
				}
				if (i == 2 && e == key[i].size() - 1)
					continue;
				if (e - 1 >= 0) {
					vec[idx(key[i][e])].push_back({ idx(key[i][e]), idx(key[i + 1][e - 1]), 1 });
					vec[idx(key[i + 1][e - 1])].push_back({ idx(key[i + 1][e - 1]), idx(key[i][e]), 1 });
				}
				if (e < key[i + 1].size()) {
					vec[idx(key[i][e])].push_back({ idx(key[i][e]), idx(key[i + 1][e]), 1});
					vec[idx(key[i + 1][e])].push_back({ idx(key[i + 1][e]), idx(key[i][e]), 1 });
				}
			}
		for (int i = 0; i < 37; i++)
			for (int e = 0; e < 37; e++) {
				int ret = dijkstra(i, e);
				pen[i][e] = ret;
				pen[e][i] = ret;
			}
		string mon[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
		int len[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int bst = 1 << 30;
		string ret;
		for (int i = 0; i < 12; i++)
			for (int e = 1; e <= len[i]; e++) {
				string s = mon[i];
				s += ' ';
				stringstream ss;
				ss << e;
				string nm;
				ss >> nm;
				s += nm;
				if (s.size() != input.size())
					continue;
				int sum = 0;
				for (int d = 0; d < s.size(); d++)
					sum += pen[idx(tolower(input[d]))][idx(tolower(s[d]))];
				if (sum < bst) {
					bst = sum;
					ret = s;
				}
			}
		return ret;
	}
};
