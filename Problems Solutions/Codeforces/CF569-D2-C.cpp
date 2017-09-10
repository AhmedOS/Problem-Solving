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

bool prime[10000001];

bool isPrime(int nm) {
	nm = abs(nm);
	if (nm == 2)
		return 1;
	if (nm < 2 || !(nm & 1))
		return 0;
	for (int i = 3; i * i <= nm; i += 2)
		if (nm % i == 0)
			return 0;
	return 1;
}

bool ispal(int nm) {
	stringstream ss;
	ss << nm;
	string s;
	ss >> s;
	for (int i = 0; i < s.size() / 2; i++)
		if (s[i] != s[s.size() - 1 - i])
			return 0;
	return 1;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	for (int i = 2; i <= 1179858; i++)
		prime[i] = 1;
	for (int i = 2; i <= 1179858; i++)
		for (int e = i + i; prime[i] && e <= 1179858; e += i)
			prime[e] = 0;
	long long a, b, ans = -1;
	cin >> a >> b;
	int pr = 0, pal = 0;
	for (int i = 1; i <= 1179858; i++) {
		pr += prime[i];
		pal += ispal(i);
		if (pr * b <= pal * a)
			ans = i;
		/*
		if ((double)pr / pal == 42)
			cout << (double)pr / pal << ' ' << i << ' ' << pr << ' ' << pal << '\n';
		*/
	}
	if (ans == -1)
		cout << "Palindromic tree is better than splay tree\n";
	else
		cout << ans << '\n';
	return 0;
}
