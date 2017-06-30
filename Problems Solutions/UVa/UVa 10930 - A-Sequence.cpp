#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000 + 9;
const double PI = 3.14159265358979323846;
int n, tn, seen[30009], vis[39][30009][2];
vector<int> vec;

void gen(int idx, int sm, int c){
	if(c > 1)
		seen[sm] = tn;
	if(idx == n || vis[idx][sm][c>1] == tn)
		return;
	vis[idx][sm][c>1] = tn;
	gen(idx + 1, sm + vec[idx], c + 1);
	gen(idx + 1, sm, c);
}

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("in.txt", "rt", stdin);
	//freopen("out.txt", "wt", stdout);
	//const clock_t beg = clock();

	while(cin >> n){
		tn++;
		vec.resize(n);
		for(int i = 0; i < n; i++)
			cin >> vec[i];
		gen(0, 0, 0);
		cout << "Case #" << tn << ":";
		for(int it : vec)
			cout << ' ' << it;
		cout << '\n';
		bool ok = 1;
		for(int i = 0; i < n && ok; i++)
			ok = (seen[vec[i]] != tn && vec[i] > (i ? vec[i - 1] : -1));
		cout << (ok ? "This is an A-sequence." : "This is not an A-sequence.") << '\n';
	}

	//cout << double(clock() - beg) / CLOCKS_PER_SEC << '\n';
	return 0;
}