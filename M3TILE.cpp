/* Rishabh Arora
   IIIT-Hyderabad */

#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> II;
typedef vector<int> VI;
typedef vector<II> VII;
typedef long long int LL;
typedef unsigned long long int ULL;

#define rep(i, a, b) for(i = a; i < b; i++)
#define rev(i, a, b) for(i = a; i > b; i--)
#define INF INT_MAX
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SET(a,b) memset(a, b, sizeof(a))

//debugging statements
#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

const int N = 1e5;
const int mod = 1e9+7;

LL n, dp[50][50][50];

LL rec(LL l1, LL l2, LL l3)
{
  if(l1 == n && l2 == n && l3 == n)
    return 1;
  else if( (l1 > n) || (l2 > n) || (l3 > n) )
    return 0;
  else if(l2 > l1 || l3 > l2 || l3 > l1)
    return 0;
  else if(dp[l1][l2][l3] != -1)
    return dp[l1][l2][l3];
  LL a = 0;

  if(l2-l1>1)
    a += rec();
  return dp[l1][l2][l3] = a;
}

int main() {
  
  ios::sync_with_stdio(false);	
  cin.tie(NULL);
  
  while(1)
    {
      cin>>n;
      
      if(n == -1)
	return 0;
      LL ans = 0;
      if(n == 0)
	ans = 0;
      else {
	LL i, j, k;

	rep(i, 0, 50)
	  rep(j, 0, 50)
	  rep(k, 0, 50)
	  dp[i][j][k] = -1;
	
	ans = rec(0, 0, 0);
      }
      
      cout<<ans<<endl;
    }
  
  return 0;
}
