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
#define gc getchar_unlocked

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

LL phi[1000010];
  
int main() {

  LL i, j;

  ios::sync_with_stdio(false);	
  cin.tie(NULL);

  rep(i, 1, 1e6+5)
    phi[i] = i;
  
  rep(i, 2, 1e6+5) 
    if(phi[i] == i)
      for(j = i; j <= (1e6+5); j+=i) {
	     phi[j] *= (i-1);
  	   phi[j] /= i;
      }
  
  LL t;
  
  cin>>t;

  while(t--) { 
    LL x;
    cin>>x;
    cout<<phi[x]<<endl;
  }
    
  return 0;
}
