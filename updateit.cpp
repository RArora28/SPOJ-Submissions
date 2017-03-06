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

int bit[100010];

void updateBit(int idx, int n, int val) {

  while(idx <= n) {
    bit[idx] += val;
    idx += idx & -idx;
  }
  
  //cout<<idx<<endl;
  return;
}

int query(int idx) {
  int sum = 0;

  while(idx > 0) {
    sum += bit[idx];
    idx -= idx & -idx;
  }

  return sum;
}

int main() {

  int t, l, r, val;

  si(t);
  
  while(t--) {
    
    int n, u;

    si(n);
    si(u);

    int i;
    rep(i, 1, n+1)
      bit[i] = 0;
	
    while(u--) {
      
      si(l); si(r); si(val);
      
      updateBit(l+1, n, val);
      updateBit(r+2, n, -val);
    }

    int q, x;

    cin>>q;
    
    while(q--) {
      cin>>x;
      pi(query(x+1));
    }
    
  }
  
  return 0;
}

//here we maintain a bit of differences(telling the no. of updates) to be applied on the path way of query(here query gives the array value of that index
