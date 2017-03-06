/* Rishabh Arora
   IIIT-Hyderabad */

#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> II;
typedef vector<int> VI;
typedef vector<II> VII;
typedef long long int LL;
typedef unsigned long long int ULL;

#define rep(i, a, b) for(i = a; i < b; i++)
#define rev(i, a, b) for(i = a; i > b; i--)
#define INF INT_MAX
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SET(a,b) memset(a, b, sizeof(a))

//debugging statements
#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

const int N = 1e5;
const int mod = 1e9+7;

struct node {
	node *left, *right;
	int count, ind;
	node () {
		left = right = NULL; 
		count = 0;
		ind = INT_MAX;
	}
};

void insert(node *currNode, string s, int level, int ind) {
	if(level == 32) {
		currNode->count++;
		currNode->ind = min(currNode->ind, ind);
		return;
	}
	else if(s[level] == '0') {
		if(!currNode->left) {
			currNode->left = new node;
		}
		(currNode->count)++;
		return insert(currNode->left, s, level+1, ind);
	}
	if(!currNode->right) {
		currNode->right = new node;
	}
	(currNode->count)++;
	return insert(currNode->right, s, level+1, ind);
}

node* del(node *currNode, string s, int level) {
	(currNode->count)--;
	if(level == 32) {
		if(currNode->count == 0) {
			currNode = NULL;
		}
		return currNode;
	}
	if(s[level] == '0') {
		currNode->left = del(currNode->left, s, level+1);
	}
	else {
		currNode->right = del(currNode->right, s, level+1);
	}
	if(currNode->count == 0) {
		currNode = NULL;
	}
	return currNode;
}

bool find(node *currNode, string s, int level) {
	if(level == 32) {
		return true;
	}

	else if(s[level] == '0') {
		if(currNode->left) {
			return find(currNode->left, s, level+1);
		}
		else return false;
	}
	else {
		if(currNode->right) {
			return find(currNode->right, s, level+1);
		}
		else return false;
	}
}

II maximise(node *currNode, string s, int level, int val) {
	if(level == 32) {
		return {val, currNode->ind};
	}
	else if(s[level] == '0') {
		if(currNode->right) {
			return maximise(currNode->right, s, level+1, 2*val + 1);
		}
		else return maximise(currNode->left, s, level+1, 2*val);
	}
	else {
		if(currNode->left) {
			return	maximise(currNode->left, s,level+1, 2*val+1);
		}
		else return maximise(currNode->right, s, level+1, 2*val);
	}
}

string toString(int val) {
	string s;
	while(val > 0) {
		if(val & 1) {
			s += '1';
		}
		else { 
			s += '0';
		}

		val >>= 1;
	}

	while(s.size() < 32) {
		s += '0';
	}

	reverse(s.begin(), s.end());
	return s;
}

int a[N], pre[N];

int main() {
	int n;
	cin >> n;
	a[0] = 0;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	node *trie = new node;
	pre[0] = 0;
	int A = -1, I, J;
	insert(trie, toString(0), 0, 1);
	for(int i = 1; i <= n; i++) {
		pre[i] = pre[i-1] ^ a[i];
		II temp = maximise(trie, toString(pre[i]), 0, 0);
		if(temp.F > A) {
			A = temp.F;
			I = temp.S;
			J = i;
		}
		else if(temp.F == A) {
			if(temp.S < I || temp.S == I && i < J) {
				I = temp.S;
				J = i;
			}
		}
		insert(trie, toString(pre[i]), 0, i+1);

	}
	cout << A << endl;
	cout << I << ' ' << J << endl;
	return 0;
}

