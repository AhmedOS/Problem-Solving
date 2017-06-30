#include <bits/stdc++.h>
using namespace std;
int k, m, n;
int srcx, srcy, srcr;
int desx, desy, desr;
vector<pair<pair<int,int>, int>> vec;
bool solve(){
	vector<bool> vis(n+2);
	queue<int> qu;
	qu.push(0);
	while(!qu.empty()){
		int nxt = qu.front();
		qu.pop();
		if(nxt == n+1)
			return 1;
		if(vis[nxt])
			continue;
		vis[nxt] = 1;
		for(int i = 1; i <= n + 1; i++){
			double dist = hypot(vec[nxt].first.first - vec[i].first.first, vec[nxt].first.second - vec[i].first.second);
			dist -= vec[nxt].second + vec[i].second;
			if(dist / m < k || abs(dist / m - k) < numeric_limits<double>::epsilon())
				qu.push(i);
		}
	}
	return 0;
}
int main(){
	//freopen("in.txt", "rt", stdin);
	//freopen("out.txt", "wt", stdout);
	while(cin >> k >> m){
		cin >> srcx >> srcy >> srcr >> desx >> desy >> desr;
		cin >> n;
		vec.resize(n+2);
		for(int i = 1; i <= n; i++)
			cin >> vec[i].first.first >> vec[i].first.second >> vec[i].second;
		vec[0].first.first = srcx;
		vec[0].first.second = srcy;
		vec[0].second = srcr;
		vec[n+1].first.first = desx;
		vec[n+1].first.second = desy;
		vec[n+1].second = desr;
		cout << (solve() ? "Larry and Ryan will escape!" : "Larry and Ryan will be eaten to death.") << '\n';
	}
	return 0;
}
