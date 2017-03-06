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

const LL N = 1e5+10;
const LL mod = 1e9+7;

vector<vector<pair<LL, LL > > > g;

LL dp[N],ans = 0;

LL power(LL a, LL b) {
	LL ans = 1;
	while(b > 0) {
		if(b & 1) {
			ans *= a;
			ans %= mod;
		}
		a *= a;
		a %= mod;
		b >>= 1;
	}
	return ans;
}

void dfs(LL v, LL p) {
	dp[v] = 0;
	LL x = 0, y = 0;
	for(auto U : g[v]) {
		LL u = U.F;
		LL w = U.S;
		if(u != p) {
			dfs(u, v);
			dp[v] += ( ( ( dp[u] + 1) % mod) * (w % mod) )%mod;
			dp[v] %= mod;
			x += ( ( ( dp[u]+1 ) % mod) * ( w % mod ) ) % mod;
			x %= mod;
			y += ( ( ( ( ( dp[u]+1) % mod) * ( ( dp[u]+1) % mod) ) % mod)*( ( w *w ) % mod) )%mod;
			y %= mod;
		}
	}
	//trace(v, x, y, dp[v]);
	x *= x % mod;
	x %= mod;
	ans += (((x + mod - y) % mod)*power(2, mod-2))%mod;
	ans %= mod;
	ans += dp[v];
	ans %= mod;
	return;
}

int main() {
	LL n;
	cin >> n; g.resize(n+10);
	for(LL i = 1; i < n; i++) {
		LL a, b, w; cin >> a >> b >> w;
		g[a].PB({b, w});
		g[b].PB({a, w});
	}
	dfs(1, -1);
	cout << ans % mod << '\n';
	return 0;
}