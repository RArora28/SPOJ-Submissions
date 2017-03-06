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

const int N = 1e5+10;
const int mod = 1e9+7;

int dp[2][N];
vector<VI> g;

void dfs(int v, int p) {
	dp[0][v] = 0;
	dp[1][v] = 1;
	for(auto u : g[v]) {
		if(u != p) {
			dfs(u, v);
			dp[1][v] += min(dp[1][u], dp[0][u]);
			dp[0][v] += dp[1][u];
		}
	}
	return;
}

int main() {

  ios::sync_with_stdio(false);	
  cin.tie(NULL);
  int n;
  cin >> n; g.resize(n+1);
  for(int i = 1 ; i < n; i++) {
  	int a, b;
  	cin >> a >> b;
  	g[a].PB(b);
  	g[b].PB(a);
  }	  
  dfs(1, -1);
  cout << min(dp[1][1], dp[0][1]) << endl;
  return 0;
}
