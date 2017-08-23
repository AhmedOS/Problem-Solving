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

int t, n;
vector<int> lucky;

bool pfact(int nm) {
	vector<int> pf;
	if (nm % 2 == 0)
		pf.push_back(2);
	while (nm % 2 == 0)
		nm = nm / 2;
	int sq = sqrt(nm);
	for (int i = 3; i <= sq; i += 2) {
		if (nm % i == 0)
			pf.push_back(i);
		while (nm % i == 0)
			nm = nm / i;
	}
	if (nm > 2)
		pf.push_back(nm);
	return pf.size() >= 3;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	for (int i = 2; lucky.size() < 1000; i++)
		if (pfact(i))
			lucky.push_back(i);
	cin >> t;
	while (t--) {
		cin >> n;
		cout << lucky[n - 1] << '\n';
	}
	return 0;
}
