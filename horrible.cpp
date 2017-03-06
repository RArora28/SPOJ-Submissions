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

ll bit1[1000010], bit2[1000010], max_val = -1;

void update(ll tree[], ll val, ll idx) {

  while(idx <= max_val) {
    tree[idx] += val;
    idx += idx & -idx;
  }
  return;
}


void update_val(ll a, ll b) {

  update(bit1, 1, a);
  update(bit1, -1, b+1);
  update(bit2, (a-1), a);
  update(bit2, -b ,b+1);
  return;
}

ll query(ll tree[], ll idx) {

  ll sum = 0;

  while(idx > 0) {
    sum += tree[idx];
    idx -= idx & -idx;
  }
  
  return sum;
}

ll q(ll x) {
  return x*query(bit1, x) - query(bit2, x);
}
  
ll ret_answer(ll a, ll b) {
  return q(b)-q(a-1);
}


int main() {

  ll t, i, q, x, y, n;

  cin>>n>>q;
  
  rep(i, 1, n+1) {
    cin>>x>>y;
    update_val(x, y);
    max_val = max(y, max_val);
    cout<<max_val<<endl;
  }

  rep(i, 1, max_val) {
    cout<<bit1[i]<<" "<<bit2[i]<<endl;
  }
  
  while(q--) {
    cin>>x>>y;
    cout<<ret_answer(x, y)<<endl;
  }
    
  return 0;
}

