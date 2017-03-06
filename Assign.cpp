/* Rishabh Arora
   IIIT-Hyderabad */

#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> II;
typedef vector<int> VI;
typedef vector<II> VII;
typedef long long int LL;
typedef unsigned long long int ULL;

#define MAXSIZE 100005
#define mod 1000000007
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

LL c[30][30], dp[1<<22][30], b[30];
LL n;
LL e;

LL rec(LL mask, LL N)
{
  if( mask == e)
    return 1;
  
  else if(N >= n)
    return 0;
  
  else if (dp[mask][N] != -1)
    return dp[mask][N];
  
  LL i, ans = 0;

  rep(i, 0, n)
    if( (c[i][N] == 1) && ((mask & (b[i])) == 0) )
      ans += rec(mask|b[i], N+1);
  return dp[mask][N] = ans;
}

int main() {

  LL t;
  scanf("%lld", &t);
  LL i, j;

  b[0] = 1;

  rep(i, 1, 22)
    b[i] = 2*b[i-1];
  
  while(t--)
    {
      scanf("%lld", &n);

      rep(i, 0, 1<<n)
	rep(j, 0, n)
	dp[i][j] = -1;
      
      e = (1 << (n)) - 1;
      
      rep(i, 0, n)
	rep(j, 0, n)
	scanf("%lld", &c[i][j]);
      
      printf("%lld\n", rec(0, 0));
    }
  return 0;
}
