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

int n, m;
int R[N], M[N], depth[N], par[N], P[N][LOGN];
II a[N];
vector<VI> g;

struct node {
	int count;
	node *left, *right;
	node() {}
	node(int count, node * left, node * right) :
		count(count), left(left), right(right) {}
	node *insert(int l, int r, int w);
};  
		
node *root[N];
node *null = new node(0, NULL, NULL);

node* node::insert(int low, int high, int w) {
	if(low == high && low == w) {
		return new node(this->count+1, null, null);
	}
	else if( (high < w) || (low > w) ) {
		return this;
	}
	int mid  = (low + high) >> 1;
	return new node(this->count+1, this->left->insert(low, mid, w), this->right->insert(mid+1, high, w)); 
}

int query(node* a, int low, int high, int l, int r) {
	if( (low > high) || (low > r) || (high < l)) {
		return 0;
	}
	else if( l <= low && high <= r) {
		return this->count;
	}
	int mid = (low + high) >> 1;
	return query(a->left, low, mid, l, r) + query(a->right, mid+1, high, l, r);
}

int main() {

	ios::sync_with_stdio(false);	
	cin.tie(NULL);
	  
	  int i;
	  cin >> n >> m;
	  g.resize(n+1);
	  rep(i, 1, n+1) {
			cin >> a[i].F ;
			a[i].S = i;
			X[a[i].F] = i;
	  }    

	  sort(a + 1,  a + n + 1);
	  
	  rep(i, 1, n+1) { 
	  	M[a[i].S] = i;
	  	R[i] = a[i].F;
	  	V[X[a[i].S]].PB()
	  }

	
	  null->left=null->right=null;
	  root[0] = null;


	  while(m--) {
			int u, v, k;
			cin >> u >> v >> k;
			int l = lca(u, v);
			int p = par[l];
			if (p == -1) p = 0;
			cout << R[query(root[u], root[v], root[l], root[p], 1, n, k)] << '\n';
	  }
	  return 0;
	}
