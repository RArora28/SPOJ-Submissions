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

int n, Max, a[20], b[20];
bool dp[1 << 20][20];
II X[1<<20][20];

II rec(int mask, int ind, int val)
{
  if(mask == Max)
    return MP(a[ind], 1);
  else if(dp[mask][ind])
    return X[mask][ind];
  int i, s = 0, cnt = 0;
  rep(i, 0, n)
    if( (mask & b[i]) == 0)
      {
	int y = a[ind];
	if(val == -1)
	  y = 0;
	II t = rec(mask|b[i], i, 1);
	t.F += abs(a[i]-y);
	if(t.F > s)
	  {
	    s = t.F;
	    cnt = t.S;
	  }
	else if(t.F == s)
	  cnt += t.S;
      }
  X[mask][ind].F = s;
  X[mask][ind].S = cnt;
  dp[mask][ind] = true;
  return X[mask][ind];
}

int main() {
  
  ios::sync_with_stdio(false);	
  cin.tie(NULL);

  int i;
  b[0] = 1;
  rep(i, 1, 20)
      b[i] = 2*b[i-1];
    
  while(1)
    {
      cin>>n;
      if(n == 0) return 0;
      rep(i, 0, n)
	cin>>a[i];
      Max = (1 <<n) -1;
      SET(dp, false);
      II T = rec(0, 0, -1);
      T.F += 2*n;
      cout<<T.F<<" "<<T.S<<endl;
    }
  return 0;
}
