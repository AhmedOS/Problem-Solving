#include <bits/stdc++.h>
using namespace std;
int id = 1, src, des;
map<string, int> mp;
vector<vector<pair<int,pair<int,int>>>> vec;
int gcd(int a, int b){
	while(b){
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}
int lcm(int a, int b){
	int g = gcd(a, b);
	return (g ? a / g * b : 0);
}
pair<int,int> solve(){
	vector<bool> vis(vec.size());
	queue<pair<int,pair<int,int>>> qu;
	for(int i = 0; i < vec[src].size(); i++){
		qu.push(vec[src][i]);
	}
	vis[src] = 1;
	while(!qu.empty()){
		pair<int,pair<int,int>> f = qu.front();
		qu.pop();
		if(f.first == des){
			int g = gcd(f.second.first, f.second.second);
			return {f.second.first / g, f.second.second / g};
		}
		if(vis[f.first])
			continue;
		vis[f.first] = 1;
		for(int i = 0; i < vec[f.first].size(); i++){
			pair<int,pair<int,int>> p;
			p.first = vec[f.first][i].first;
			int lc = lcm(vec[f.first][i].second.first, f.second.second);
			p.second.first = f.second.first * (lc / f.second.second);
			p.second.second = vec[f.first][i].second.second * (lc / vec[f.first][i].second.first);
			qu.push(p);
		}
	}
	return {-1, -1};
}
void chk(string str){
	int idx = mp[str];
	if(!idx){
		mp[str] = id++;
		vec.push_back({});
	}
}
int main() {
	//freopen("in.txt", "rt", stdin);
	//freopen("out.txt", "wt", stdout);
	vec.push_back({});
	char ch;
	while(cin >> ch){
		int a, b;
		string sa, sb;
		if(ch == '!'){
			cin >> a >> sa >> ch >> b >> sb;
			chk(sa);
			chk(sb);
			vec[mp[sa]].push_back({mp[sb], {a,b}});
			vec[mp[sb]].push_back({mp[sa], {b,a}});
		}
		else if(ch == '?'){
			cin >> sa >> ch >> sb;
			src = mp[sa];
			des = mp[sb];
			pair<int,int> ret = solve();
			if(ret.first == -1)
				cout << "? " << sa << " = ? " << sb << '\n';
			else
				cout << ret.first << ' ' << sa << " = " << ret.second << ' ' << sb << '\n';
		}
		else
			break;
	}
	return 0;
}
