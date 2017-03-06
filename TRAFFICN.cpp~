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

int dp[1005][1005], counter = 1, n, a[1005];

int winner(int i, int j) {
  
  counter++;

  if(i >= j || i > n || j < 1)
    return 0;
  else if(dp[i][j] != -1)
    return dp[i][j];
  else {

    int temp;
    
    if(counter == 2)
      temp = max(a[i] + winner(i+1, j), a[j] + winner(i, j-1));
    else {
      if(a[i] >= a[j]) 
	temp = max(a[i+1] + winner(i+2, j), a[j] + winner(i+1, j-1));
      else
	temp = max(a[i] + winner(i+1, j-1), a[j-1] + winner(i, j-2));
    }
    
    dp[i][j] = temp;
    return dp[i][j];
  }
}


int main() {
  
  int i, ind = 1;

  while(1) {
    
    memset(dp, -1, sizeof(dp));
    
    cin>>n;
    
    if(n == 0)
      break;

    int total = 0;
    counter = 1;
    
    rep(i, 1, n+1) { 
      cin>>a[i];
      total += a[i];
    }
    
    cout<<"In game "<<ind<<", the greedy strategy might lose by as many as "<<2*winner(1, n)-total<<" points."<<endl;
    ind++;
  }

  return 0;
}

