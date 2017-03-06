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

int n, bit[200010], a[200010];

void update(int idx) {
  
  while(idx <= n) {
    bit[idx] += 1;
    idx += idx & (-idx);
  }

  return;
}

int cum(int idx) {

  int sum = 0;

  while(idx > 0) {
    sum += bit[idx];
    idx -= idx & (-idx);
  }

  return sum;

}

int main() { 
  
  int t, i, temp;
  
  si(t);

  while(t--) { 
    
    map<int, int> m;
    ll inv = 0;
    si(n);

    rep(i, 1, n+1) {  
      si(a[i]);
      m[a[i]] = 0;
    }
    
    memset(bit, 0, (n+3)*sizeof(int));
    
    int ind = 1;

    for(auto it : m) 
      m[it.fi] = ind++;
    
    rep(i, 1, n+1) {
      temp = m[a[i]];
      update(temp);
      inv += (ll)cum(n)-(ll)cum(temp);
    }
  
    cout<<inv<<endl;    
  }

  return 0;
}

