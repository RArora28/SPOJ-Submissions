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

adjList adj;
int ans[10010], len[10010], taken[10010];

ii dfs(int v) {
  
  bool flag = false;

  taken[v] = 1;
  
  int max1 = -1, max2 = -1, b = -1;
  
  for(auto it : adj[v]) {
    if(!taken[it]){ 
      
      flag = true;
      
      ii temp = dfs(it);
      int A = temp.fi;
      int B = temp.se;
      
      if(A >= max1) {
	max2 = max1;
	max1 = A;
      }
      
      else if(A > max2)
	max2 = A;
      
      if(B > b) 
	b = B;
    }
  }
  
  if(flag == true) {
    
    len[v] = max1+1;
    ans[v] = b;
    ans[v] = max(b, len[v]);
    
    if(adj[v].size() > 1) 
      ans[v] = max(len[v], max1 + max2 + 2);
  }
  
  if(!flag) 
    return mp(0, 0);
  else
    return mp(len[v], ans[v]);
}

int main() {

  int N;
  int i;
  
  cin>>N;

  adj.resize(N+1);
  int u, v;

  rep(i, 1, N) {
    cin>>u>>v;

    adj[v].pb(u);
    adj[u].pb(v);
  }
  
  ii temp = dfs(1);
  
  cout<<temp.se<<endl;
  
  return 0;
}

