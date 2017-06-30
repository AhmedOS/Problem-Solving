#include <bits/stdc++.h>
using namespace std;
int t;
string str, en;
vector<string> vec;
map<string, int> mp;
vector<int> arr[209];
bool vis[209];
int solve() {
	memset(vis, 0, sizeof(vis));
	int s = mp[str];
	pair<int, int> p = { s, 0 };
	queue<pair<int, int>> qu;
	qu.push(p);
	while (!qu.empty()) {
		pair<int, int> f = qu.front();
		qu.pop();
		if (vec[f.first] == en)
			return f.second;
		if (vis[f.first])
			continue;
		vis[f.first] = 1;
		for (int i = 0; i < arr[f.first].size(); i++)
			qu.push({ arr[f.first][i], f.second + 1 });
	}
}
int main() {
	//freopen("in.txt", "rt", stdin);
	//freopen("out.txt", "wt", stdout);
	scanf("%d", &t);
	while (t--) {
		vec.clear();
		mp.clear();
		for (int i = 0;; i++) {
			cin >> str;
			if (str == "*")
				break;
			vec.push_back(str);
			mp[str] = i;
		}
		for (int i = 0; i < 209; i++)
			arr[i].clear();
		for (int i = 0; i < vec.size(); i++) {
			for (int e = i + 1; e < vec.size(); e++) {
				int c = 0;
				for (int s = 0; s < vec[i].size(); s++)
					c += vec[i][s] != vec[e][s];
				if (c == 1) {
					int idx = mp[vec[i]], idx2 = mp[vec[e]];
					arr[idx].push_back(idx2);
					arr[idx2].push_back(idx);
				}
			}
		}
		cin.ignore();
		for (;;) {
			string lin;
			getline(cin, lin);
			if (!lin.size())
				break;
			int f;
			for (int i = 0; i <= lin.size(); i++) {
				if (i == lin.size()) {
					en = lin.substr(f + 1, lin.size() - 1 - str.size());
					break;
				}
				else if (lin[i] == ' ') {
					f = i;
					str = lin.substr(0, f);
				}
			}
			cout << str << ' ' << en << ' ' << solve() << '\n';
		}
		if (t)
			cout << '\n';
	}
	return 0;
}