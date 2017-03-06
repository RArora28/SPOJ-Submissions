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
 

const int N = 1e6+10;
const int mod = 1e9+7;
const int LOGN = 20;

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

int IND[N];
map<int, int > ma;

int main () { 

	ios::sync_with_stdio(false);	
	cin.tie(NULL);
	
	cin >> n >> m;
	
	V.resize(n+10);

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
		IND[a[i].S] = (int)(V[ma[a[i].F]].size()-1);
	}

	int opt;

	null->left = null;
	null->right = null;
	root[0] = null;

	rep(i, 1, n+1) { 
	  root[i] = root[i-1]->insert(1, n, M[i]);
	}

	while(m--) { 
		int u, v, k;
		cin >> opt;
		if(opt == 0) { 
			cin >> u >> v >> k;
			int t = R[query(root[u+1], 1, n, k)];
		
			if( v > (int)V[ma[t]].size()) { 
				cout << -1 << '\n'
			}
			else 
				cout << V[ma[t]][v-1] - 1 << '\n';
		}
		else {
			cin >> u;
			u += 1;
			root[u+1] = NULL;
			root[u] = NULL;
			root[u] = root[u-1]->insert(1, n, M[u+1]);
			root[u+1] = root[u]->insert(1, n, M[u]);
			V[ma[R[M[u]]]] [IND[u]] = u+1;
			V[ma[R[M[u+1]]]] [IND[u+1]] = u;
			swap(M[u], M[u+1]);
		}
	}

	return 0;
}	