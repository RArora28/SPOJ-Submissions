#include<bits/stdc++.h>
#include<limits.h>
using namespace std;

#define mod 1000000007
#define si(x) scanf("%d", &x)
#define sll(x) scanf("%lld", &x)
#define pi(x) printf("%d\n", x)
#define pll(x) printf("%lld\n", x)
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<pair<int, int> >
#define adjList vector<vector<int> >
#define ll long long int
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define rep(i, z, q) for(i = z; i < q; i++)
#define rev(i, z, q) for(i = z; i > q; i--)
#define gc getchar_unlocked

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }
ll power(ll a,ll b) {
  ll ans = 1;  
  while(b > 0){
    if(b & 1)
      ans = ((ans % mod) *(a % mod)) % mod;
    a=((a % mod)*(a % mod)) % mod;
    b >>= 1;
  }
  return ans;
}

int read_int() {
  char c = gc();
  while(c<'0' || c>'9') c = gc();
  int ret = 0;
  while(c>='0' && c<='9') {
    ret = 10 * ret + c - 48;
    c = gc();
  }
  return ret;
}

int a[30010], query[200010], c[1000010], n, answer = 0;

struct node {
  int l, r, a;
};

bool compare(node A, node B) {
  return A.r < B.r;
}

vector< vector <node> > adj;

inline void add(int ind) {
  
  if(ind <= 0 || ind >= n+1)
    return;
  
  int temp = a[ind];
  
  ++c[temp];

  if(c[temp] == 1) 
    answer++;
  
  return;
}

inline void remove(int ind) {
  
  if(ind <= 0 || ind >= n+1)
    return;
 
  int temp = a[ind];
  
  --c[temp];

  if(c[temp] ==  0) 
      answer--;
 
 return;
}

int main() { 

  int i, q, l, r;
  int m = INT_MIN;

  n = read_int();
  
  rep(i, 1, n+1)  {
    a[i] = read_int();
    m = max(m, a[i]);
  }
  
  int temp = sqrt(n);
  int size = (n/temp) + 3;
  adj.resize(size);
  
  q = read_int();
  
  rep(i, 1, q+1) {
    l = read_int();
    r = read_int();
    
    node T;
    T.l = l; 
    T.r = r; 
    T.a = i;
    
    if(l % temp == 0)
      adj[l/temp].pb(T);
    else 
      adj[l/temp + 1].pb(T);
  }
  
  rep(i, 1, size)
    sort(adj[i].begin(), adj[i].end(), compare);
  
  rep(i, 1, size) {
    
    answer = 0;
    memset(c, 0, (m+2)*sizeof(int));

    int start = (i-1)*temp;
    int end = start;

    for(auto it : adj[i]) {
      int L = it.l;
      int R = it.r;

      while(end <=  R) {
	add(end);
	end++;
      }
      
      while(start < L) {
	remove(start);
	start++;
      }
      
      while(start > L) {
	add(start-1);
	start--;
      }

      query[it.a] = answer;
    }
  }

  rep(i, 1, q+1)
    pi(query[i]);
  
  return 0;
}
 
