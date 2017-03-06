#include<bits/stdc++.h>
#include<limits.h>
using namespace std;

#define mod 1000000007
#define si(x) scanf("%d", &x)
#define sll(x) scanf("%lld", &x)
#define pi(x) printf("%d\n", x)
#define pll(x) printf("%lld\n", x)
#define ii pair<long long int , long long int>
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

ii p[2000005];
ll sum1[2000005], val[2000005], sum2[2000005];

int main() {

  ll n, s, i, j;
  
  cin>>s>>n;

  rep(i, 1, n+1)
    cin>>p[i].fi>>p[i].se;

  int k;
  
  sum1[0] = 1;
  val[0] = 0;
  
  rep(i, 1, n+1) {
    
    rep(j, 0, s+1) {
      sum2[j] = sum1[j];
      //cout<<sum2[i]<<" ";
    }

    // cout<<sum2[0]<<endl;
    
    // cout<<endl;
    
    rep(j, 0, s+1) {
      
      k = j + p[i].se;    
      
      if(sum1[j] == 1 && k <= s) {
	sum2[k] = 1;
	val[k] = max(val[k], val[j] + p[i].fi);
      }
    }

    rep(j, 0, s+1)  {
      sum1[j] = sum2[j];
    }

    //cout<<endl;
  }
  
  ll m = -1;
  
  rep(i, 0, s+1) {
    //cout<<val[i]<<endl;
    m = max(m, val[i]);
  }
  
  cout<<m<<endl;
  
  return 0;
}
