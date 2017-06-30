#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000 + 9;
const double PI = 3.14159265358979323846;
int n, tn, vis[49];
bool nprm[49];
vector<int> v;

void solve(int prv){
	if(v.size() == n && !nprm[*v.rbegin() + 1]){
		for(int i = 0; i < n; i++){
			if(i)
				cout << ' ';
			cout << v[i];
		}
		cout << '\n';
		return;
	}
	for(int i = 2; i <= n; i++)
		if(!nprm[prv + i] && vis[i] != tn){
			vis[i] = tn;
			v.push_back(i);
			solve(i);
			vis[i] = 0;
			v.pop_back();
		}
}

void gen(){
	for(int i = 2; i < 40; i++)
		for(int e = i+i; e < 40; e += i)
			nprm[e] = 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("in.txt", "rt", stdin);
	//freopen("out.txt", "wt", stdout);
	//const clock_t beg = clock();

	gen();
	while(cin >> n){
		tn++;
		if(tn > 1)
			cout << '\n';
		v.clear();
		cout << "Case " << tn << ":\n";
		v.push_back(1);
		solve(1);
	}

	//cout << double(clock() - beg) / CLOCKS_PER_SEC << '\n';
	return 0;
}