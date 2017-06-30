#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000 + 9;
const double PI = 3.14159265358979323846;

int tn = 1;
vector<int> vec(8);
vector<int> pos;
vector<vector<int>> pp;

void solve(int nxt){
	if(nxt == 8){
		pp.push_back(pos);
		return;
	}
	for(int i = 0; i < 8; i++){
		bool ok = 1;
		for(int e = 0; e < pos.size() && ok; e++){
			int rd = abs(i - pos[e]);
			int cd = abs(nxt - e);
			if(pos[e] == i || rd == cd || rd == -cd)
				ok = 0;
		}
		if(ok){
			pos.push_back(i);
			solve(nxt + 1);
			pos.pop_back();
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("in.txt", "rt", stdin);
	//freopen("out.txt", "wt", stdout);
	//const clock_t beg = clock();

	solve(0);
	for(; cin >> vec[0]; tn++){
		vec[0]--;
		for(int i = 1; i < 8; i++){
			cin >> vec[i];
			vec[i]--;
		}
		int ans = 1 << 30;
		for(int i = 0; i < pp.size(); i++){
			int c = 0;
			for(int e = 0; e < pp[i].size(); e++)
				c += (pp[i][e] != vec[e]);
			ans = min(ans,c);
		}
		cout << "Case " << tn << ": " << ans << '\n';
	}

	//cout << double(clock() - beg) / CLOCKS_PER_SEC << '\n';
	return 0;
}