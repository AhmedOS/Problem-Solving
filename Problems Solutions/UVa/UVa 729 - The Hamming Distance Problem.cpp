#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000 + 9;
const double PI = 3.14159265358979323846;

int t, n, h;

void solve(int c, string str){
	if(c == h && str.size() == n)
		cout << str << '\n';
	if(str.size() == n)
		return;
	solve(c, str + '0');
	solve(c + 1, str + '1');
}

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("in.txt", "rt", stdin);
	//freopen("out.txt", "wt", stdout);
	//const clock_t beg = clock();

	cin >> t;
	while(t--){
		cin >> n >> h;
		solve(0, "");
		if(t)
			cout << '\n';
	}

	//cout << double(clock() - beg) / CLOCKS_PER_SEC << '\n';
	return 0;
}