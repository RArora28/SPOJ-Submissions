/* Rishabh Arora
   IIIT-Hyderabad */
 
#include <bits/stdc++.h>
using namespace std;
 
typedef pair<long long int,long long int> II;
typedef vector<long long int> VI;
typedef vector<II> VII;
typedef long long int LL;
typedef unsigned long long int ULL;
 
#define MAXSIZE 100005
#define mod 1000000007
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
 
const long long int  N = 1e5+5;
const long long int LOGN = 15;

struct node {
  int k[3];
};

int lazy[4*N];
node tree[4*N];

node merge(node a, node b) {
  node t; 
  for(int i = 0; i < 3; i++) {
    t.k[i] = a.k[i] + b.k[i];
  }
  return t;
}

node shift(node a, int val) {
  int t[3];
  t[0] = 0;
  t[1] = 0;
  t[2] = 0;
  val %= 3;
  for(int i = 0; i < 3; i++) {
    t[(i+val)%3] += a.k[i];
  }
  for(int i = 0; i < 3; i++) {
    a.k[i] = t[i];
  }
  return a;
}

void build(int low, int high, int pos) {
  if(low == high) {
    tree[pos].k[0] = 1;
    return;
  }
  int mid = (low + high) >> 1;
  build(low, mid, 2*pos);
  build(mid+1, high, 2*pos+1);
  tree[pos] = merge(tree[2*pos], tree[2*pos+1]);
  return ;
}
void update(int low, int high, int pos, int l, int r, int val) {
  if(lazy[pos]) {
    tree[pos] = shift(tree[pos], lazy[pos]);
    if(low != high){
      lazy[2*pos] += lazy[pos];
      lazy[2*pos+1] += lazy[pos];
    }
    lazy[pos] = 0;
  }
  if( (low > high) || (low > r) || (high < l)) {
    return;
  }

  else if(l <= low && high <= r) {
    tree[pos] = shift(tree[pos], val);
    if(low != high) {
      lazy[2*pos] += val;
      lazy[2*pos+1] += val;
    }
    return;
  }
  int mid = (low + high) >> 1;
  update(low, mid, 2*pos, l, r, val);
  update(mid+1, high, 2*pos+1, l, r, val);
  tree[pos] = merge(tree[2*pos], tree[2*pos+1]);
  return;
}

node query(int low, int high, int pos, int l, int r) { 
  if(lazy[pos]) {
    tree[pos] = shift(tree[pos], lazy[pos]);
    if(low != high) {
      lazy[2*pos] += lazy[pos];
      lazy[2*pos+1] += lazy[pos];
    }
    lazy[pos] = 0;
  }
  if( (low > high) || (low > r) || (high < l)) {
    node X;
    X.k[0] = 0, X.k[1] = 0, X.k[2] = 0;
    return X;
  }
  else if(l <= low && high <= r) {
    return tree[pos];   
  }
  int mid = (low + high) >> 1;
  return merge(query(low, mid, 2*pos, l, r), query(mid+1, high, 2*pos+1, l, r));
}

#define si(x) scanf("%d", &x);

int main() {
  int n, q;
  si(n); si(q);
  for(int i = 0; i < 4*n; i++) {
    for(int j = 0; j < 3; j++) {
      tree[i].k[j] = 0;
    }
  }
  build(1, n, 1);
  while(q--) {
    int opt, a, b;
    si(opt); si(a); si(b);
    if(!opt){
      update(1, n, 1, a+1, b+1, 1);
    }
    else {
      node X = query(1, n, 1, a+1, b+1);
      printf("%d\n", X.k[0]);
    }
  }
  return 0;
}