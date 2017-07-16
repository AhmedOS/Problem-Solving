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

int n;

long long gcd(long long a, long long b) {
	while (b) {
		long long r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int getsize(int nm) {
	stringstream ss;
	ss << nm;
	string s;
	ss >> s;
	return s.size();
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int t = 1;
	while (cin >> n && n) {
		cout << "Case " << t << ":\n";
		int sum = 0;
		for (int i = 0; i < n; i++) {
			int nm;
			cin >> nm;
			sum += nm;
		}
		if (!(sum % n)) {
			if (sum < 0)
				cout << "- ";
			cout << abs(sum / n) << '\n';
		}
		else {
			int a = sum / n;
			sum -= a * n;
			string s = "";
			if (sum < 0)
				s += "  ";
			if (a) {
				int tmp = abs(a);
				while (tmp) {
					tmp /= 10;
					s += ' ';
				}
			}
			int g = gcd(abs(sum), n);
			sum /= g;
			n /= g;
			int ssz = getsize(abs(sum)), nsz = getsize(n);
			int dif = nsz - ssz;
			cout << s;
			while (dif--)
				cout << ' ';
			cout << abs(sum) << '\n';
			if (sum < 0)
				cout << "- ";
			if(a)
				cout << abs(a);
			int tmp = n;
			while (tmp) {
				tmp /= 10;
				cout << '-';
			}
			cout << '\n' << s << n << '\n';
		}
		t++;
	}
	return 0;
}
