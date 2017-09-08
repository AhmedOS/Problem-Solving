//http://www.spoj.com/problems/GSS6 
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

int n, q;

struct node {
	int key; //left subtree size
	long long value; //int?
	node *left, *right, *parent;
	int height, balanceFactor, size;
	long long best, prefix, suffix, all; //int?
	static const long long badValue = -100000000000001;

	node() {
		memset(this, 0, sizeof(*this));
		size = 1;
	}

	node(int value) : node() { //C++11
		set_value(value);
	}

	void set_value(int value) {
		this->value = value;
		reset_merge();
	}

	void reset_merge() {
		best = prefix = suffix = all = value;
	}

	static int get_size(node *next) {
		return next ? next->size : 0;
	}

	static int get_balanceFactor(node *next) {
		return next ? next->balanceFactor : 0;
	}

	static node badNode() {
		node ret;
		ret.best = ret.prefix = ret.suffix = ret.all = ret.value = badValue;
		return ret;
	}

	static void merge(node *l, node *r, node *p) {
		if (l && r) {

			/*
			//direct merging, when badValue won't be used and no overflow would happen
			p->best = max({ l->best, r->best, l->suffix + r->prefix });
			p->prefix = max(l->prefix, l->all + r->prefix);
			p->suffix = max(r->suffix, r->all + l->suffix);
			p->all = l->all + r->all;
			*/

			long long suprfix = badValue;
			if (l->suffix != badValue && r->prefix != badValue)
				suprfix = l->suffix + r->prefix;
			p->best = max({ l->best, r->best, suprfix });

			long long allprefix = badValue;
			if (l->all != badValue && r->prefix != badValue)
				allprefix = l->all + r->prefix;
			p->prefix = max(l->prefix, allprefix);

			long long allsuffix = badValue;
			if (r->all != badValue && l->suffix != badValue)
				allsuffix = r->all + l->suffix;
			p->suffix = max(r->suffix, allsuffix);

			if (l->all == badValue || r->all == badValue)
				p->all = badValue;
			else
				p->all = l->all + r->all;

		}
		//if one of them isn't null, it should be the parent
	}

	void merge() {
		reset_merge();
		merge(left, this, this);
		merge(this, right, this);
	}

	void fix(bool and_merge = false) {
		int lh = left ? left->height : 0, rh = right ? right->height : 0;
		height = !left && !right ? 0 : 1 + max(lh, rh);
		balanceFactor = lh - rh;
		size = 1 + get_size(left) + get_size(right);
		key = get_size(left);
		if (and_merge)
			merge();
	}

	void rotateLeft() {
		if (parent)
			(parent->left == this ? parent->left : parent->right) = right;
		right->parent = parent;
		parent = right;
		node *r = right->left;
		right->left = this;
		right = r;
		if (right)
			right->parent = this;
	}

	void rotateRight() {
		if (parent)
			(parent->left == this ? parent->left : parent->right) = left;
		left->parent = parent;
		parent = left;
		node *l = left->right;
		left->right = this;
		left = l;
		if (left)
			left->parent = this;
	}

	void balance() {
		if (balanceFactor == 2) {
			if (get_balanceFactor(left) == -1)
				left->rotateLeft();
			rotateRight();
		}
		else if (balanceFactor == -2) {
			if (get_balanceFactor(right) == 1)
				right->rotateRight();
			rotateLeft();
		}
		else {
			merge(); //required because values have been changed
			return; //nothing else to do here
		}
		parent->left->fix(true);
		parent->right->fix(true);
		//parent will be updated later via update()
	}
};

struct AVL_Tree {
	// 0-indexing
	node *root = NULL;

	//Tools

	void update(node *next, bool rebalance) {
		while (next) {
			if (rebalance) {
				next->fix();
				next->balance();
			}
			else
				next->merge();
			root = next;
			next = next->parent;
		}
	}

