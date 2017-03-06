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

const LL N = 1e6+10;
const LL mod = 1e9+7;

LL phi[N];
LL  ans[N];

void calculatephi(int n) {
	for(int i = 1; i <= n; i++)
		phi[i]=i;
	for(int i = 2; i <= n; i++) {
		if(phi[i] == i) {
			for(int j = i; j <= n; j+= i) {
				phi[j] *= (i-1);
				phi[j] /= i;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);	
	cin.tie(NULL);

	int t;
	calculatephi(1e6+2);
	cin >> t;

	for(int i = 1; i <= 1e6+2; i++) {
		for(int j = i; j <= 1e6+2; j += i) {
			ans[j] += (LL)i*(LL)phi[i];
		}
	}

	while(t--) { 
		LL n;
		cin >> n;
		cout << (LL)(n*ans[n] + n)/2 << '\n';
	}
	return 0;
}