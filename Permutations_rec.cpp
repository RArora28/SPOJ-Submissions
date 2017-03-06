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

int dp[100][100];
 
int perm(int n, int k) {

  if(k == 0)
    return 1;
  
  else if(n == 1) 
      return 0;
  
  else if(dp[n][k] != -1)
    return dp[n][k];
  
  else {
    int i, sum = 0;
    
    rep(i, 0, k+1)
      if(k - i < n)
	sum += perm(n-1, i);
    
    return dp[n][k] = sum;
  }
}

int main() {
 
  int d, i, n, k;
 
  cin>>d;
 
  memset(dp, -1, sizeof(dp));
  
  while(d--) {
    
    cin>>n>>k;

    if(k > n*(n-1)/2)
      cout<<"0"<<endl;
    else
      cout<<perm(n, k)<<endl;
  }
  
  return 0;
}
