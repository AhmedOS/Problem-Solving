#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000 + 9;
const double PI = 3.14159265358979323846;
int t, n;
vector<int> vec;
set<string> vis;
vector<string> ans;

void prnt(vector<int> &v){
	string str;
	for(int i = 0; i < v.size(); i++){
		if(i)
			str += '+';
		stringstream ss;
		ss << v[i];
		string sn;
		ss >> sn;
		str += sn;
	}
	if(!vis.count(str)){
		ans.push_back(str);
		vis.insert(str);
	}
}

void gen(int idx, int sm, vector<int> v){
	if(sm == t){
		prnt(v);
		return;
	}
	if(sm > t || idx == vec.size())
		return;
	v.push_back(vec[idx]);
	gen(idx + 1, sm + vec[idx], v);
	v.pop_back();
	gen(idx + 1, sm, v);
}

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("in.txt", "rt", stdin);
	//freopen("out.txt", "wt", stdout);
	//const clock_t beg = clock();

	while(cin >> t >> n && t && n){
		ans.clear();
		vis.clear();
		cout << "Sums of " << t << ":\n";
		vec.resize(n);
		for(int i = 0; i < n; i++)
			cin >> vec[i];
		gen(0, 0, {});
		if(ans.size()){
			for(auto it : ans)
				cout << it << '\n';
		}
		else
			cout << "NONE\n";
	}

	//cout << double(clock() - beg) / CLOCKS_PER_SEC << '\n';
	return 0;
}