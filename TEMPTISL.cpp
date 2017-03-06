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

ll dp[55][55], A, B, K, N;

ll rec(ll i, ll k) {
  
  if(k == 0) {
    if(i == B)
      return 1;
    else
      return 0;
  }

  else if(dp[i][k] != -1)
    return dp[i][k];

  else {
    if(i > 1 && i < N)
      return dp[i][k] = rec(i+1, k-1) + rec(i-1, k-1);
    else if(i == 1)
      return dp[1][k] = rec(2, k-1) + rec(N, k-1);
    else
      return dp[N][k] = rec(1, k-1) + rec(N-1, k-1);
  }
}


int main() {
  
  while(1) {

    cin>>N>>K;

    if(N == -1 && K == -1)
      return 0;
    
    memset(dp, -1, sizeof(dp));
    
    cin>>A>>B;
    
    cout<<rec(A, K)<<endl;
  }

  return 0;
}

