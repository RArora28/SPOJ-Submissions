#include<bits/stdc++.h>
#include<limits.h>
using namespace std;

#define mod 1000000007
#define si(x) scanf("%d", &x)
#define sll(x) scanf("%lld", &x)
#define pi(x) printf("%d\n", x)
#define pll(x) printf("%lld\n", x)
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<pair<int, int> >
#define adjList vector<vector<int> >
#define ll long long int
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define rep(i, z, q) for(i = z; i < q; i++)
#define rev(i, z, q) for(i = z; i > q; i--)

bool flag = false, taken[3000];
int color[3000];
adjList adj;

void dfs(int v) {
  
  taken[v] = true;

  if(flag)
    return;

  for(auto it : adj[v]) {
    if(!taken[it]) {
      color[it] = 1 - color[v];
      dfs(it);
    }
    
    else if(taken[it] && color[it] == color[v]) {
      flag = true;
      return;
    }
  }

  return ;      
}

int main() {

  int i;
  int T, ind = 1;
  
  si(T);

  while(T--) {
    
    flag = false;

    int N;
    int M;

    si(N);

    rep(i, 1, N+1) {
      taken[i] = false;
      color[i] = -1;
    }

    si(M);

    adj.resize(N+1);
    
    int u, v;
    
    while(M--) { 
      si(u);
      si(v);
      
      adj[v].pb(u);
      adj[u].pb(v);
    }
    
    rep(i, 1, N+1) 
      if(!taken[i]) {
	color[i] = 0;
	dfs(i);
      }
    
    cout<<"Scenario #"<<ind<<":"<<endl;
    
    if(flag) 
      cout<<"Suspicious bugs found!"<<endl;
    else 
      cout<<"No suspicious bugs found!"<<endl;
    
    adj.resize(0);
    ind++;
  }

  return 0;
}