	node *get_node(int index) {
		if (root == NULL || index < 0 || index >= root->size)
			return NULL;
		node *next = root;
		int rightSum = 0, curIndex = next->key;
		while (index != curIndex) {
			if (index < curIndex) {
				next = next->left;
			}
			else {
				rightSum += next->key + 1;
				next = next->right;
			}
			curIndex = next->key + rightSum;
		}
		return next;
	}

	bool is_leftChild(node *child) {
		if (child->parent == NULL)
			return 0; //doesn't matter 0 or 1
		return child->parent->left == child;
		//null child?
	}

	void connect_child(node *parent, node *child, bool leftChild) {
		if (parent == NULL)
			root = child;
		else
			(leftChild ? parent->left : parent->right) = child;

		if (child != NULL)
			child->parent = parent;
	}

	static void print(node *next) {
		if (next == NULL)
			return;
		print(next->left);
		cout << next->value << ' ';
		print(next->right);
	}

	//Primary functions

	node *append(int value) {
		node *parent = get_node(node::get_size(root) - 1);
		node *nn = new node(value);
		connect_child(parent, nn, false);
		update(nn, true);
		return nn;
	}

	node *insert(int index, int value) {
		node *next = get_node(index), *parent;
		if (next == NULL)
			return append(value);
		bool leftChild = true;
		if (next->left == NULL)
			parent = next;
		else {
			parent = get_node(index - 1); //predecessor
			leftChild = false;
		}
		node *nn = new node(value);
		connect_child(parent, nn, leftChild);
		update(nn, true);
		return nn;
	}

	node *set_value(int index, int value) {
		node *next = get_node(index);
		if (next != NULL) {
			next->value = value;
			update(next, false);
		}
		return next;
	}

	void erase(int index, bool kill = true) {
		node *next = get_node(index), *alt = NULL; //alt -> alternative
		if (next == NULL) //no such index
			return;
		if (next->left && next->right) {
			alt = get_node(index + 1); //successor
			erase(index + 1, false);
			connect_child(alt, next->left, true);
			connect_child(alt, next->right, false);
			//if tree is rebalanced after deleting successor, left could be null
			//if right was the successor, it would be null now
		}
		else if (next->left)
			alt = next->left;
		else if (next->right)
			alt = next->right;
		connect_child(next->parent, alt, is_leftChild(next));
		update(alt ? alt : next->parent, true);
		if (kill)
			delete next;
	}

	node query(node *next, int s, int e, int ss, int ee, int rightSum) {
		if (next == NULL) //if root == null
			return node::badNode();
		if (s >= ss && e <= ee)
			return *next;
		int index = next->key + rightSum;
		int rsz = node::get_size(next->right), lsz = node::get_size(next->left);
		int ne = e - rsz - 1;
		int ns = s + lsz + 1;
		if (index < ss)
			return query(next->right, s + lsz + 1, e, ss, ee, rightSum + lsz + 1);
		if (index > ee)
			return query(next->left, s, e - rsz - 1, ss, ee, rightSum);
		node ret = *next, temp;
		ret.reset_merge();
		if (ne >= ss && s <= ee && s <= ne) {
			temp = query(next->left, s, e - rsz - 1, ss, ee, rightSum);
			node::merge(&temp, &ret, &ret);
		}
		if (e >= ss && ns <= ee && ns <= e) {
			temp = query(next->right, s + lsz + 1, e, ss, ee, rightSum + lsz + 1);
			node::merge(&ret, &temp, &ret);
		}
		return ret;
	}
};

AVL_Tree avl;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int nm;
		cin >> nm;
		avl.append(nm);
	}
	cin >> q;
	for (int i = 0; i < q; i++) {
		char ch;
		int nm, nm2;
		cin >> ch >> nm;
		if (ch != 'D')
			cin >> nm2;
		nm--;
		if (ch == 'I')
			avl.insert(nm, nm2);
		else if (ch == 'D')
			avl.erase(nm);
		else if (ch == 'R')
			avl.set_value(nm, nm2);
		else if (ch == 'Q') {
			nm2--;
			cout << avl.query(avl.root, 0, node::get_size(avl.root) - 1, nm, nm2, 0).best << '\n';
		}
	}
	return 0;
}
