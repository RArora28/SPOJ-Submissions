/* Rishabh Arora
   IIIT-Hyderabad */
 
#include <bits/stdc++.h>
using namespace std;
 
typedef pair<long long int,long long int> II;
typedef vector<long long int> VI;
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
 
const long long int  N = 1e5+5;
const long long int LOGN = 15;

int prime[N];

void segmented_sieve(int start, int diff) {
   for(int i = 0; i <= diff; i++) prime[i] = 0;
   
   int sq = sqrt(start+diff);
   for(int i = 2; i <= sq; i++) {
    int  t = start-(start%i);
    for(int j = t; j <= start+diff; j += i) {
      prime[j-start] = 1;
    }
   }
   return;
}

int main() {
  int t;
  cin >> t;
  while(t--) {
    int a, b;
    cin >> a >> b;
    segmented_sieve(a, b-a);   
    for(int i = 0; i <= b-a; i++) {
      if(!prime[i]) {
        cout << i + a << endl;
      }
    }
  }
}