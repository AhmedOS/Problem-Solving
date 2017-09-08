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
unsigned long long h;

unsigned long long sum(unsigned long long nm) {
	unsigned long long a = nm, b = nm + 1;
	if (a & 1)
		b /= 2;
	else
		a /= 2;
	return a * b;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n;
	while (n--) {
		cin >> h;	
		if (h == 0 || h == 1)
			cout << "0\n";
		else if (h == 2)
			cout << "1\n";
		else {
			unsigned long long nm = h / 3;
			int sh = 2;
			unsigned long long tmp = h + 1;
			while (tmp % 3) {
				tmp++;
				sh--;
			}
			cout << sum(nm) * 2 + sum(nm - 1 + sh) << '\n';
		}
	}
	return 0;
}
