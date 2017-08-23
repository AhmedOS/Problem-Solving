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

int t, n, arr[23][23], dna[16];

int dirr[] = { 0, 0, 1, -1 };
int dirc[] = { 1, -1, 0, 0 };

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> t;
	while (t--) {
		memset(arr, 0, sizeof(arr));
		cin >> n;
		for (int i = 0; i < 16; i++)
			cin >> dna[i];
		for (int i = 1; i <= 20; i++)
			for (int e = 1; e <= 20; e++)
				cin >> arr[i][e];
		while (n--) {
			int tmp[23][23];
			for (int i = 1; i <= 20; i++)
				for (int e = 1; e <= 20; e++) {
					int sum = arr[i][e];
					for (int d = 0; d < 4; d++)
						sum += arr[i + dirr[d]][e + dirc[d]];
					sum = dna[sum];
					sum += arr[i][e];
					if (sum >= 0 && sum <= 3)
						tmp[i][e] = sum;
					else if (sum < 0)
						tmp[i][e] = 0;
					else
						tmp[i][e] = 3;
				}
			for (int i = 1; i <= 20; i++)
				for (int e = 1; e <= 20; e++)
					arr[i][e] = tmp[i][e];
		}
		char ch[] = { '.', '!', 'X', '#' };
		for (int i = 1; i <= 20; i++) {
			for (int e = 1; e <= 20; e++)
				cout << ch[arr[i][e]];
			cout << '\n';
		}
		if (t)
			cout << '\n';
	}
	return 0;
}
