/*
The main idea is to create a complete graph so we get number of cycles that is less than or equal the required number,
now we have (#nodes COMBINATION 3) cycles, if number of cycles still less than the required number,
we add a node and connect it to 2 or more nodes that are part of the complete graph.
now number of cycles is increased by (#connected_to_nodes COMBINATION 2),
if still number of cycles is less than the required number, repeat the last step till we get the required number of cycles.
Example: if it is required to have 39 cycles, then we create a complete graph with 7 nodes to get a total of 35 cycles,
then add a new node and connect it to 3 nodes of the complete graph so we get a total of 38 cycles,
and finally we add another node and connect it to 2 nodes so we get the required number of cycles with 9 nodes.
as illustrated in the image: https://i.imgur.com/SkyMajI.png
*/
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
bool arr[100][100];

int comp(int nm, int r) {
	if (r > nm)
		return 0;
	int rs = 1;
	for (int i = 1; i <= r; i++, nm--) {
		rs *= nm;
		rs /= i;
	}
	return rs;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n;
	int it = 3;
	for (; comp(it + 1, 3) <= n; it++);
	n -= comp(it, 3);
	for (int i = 0; i < it; i++)
		for (int e = i + 1; e < it; e++)
			arr[i][e] = arr[e][i] = 1;
	int ans = it, full_cnct = it;
	while (n) {
		int req = 2;
		for (; req <= full_cnct && comp(req + 1, 2) <= n; req++);
		n -= comp(req, 2);
		for (int i = 0; i < req; i++)
			arr[i][ans] = arr[ans][i] = 1;
		ans++;
	}
	cout << ans << '\n';
	for (int i = 0; i < ans; i++) {
		for (int e = 0; e < ans; e++)
			cout << arr[i][e];
		cout << '\n';
	}
	return 0;
}
