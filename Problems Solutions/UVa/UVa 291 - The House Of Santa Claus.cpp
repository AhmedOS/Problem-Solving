#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000 + 9;
const double PI = 3.14159265358979323846;

int nodef[] = {1, 1, 1, 3, 3, 3, 5, 5};
int nodet[] = {5, 3, 2, 4, 5, 2, 4, 2};
vector<vector<int>> vec;
vector<string> ans;
bool used[6][6];

void solve(int nxt, int c, string path){
	if(c == 8){
		ans.push_back(path);
		return;
	}
	for(int i = 0; i < vec[nxt].size(); i++){
		if (!used[nxt][vec[nxt][i]] && !used[vec[nxt][i]][nxt]){
			used[nxt][vec[nxt][i]] = 1;
			path += vec[nxt][i] + '0';
			solve(vec[nxt][i], c + 1, path);
			path.pop_back();
			used[nxt][vec[nxt][i]] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("in.txt", "rt", stdin);
	//freopen("out.txt", "wt", stdout);
	//const clock_t beg = clock();

	vec.resize(6);
	for(int i = 0; i < 8; i++){
		int a = nodef[i];
		int b = nodet[i];
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	solve(1, 0, "1");
	sort(ans.begin(), ans.end());
	for(auto it : ans)
		cout << it << '\n';

	//cout << double(clock() - beg) / CLOCKS_PER_SEC << '\n';
	return 0;
}