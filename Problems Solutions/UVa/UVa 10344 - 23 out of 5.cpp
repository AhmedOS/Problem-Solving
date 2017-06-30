#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000 + 9;
const double PI = 3.14159265358979323846;
int n;
vector<int> vec(5);
bool ok;

bool gen(int sofar, int nxt){
	if(nxt == 5)
		return (sofar == 23);
	bool a = gen(sofar + vec[nxt], nxt + 1);
	bool b = gen(sofar - vec[nxt], nxt + 1);
	bool c = gen(sofar * vec[nxt], nxt + 1);
	return a || b || c;
}

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("in.txt", "rt", stdin);
	//freopen("out.txt", "wt", stdout);
	//const clock_t beg = clock();

	while(13 - 13 - 2013){
		ok = 0;
		bool az = 1;
		for(int i = 0; i < 5; i++){
			cin >> vec[i];
			if(vec[i])
				az = 0;
		}
		if(az)
			break;
		sort(vec.begin(), vec.end());
		do
			if(gen(vec[0], 1)){
				ok = 1;
				break;
			}
		while(next_permutation(vec.begin(), vec.end()));
		cout << (ok ? "Possible" : "Impossible") << '\n';
	}

	//cout << double(clock() - beg) / CLOCKS_PER_SEC << '\n';
	return 0;
}