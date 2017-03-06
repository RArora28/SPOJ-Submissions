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

struct node {
	int Max, ans;
};

node seg[N];
int arr[N];

node merge(node A, node B) {
	node T;
	T.Max = max(A.Max, B.Max);
	T.ans = max(A.Max + B.Max, max(A.ans, B.ans));
	return T;
}

void build(int low, int high, int pos) {
	if(low == high) {
		seg[pos].Max = arr[low];
		seg[pos].ans = -INF;
		return;
	}
	int mid = (low + high) >> 1;
	build(low, mid, 2*pos);
	build(mid+1, high, 2*pos+1);
	seg[pos] = merge(seg[2*pos], seg[2*pos+1]);
	return;
}

node query(int low, int high, int l, int r, int pos) {
	if(l <= low && r >= high) {
		return seg[pos];
	}
	else if(l > high || r < low || l > r) {
		return	(node){-INF, -INF};
	}
	int mid = (low + high) >> 1;
	return merge(query(low, mid, l, r, 2*pos), query(mid+1, high, l, r, 2*pos+1));
}

void update(int low, int high, int ind, int pos) {
	if(low == ind && high == low) {
		seg[pos].Max = arr[ind];
		seg[pos].ans = -INF;
		return;
	}
	else if(ind > high || ind < low) {
		return;
	}
	int mid = (low + high) >> 1;
	update(low, mid, ind, 2*pos);
	update(mid+1, high, ind, 2*pos+1);
	seg[pos] = merge(seg[2*pos], seg[2*pos+1]);
	return;	
}

int main() {

	ios::sync_with_stdio(false);	
 	cin.tie(NULL);

	int n, q;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	build(1, n, 1);
	cin >> q;
	while(q--) {
		char ch;
		int x, y;
		cin >> ch >> x >> y;
		if(ch == 'U') {
			arr[x] = y;
			update(1, n, x, 1);
		}
		else {
			node T = query(1, n, x, y, 1);
			cout << T.ans << '\n';
		}
	}	
}