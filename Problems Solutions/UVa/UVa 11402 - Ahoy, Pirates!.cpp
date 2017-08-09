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

int t, m, q;

struct node {
	int br = 0, bu = 0;
	int lazy = -1; // 0->br , 1->bu, 2->invert
};

int arr[1024000];
node seg[2100000];

void merge(node *p, node *l, node *r) {
	p->br = l->br + r->br;
	p->bu = l->bu + r->bu;
}

void push_down(int p, bool leaf) {
	if (seg[p].lazy == -1)
		return;
	if (seg[p].lazy == 0) {
		seg[p].br += seg[p].bu;
		seg[p].bu = 0;
		if (!leaf) {
			seg[p * 2].lazy = seg[p].lazy;
			seg[p * 2 + 1].lazy = seg[p].lazy;
		}
	}
	else if (seg[p].lazy == 1) {
		seg[p].bu += seg[p].br;
		seg[p].br = 0;
		if (!leaf) {
			seg[p * 2].lazy = seg[p].lazy;
			seg[p * 2 + 1].lazy = seg[p].lazy;
		}
	}
	else if (seg[p].lazy == 2) {
		swap(seg[p].br, seg[p].bu);
		if (!leaf) {
			for (int i = 0; i < 2; i++) {
				if (seg[p * 2 + i].lazy == 2)
					seg[p * 2 + i].lazy = -1;
				else if (seg[p * 2 + i].lazy == 1)
					seg[p * 2 + i].lazy = 0;
				else if (seg[p * 2 + i].lazy == 0)
					seg[p * 2 + i].lazy = 1;
				else
					seg[p * 2 + i].lazy = seg[p].lazy;
			}
		}
	}
	seg[p].lazy = -1;
}

void update(int p, int s, int e, int ss, int ee, int value) {
	//even if the node is out of range, its parent is in range and should merge with correct values
	push_down(p, s == e);
	if (ss > e || ee < s)
		return;
	if (s >= ss && e <= ee) {
		seg[p].lazy = value;
		push_down(p, s == e);
		return;
	}
	int mid = (s + e) / 2;
	update(p * 2, s, mid, ss, ee, value);
	update(p * 2 + 1, mid + 1, e, ss, ee, value);
	merge(&seg[p], &seg[p * 2], &seg[p * 2 + 1]);
}

node dummy;

node query(int p, int s, int e, int ss, int ee) {
	if (ss > e || ee < s)
		return dummy;
	push_down(p, s == e);
	if (s >= ss && e <= ee)
		return seg[p];
	int mid = (s + e) / 2;
	node ret;
	node l = query(p * 2, s, mid, ss, ee);
	node r = query(p * 2 + 1, mid + 1, e, ss, ee);
	merge(&ret, &l, &r);
	return ret;
}

void build(int p, int s, int e) {
	seg[p].lazy = -1;
	if (s == e) {
		(arr[s] ? seg[p].bu : seg[p].br) = 1;
		(!arr[s] ? seg[p].bu : seg[p].br) = 0;
		return;
	}
	int mid = (s + e) / 2;
	build(p * 2, s, mid);
	build(p * 2 + 1, mid + 1, e);
	merge(&seg[p], &seg[p * 2], &seg[p * 2 + 1]);
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> t;
	for (int tt = 1; tt <= t; tt++) {
		cout << "Case " << tt << ":\n";
		int id = 0;
		cin >> m;
		for (int i = 0; i < m; i++) {
			int n;
			string s;
			cin >> n >> s;
			for (int e = 0; e < n; e++)
				for (int d = 0; d < s.size(); d++) {
					arr[id] = s[d] - '0';
					id++;
				}
		}
		build(1, 0, id - 1);
		cin >> q;
		int qq = 1;
		while (q--) {
			char ch;
			int a, b;
			cin >> ch >> a >> b;
			if (ch == 'F')
				update(1, 0, id - 1, a, b, 1);
			else if (ch == 'E')
				update(1, 0, id - 1, a, b, 0);
			else if (ch == 'I')
				update(1, 0, id - 1, a, b, 2);
			else if (ch == 'S')
				cout << "Q" << qq++ << ": " << query(1, 0, id - 1, a, b).bu << '\n';
		}
	}
	return 0;
}
