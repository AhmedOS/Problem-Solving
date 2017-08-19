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

int a, b, c, d, n, arr[26];
char ab[50][50], cd[50][50], ans[100][100];

int ror[2];
int val[2] = { 1, -1 };
int env[2];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> a >> b >> c >> d >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	ror[1] = b - 1;
	env[0] = b;
	env[1] = -1;
	int rv = 0;
	if (a & 1)
		rv = 1;
	int id = 0;
	for (int co = 0; co < a; co++) {
		for (int ro = ror[rv]; ro != env[rv]; ro += val[rv]) {
			ab[ro][co] = 'a' + id;
			arr[id]--;
			if (!arr[id])
				id++;
		}
		rv = !rv;
	}
	// a -> c
	// b -> d
	ror[1] = d - 1;
	env[0] = d;
	for (int co = 0; co < c; co++) {
		for (int ro = ror[rv]; ro != env[rv]; ro += val[rv]) {
			cd[ro][co] = 'a' + id;
			arr[id]--;
			if (!arr[id])
				id++;
		}
		rv = !rv;
	}
	for (int i = 0; i < b; i++)
		for (int e = 0; e < a; e++)
			ans[i][e] = ab[i][e];
	for (int i = 0; i < d; i++)
		for (int e = 0; e < c; e++)
			ans[i][e + a] = cd[i][e];
	cout << "YES\n";
	for (int i = 0; i < max(b, d); i++) {
		for (int e = 0; e < a + c; e++)
			cout << (ans[i][e] ? ans[i][e] : '.');
		cout << '\n';
	}
	return 0;
}
