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

const int N = 1e5+10;
const int mod = 1e9+7;
const int LOGN = 20;

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
 

int n, i, m, R[N], M[N];
II a[N];
vector<VI> V;

struct node { 
	int count;
	node *left, *right;

	node(int count, node *left, node *right) : count(count), left(left), right(right) {}
	node *insert(int low, int high, int val);
};

node *null = new node (0, NULL, NULL);
node *root[N];

node* node::insert(int low, int high, int val) {
	if(low == high && low == val) {
		return new node(this->count+1, null, null);
	}
	else if( (low > val) || (high < val	)) {
		return this;
	}
	int mid = (low + high) >> 1;
	return new node(this->count + 1, (this->left)->insert(low, mid, val), (this->right)->insert(mid+1, high, val));
}

int query(node* a, int low, int high, int k) {
	if(low == high) { 
		return low;
	}
	int sum = (a->left)->count;
	int mid = (low + high ) >> 1;
	if(sum >= k) {
		return query(a->left, low, mid, k);
	}
	return query(a->right, mid+1, high, k-sum);
}

int main () { 

	ios::sync_with_stdio(false);	
	cin.tie(NULL);
	
	cin >> n >> m;
	map<int, int > ma;

	V.resize(n+1);

	rep(i, 1, n+1) {
		cin >> a[i].F;
		a[i].S = i;
		ma[a[i].F] = i;
	}

	sort(a+1, a+1+n);

	//M -> 	stores the compressed value for an index(i)
	//R -> stores the actual value for the compressed value
	rep(i, 1, n+1) {
		M[a[i].S] = i;	
		R[i] = a[i].F;
	}

	rep(i, 1, n+1) { 
		V[ma[a[i].F]].PB(a[i].S);
	}

	
	null->left = null;
	null->right = null;
	root[0] = null;

	rep(i, 1, n+1) { 
	  root[i] = root[i-1]->insert(1, n, M[i]);
	}

	while(m--) { 
		int u, v, k;
		cin >> k >> u >> v;
		int t = R[query(root[u+1], 1, n, k)];
		//trace(t, ma[t], (int)V[ma[t]].size(), v-1);
		if( v > (int)V[ma[t]].size()) { 
			cout << -1 << endl;
		}
		else 
			cout << V[ma[t]][v-1] - 1 << endl;
	}
	return 0;
}	