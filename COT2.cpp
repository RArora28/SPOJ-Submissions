/* Rishabh Arora
   IIIT-Hyderabad */
 
#include <bits/stdc++.h>
using namespace std;
 
typedef pair<int,int> II;
typedef vector<int> VI;
typedef vector<II> VII;
typedef long long int LL;
typedef unsigned long long int ULL;
 
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
 
struct node { 
  LL lc, i, l, r;
};

const LL MAXSIZE = 1e6;
LL n, m, i, j, u, v;
LL sq, ans = 0, tim = 1, w[MAXSIZE], W[MAXSIZE], arr[2*MAXSIZE], in[MAXSIZE], out[MAXSIZE], L[MAXSIZE], par[MAXSIZE], P[MAXSIZE][50], cnt[MAXSIZE], vis[MAXSIZE], query[MAXSIZE];
bool taken[MAXSIZE];
vector<vector<LL> > adj;
vector<node> Q;
map<LL, LL> M;

bool cmp(node A, node B) { 
  if(A.l/sq != B.l/sq)
    return A.l/sq < B.l/sq;
  return A.r < B.r;  
} 
 
void dfs(LL v) { 
  taken[v] = true;
  in[v] = tim++;
  arr[in[v]] = v;
  for(auto it : adj[v])
    if(!taken[it]) {
      par[it] = v;
      L[it] = L[v] + 1;
      dfs(it);
    }
  out[v] = tim++;
  arr[out[v]] = v;
  return;
}

void LCApre(int N) { 
  
  int i, j;
   
  rep(i, 1, N+1)
    P[i][0] = par[i];
  
  for(j = 1; (1 << j) < N; j++) 
    rep(i, 1, N+1)
      if(P[i][j-1] != -1)
	     P[i][j] = P[P[i][j-1]][j-1];
  
  return;
}

int LCA(int p, int q) { 

  int i;
  
  if(L[p] < L[q])
    swap(p, q);
  
  int log;
  
  for(log = 1; (1 << log) <= L[p]; log++);
  log--;
  
  rev(i, log, -1) {
    if(L[p] - (1 << i) >= L[q])
      p = P[p][i];
  }
 if(p == q)
    return p;
  rev(i, log, -1) 
    if(P[p][i] != -1 && P[p][i] != P[q][i])
      p = P[p][i], q = P[q][i];
  
  return par[p];
}

inline void add(LL x) { 
  vis[x] ^= 1;
  LL temp = w[x];
  if(vis[x] == 1) { 
    cnt[temp]++;
    if(cnt[temp] == 1)
      ans++;
  }
  else {
    cnt[temp]--;
    if(cnt[temp] == 0)
      ans--;
  }
  return;
}

inline void remove(LL x) {
  vis[x] ^= 1;
  LL temp = w[x];
  if(vis[x] == 0) { 
    cnt[temp]--;
    if(cnt[temp] == 0)
      ans--;
  }
  else {
    cnt[temp]++;
    if(cnt[temp] == 1)
      ans++;
  }
  return; 
}
 
LL extra(LL x) { 
  if(cnt[w[x]] == 0)
    return 1;
  return 0;
}

#define SLL(n) scanf("%lld", &n)
int main() {
  
  SLL(n);
  SLL(m);
  adj.resize(n+2);
  
  rep(i, 1, n+1) {
    SLL(W[i]);
    M[W[i]];
  }
  
  LL ind = 1;
  for(auto &it : M) 
    M[it.F] = ind++;
  
  rep(i, 1, n+1) 
    w[i] = M[W[i]];
  
  rep(i, 1, n+1)
    rep(j, 0, 30)
    P[i][j] = -1;
  
  rep(i, 1, n) {
    SLL(u);
    SLL(v);
    adj[u].PB(v);
    adj[v].PB(u);
  }
  
  L[1] = 0, par[1] = -1;
  dfs(1);
  LCApre(n);
  sq = (int)sqrt(2*n);
  LL L;

  rep(i, 1, m+1) { 
    node T;
    SLL(u), SLL(v);
    if(in[u] > in[v])
      swap(u, v);
    L = LCA(u, v);
    T.i = i;
    if(L == u || L == v)
      T.l = in[u], T.r = in[v], T.lc = 0;
    else  
      T.l = out[u], T.r = in[v], T.lc = L;
    Q.PB(T);
  }
  
  sort(Q.begin(), Q.end(), cmp);
  
  LL start = 1, end =1 ;
  for(auto X : Q) { 
    LL L = X.l, R = X.r;
    LL I = X.i;
    while(end <= R) add(arr[end++]);  
    while(end > (R+1) )  { remove(arr[end-1]); end--; } 
    while(start < L) remove(arr[start++]); 
    while(start > L ) { add(arr[start-1]); start--; } 
     if(X.lc != 0) 
      {
	add(X.lc);
	query[I] = ans;
	remove(X.lc);
      }
     else
       query[I] = ans;
    //if(I == 13)
    //trace(X.flag, extra(X.lc));
  }
  
  rep(i, 1, m+1)
    printf("%lld\n", query[i]);

  return 0;
}
