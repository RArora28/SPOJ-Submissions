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

int dp[1005][1005], K;
char str1[1005], str2[1005];

int ans(int i, int j, int k1, int k2) {

  if(i < 0 || j < 0) {
    if(k1 >= K && k2 >= K)
      return 0;
    else
      return INT_MIN;
  }

  else if(str[i] == str[j]) {
    temp = ans(i-1, j-1,  k1 + 1, k2 + 1);

    if(k1 >= k && k2 < K)
      temp = max(temp, ans(i-1, j, 0, k2+1));
    else if(k2 >= k && k1 < K) {
}

int main() {
  
  int i, ind = 1;

  while(1) {
   
    cin>>k;

    if(k == 0)
      return 0;
    
    cin>>str1>>str2;
    int len1 = strlen(str1);, len2 = strlen(str2);

    
  }

  return 0;
}

