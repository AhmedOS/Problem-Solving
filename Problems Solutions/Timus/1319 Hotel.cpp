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

int n, arr[101][101];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n;
	int lst = 1, co = n;
	int mid = n * 2 - 1;
	for (int i = 0; i < mid / 2; i++, co--)
		for (int r = 1, c = co; r <= n && c <= n; r++, c++) {
			arr[r][c] = lst;
			lst++;
		}
	int ro = 1;
	for (int i = 0; i < mid / 2 + 1; i++, ro++)
		for (int c = 1, r = ro; r <= n && c <= n; r++, c++) {
			arr[r][c] = lst;
			lst++;
		}
	for (int i = 1; i <= n; i++) {
		for (int e = 1; e <= n; e++)
			cout << arr[i][e] << (e == n ? '\n' : ' ');
	}
	return 0;
}
