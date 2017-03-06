#include<bits/stdc++.h>
#include<limits.h>
using namespace std;

#define mod 1000000007
#define si(x) scanf("%d", &x)
#define sll(x) scanf("%lld", &x)
#define pi(x) printf("%d\n", x)
#define pll(x) printf("%lld\n", x)
#define LL long long int
#define ii pair<int, int>
#define vii vector<pair<int, int> >
#define vi vector<int>
#define adjList vector<vector<int> >
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define rep(i, z, q) for(i = z; i < q; i++)
#define rev(i, z, q) for(i = z; i > q; i--)
#define INF 1061109567

#define gc getchar_unlocked

int read_int() {
  char c = gc();
  while(c<'0' || c>'9') c = gc();
  int ret = 0;
  while(c>='0' && c<='9') {
    ret = 10 * ret + c - 48;
    c = gc();
  }
  return ret;
}

int d1[510], d2[510], A[510];
bool flag[510];
int taken[510];
int i, n, k, m, s, t, x, y, w;

//dijkstra's n^2

inline int min_dis(int arr[], bool fl[]) {

  int i, Min = INF, ans = -1;
  
  rep(i, 0, n) 
    if(!fl[i] && arr[i] < Min) {
      Min = arr[i];
      ans = i;
    }
  
  //cout<<ans<<endl;
  return ans;
  
}

inline void shortest_path(int dis[], int source, vector<vii> adj) {
  
  //priority_queue <ii, vii, greater<ii > > p;
  
  int i, u;
  bool R[n+1];
  
  rep(i, 0, n)
    R[i] = false;
  
  dis[source] = 0;
  
  rep(i, 0, n-1) {
    
    u = min_dis(dis, R);

    if(u == -1)
      continue;
    
    else {
      
      R[u] = true;
      
      for(vii::iterator it = adj[u].begin(); it != adj[u].end(); it++) 
	if( R[(*it).se ] == false && ( dis[u] + (*it).fi < dis[(*it).se])) 
	  dis[(*it).se] = dis[u] + (*it).fi;
    }
  }
  
  return;
}


inline void shortest_path1(int dis[], int source, vector<vii> adj) {
  
  //priority_queue <ii, vii, greater<ii > > p;
  
  int i, u;
  bool R[n+1];
  
  rep(i, 0, n)
    R[i] = false;
  
  dis[source] = 0;
  
  rep(i, 0, n-1) {
    
    u = min_dis(dis, R);
    
    if(u == -1)
      continue;
    
    else {
      
      R[u] = true;
      
      for(vii::iterator it = adj[u].begin(); it != adj[u].end(); it++) 
	if((R[(*it).se ] == false && ( dis[u] + (*it).fi < dis[(*it).se])) && !(flag[u] && flag[(*it).se])) 
	  dis[(*it).se] = dis[u] + (*it).fi;
    }
  }
  
  return;
}

// inline void dfs(int v, vector<vii> adj) {

//   taken[v] = 1;
  
//   for(vii::iterator it = adj[v].begin(); it != adj[v].end(); it++) 
//     if(!taken[(*it).se] && !(flag[v] && flag[(*it).se])) { 
//       A[(*it).se] = A[v] + (*it).fi;
//       dfs((*it).se, adj);
//     }
  
//   return;
// }


int main() {

  while(1) {

    vector<vii> adj1, adj2;

    n = read_int();
    m = read_int();
    
    if(n == 0 && m == 0)
      return 0;

    s = read_int();
    t = read_int();
   
    rep(i, 0, n) {
      flag[i] = false;
      d1[i] = d2[i] = INF;
      A[i] = INF;
      taken[i] = 0;
    }
    
    adj1.resize(n);
    adj2.resize(n);
    
    rep(i, 1, m+1) {
      
      x = read_int();
      y = read_int();
      w = read_int();
    
      adj1[x].pb(ii(w, y));
      adj2[y].pb(ii(w, x));
    }
    
    A[s] = 0;
    
    shortest_path(d1, s, adj1);

    int ans = d1[t];

    //  cout<<ans<<endl;
    
    shortest_path(d2, t, adj2);
    
    //cout<<d2[s]<<endl;
    
    rep(i, 0, n) 
      if(d1[i] + d2[i] == ans)
	flag[i] = true;
    
    shortest_path1(A, s, adj1);

    if(A[t] == INF)
      A[t] = -1;
    
    pi(A[t]);
  }

return 0;
}


