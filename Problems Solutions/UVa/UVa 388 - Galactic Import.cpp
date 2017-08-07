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

int n, arr[26];
vector<int> vec[27];
double mx;
int ans;

int getid(char ch) {
	if (ch == '*')
		return 26;
	return ch - 'A';
}

void bfs(int nxt) {
	queue<pair<int, double>> qu;
	qu.push({ nxt, 1 });
	bool vis[27];
	memset(vis, 0, sizeof(vis));
	while (!qu.empty()) {
		pair<int, double> fr = qu.front();
		qu.pop();
		if (fr.first == 26) {
			double cpu = arr[nxt] / fr.second;
			if (cpu > mx || (cpu == mx && nxt < ans)) {
				mx = cpu;
				ans = nxt;
			}
			break;
		}
		if (vis[fr.first])
			continue;
		vis[fr.first] = 1;
		for (int i = 0; i < vec[fr.first].size(); i++) {
			double fee = fr.second * 0.05;
			if (fr.first == nxt)
				fee = 0;
			qu.push({ vec[fr.first][i], fr.second - fee });
		}
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	while (cin >> n) {
		mx = 0;
		for (int i = 0; i < 27; i++)
			vec[i].clear();
		for (int e = 0; e < n; e++) {
			char ch;
			cin >> ch;
			int id = getid(ch);
			double cost;
			cin >> cost;
			cost *= 100;
			arr[id] = cost;
			string s;
			cin >> s;
			for (int i = 0; i < s.size(); i++) {
				int id2 = getid(s[i]);
				vec[id].push_back(id2);
				vec[id2].push_back(id);
			}
		}
		for (int i = 0; i < 26; i++)
			bfs(i);
		cout << "Import from " << (char)(ans + 'A') << '\n';
	}
	return 0;
}
