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

class ComboBoxKeystrokes {
	int bfs(int s, int e) {
		bool vis[51];
		memset(vis, 0, sizeof(vis));
		queue<pair<int, int>> qu;
		qu.push({ s, 0 });
		while (!qu.empty()) {
			pair<int, int> fr = qu.front();
			qu.pop();
			if (fr.first == e)
				return fr.second;
			if (vis[fr.first])
				continue;
			vis[fr.first] = 1;
			for (int i = 0; i < vec[fr.first].size(); i++)
				qu.push({ vec[fr.first][i], fr.second + 1 });
		}
	}
public:
	vector<int> vec[51];
	int minimumKeystrokes(vector <string> elements) {
		for (int i = 0; i < elements.size(); i++) {
			for (int l = 0; l < 26; l++) {
				bool ok = 0;
				for (int e = i + 1; e < elements.size(); e++)
					if (tolower(elements[e][0]) - 'a' == l) {
						vec[i].push_back(e);
						ok = 1;
						break;
					}
				for (int e = 0; !ok && e < i; e++)
					if (tolower(elements[e][0]) - 'a' == l) {
						vec[i].push_back(e);
						ok = 1;
						break;
					}
			}
		}
		int ans = 0;
		for (int i = 0; i < elements.size(); i++)
			for (int e = 0; e < elements.size(); e++)
				ans = max(ans, bfs(i, e));
		return ans;
	}
};
