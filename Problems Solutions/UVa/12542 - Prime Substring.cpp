#pragma warning (disable : 4996 4018)

//#include <thread>
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

int prime[10000001];
string s;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	for (int i = 2; i < 10000001; i++)
		prime[i] = 1;
	for (int i = 2; i < 10000001; i++)
		for (int e = i + i; prime[i] && e < 10000001; e += i)
			prime[e] = 0;
	while (cin >> s && !(s[0] == '0' && s.size() == 1)) {
		int ans = 0;
		for (int i = 0; i < s.size(); i++) {
			string str = "";
			for (int e = i; e < s.size() && str.size() < 6; e++) {
				str += s[e];
				stringstream ss;
				ss << str;
				int nm;
				ss >> nm;
				if (prime[nm] && nm > ans && nm <= 100000)
					ans = nm;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
