/* Rishabh Arora
   IIIT-Hyderabad */
 
#include <bits/stdc++.h>
using namespace std;
 
typedef pair<int,int> II;
typedef vector<int> VI;
typedef vector<II> VII;
typedef long long int LL;
typedef unsigned long long int ULL;
 
#define MAXSIZE 400005
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
  int lc, i, l, r;
  bool flag;
};

int ans = 0, tim = 1, w[MAXSIZE], W[MAXSIZE], arr[2*MAXSIZE], in[MAXSIZE], out[MAXSIZE], L[MAXSIZE], par[MAXSIZE], P[MAXSIZE][20], cnt[MAXSIZE], vis[MAXSIZE], query[MAXSIZE];
bool taken[MAXSIZE];
vector<vector<int> > adj;
vector<vector<node> > Q;
map<int, int> M;
 
inline bool cmp(node A, node B) { 
  return A.r < B.r;  
}
 
inline int read_int() {
  char c;
  while (c = getchar(), c < '0' || c > '9');
  int t = c - '0';
  while (c = getchar(), c >= '0' && c <= '9')	t = t * 10 + c - '0';
  return t;
}
 
void dfs(int v) { 
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

inline void LCApre(int n) { 
  int i, j;
  rep(i, 1, n+1)
    P[i][0] = par[i];
  rep(i, 1, n+1)
    for(j = 1; 1 << j <= n; j++)
      if(P[i][j-1] != -1)
	P[i][j] = P[P[i][j-1]][j-1];
  return; 
}

inline int LCA(int a, int b) { 
  int i, log;
  if(L[a] < L[b])
    swap(a, b);
  for(log = 1; 1 << log <= L[a]; log++);
  log--;
  rev(i, log, -1)
    if(L[a] - (1 << i) >= L[b])
      a = P[a][i];
  if(a == b)
    return a;
  rev(i, log, -1)
    if(P[a][i] != -1 && P[a][i] != P[b][i])
      a = P[a][i], b = P[b][i];
  return par[a];
}

inline void add(int x) { 
  vis[x] ^= 1;
  int temp = w[x];
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

inline void remove(int x) {
  vis[x] ^= 1;
  int temp = w[x];
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
 
int extra(int x) { 
  if(cnt[M[W[x]]] == 0)
    return 1;
  return 0;
}
 
int main() {
  
  int n, m;
  int i, j;
  int u, v;
  n = read_int();
  m = read_int();
  adj.resize(n+1);
 
  rep(i, 1, n+1) {
    W[i] = read_int();
    M[W[i]] = 0;
  }
 
  int ind = 1;
  for(auto &it : M) 
    M[it.F] = ind++;
  
  rep(i, 1, n+1) 
    w[i] = M[W[i]];

  rep(i, 1, n+1)
    rep(j, 0, 17)
    P[i][j] = -1;
 
  rep(i, 1, n) {
    u = read_int();
    v = read_int();
    adj[u].PB(v);
    adj[v].PB(u);
  }
  
  L[1] = 0, par[1] = -1;
  dfs(1);
  LCApre(n);
  int sq = sqrt(2*n);
  int sz = 2*n / sq + 2;
  Q.resize(sz + 2);
  
  rep(i, 1, m+1) { 
    node T;
    u = read_int(), v = read_int();
    if(in[u] > in[v])
      swap(u, v);
    int L = LCA(u, v);
    //trace(u, v, L);
    T.i = i, T.lc = L;
    if(L == u)
      T.l = in[u], T.r = in[v], T.flag = false;
    else  
      T.l = out[u], T.r = in[v], T.flag = true;

    if(T.l % sq == 0)  
      Q[T.l/sq].PB(T);
    else 
      Q[T.l/sq + 1].PB(T);
  }

  for(auto &it : Q)
    sort(it.begin(), it.end(), cmp);
  
  i = 0;
  // for(auto it : Q) {
  //   cout<<i<<"->";
  //   i++;
  //   for(auto A : it)
  //     cout<<A.l<<"-"<<A.r<<" ";
  
  //   cout<<endl;
  // }
  
  int f = -1;
  for(auto it : Q) { 
    int k;
    if(it.size() != 0)
      rep(k, 0, n+1)
	vis[k] = 0, cnt[k] = 0;
    ans = 0;
    int start = sq * f;
    int end = start;
    f++;
    //trace(start);
    for(auto X : it) { 
      int L = X.l, R = X.r;
      bool flag = X.flag;
      int I = X.i;
      //trace(start);
      while(end <= R) { if(end == 0) { end++; continue; } add(arr[end++]); } 
      //trace(start);
      while(start < L) { if(start == 0) { start++; continue; } remove(arr[start++]); }
      //trace(start);
      while(start > L)  { cout<<"hello"<<endl; if(start == 1) { start--; continue; } add(arr[start-1]); start--; }
      query[I] = ans;
      if(flag) 
    	query[I] += extra(X.lc);
    }
  }
  
  rep(i, 1, m+1)
    printf("%d\n", query[i]);
  return 0;
}
