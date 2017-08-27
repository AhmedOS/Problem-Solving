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

int nid = 1, eid = 1;
map<string, int> ntoid, etoid;
string idton[101], idtoe[201];

struct edge {
	int from, to, cost, id, cost2;
};
vector<edge> vec[101], prv;

bool operator < (const edge &b, const edge &a) {
	if (b.cost != a.cost)
		return b.cost > a.cost;
	return 0;
}

void dijkstra(int src, int gol) {
	prv.clear();
	prv.resize(nid);
	int inf = 1 << 30;
	vector<int> dist(nid, inf);
	dist[src] = 0;
	priority_queue<edge> qu;
	qu.push({ -1, src, 0, 0 });
	while (!qu.empty()) {
		edge nxt = qu.top();
		qu.pop();
		if (nxt.cost > dist[nxt.to])
			continue;
		prv[nxt.to] = nxt;
		if (nxt.to == gol)
			break;
		for (int i = 0; i < vec[nxt.to].size(); i++) {
			edge ne = vec[nxt.to][i];
			if (dist[ne.from] + ne.cost < dist[ne.to]) {
				dist[ne.to] = dist[ne.from] + ne.cost;
				ne.cost = dist[ne.to];
				ne.cost2 = vec[nxt.to][i].cost;
				qu.push(ne);
			}
		}
	}
}

int nmsz(int nm) {
	stringstream ss;
	ss << nm;
	string s;
	ss >> s;
	return s.size();
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	string line;
	while (getline(cin, line) && line.size()) {
		int a, b, id, c = 0;
		string s = "";
		int i = 0;
		for (; i < line.size() && line[i] != ','; i++)
			s += line[i];
		a = ntoid[s];
		if (!a) {
			a = nid++;
			ntoid[s] = a;
			idton[a] = s;
		}
		i++;
		s = "";
		for (; i < line.size() && line[i] != ','; i++)
			s += line[i];
		b = ntoid[s];
		if (!b) {
			b = nid++;
			ntoid[s] = b;
			idton[b] = s;
		}
		i++;
		s = "";
		for (; i < line.size() && line[i] != ','; i++)
			s += line[i];
		i++;
		for (; i < line.size(); i++)
			c = (c * 10) + (line[i] - '0');
		id = etoid[s];
		if (!id) {
			id = eid++;
			etoid[s] = id;
			idtoe[id] = s;
		}
		vec[a].push_back({ a, b, c, id });
		vec[b].push_back({ b, a, c, id });
	}
	while (getline(cin, line) && line.size()) {
		int a, b;
		string s = "";
		int i = 0;
		for (; i < line.size() && line[i] != ','; i++)
			s += line[i];
		a = ntoid[s];
		i++;
		s = "";
		for (; i < line.size(); i++)
			s += line[i];
		b = ntoid[s];
		dijkstra(a, b);
		cout << "\n\n";
		string arr[] = { "From", "To", "Route", "Miles" };
		int nms[] = { 20, 20, 10, 5 };
		for (int i = 0; i < 4; i++) {
				for (int e = 0; i && e < nms[i - 1] - arr[i - 1].size() + 1; e++)
					cout << ' ';
				cout << arr[i];
		}
		cout << '\n';
		for (int i = 0; i < 4; i++) {
			if (i)
				cout << ' ';
			for (int e = 0; e < nms[i]; e++)
				cout << '-';
		}
		cout << '\n';
		vector<edge> path;
		int nxt = b;
		while (nxt != a) {
			path.push_back({prv[nxt].from, nxt, prv[nxt].cost2, prv[nxt].id });
			nxt = prv[nxt].from;
		}
		int sum = 0;
		for (int i = path.size() - 1; i >= 0; i--) {
			cout << idton[path[i].from];
			for (int e = 0; e < 20 - idton[path[i].from].size() + 1; e++)
				cout << ' ';
			cout << idton[path[i].to];
			for (int e = 0; e < 20 - idton[path[i].to].size() + 1; e++)
				cout << ' ';
			cout << idtoe[path[i].id];
			for (int e = 0; e < 10 - idtoe[path[i].id].size() + 1; e++)
				cout << ' ';
			for (int e = 0; e < 5 - nmsz(path[i].cost); e++)
				cout << ' ';
			cout << path[i].cost << '\n';
			sum += path[i].cost;
		}
		for (int e = 0; e < 53; e++)
			cout << ' ';
		for (int e = 0; e < 5; e++)
			cout << '-';
		cout << '\n';
		for (int e = 0; e < 42; e++)
			cout << ' ';
		cout << "Total";
		for (int e = 0; e < 11 - nmsz(sum); e++)
			cout << ' ';
		cout << sum << '\n';
	}
	return 0;
}
