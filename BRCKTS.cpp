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

int seg[4*N], a[N];

int merge(int a, int b)
{
  return a+b;
}

void build(int low, int high, int pos)
{
  if(low == high)
    {
      seg[pos] = a[low];
      return;
    }
  int mid = (low + high) >> 1;
  build(low, mid, 2*pos);
  build(mid+1, high, 2*pos+1);
  seg[pos] = merge(seg[2*pos], seg[2*pos+1]);
  return;
}

int query(int l, int r, int low, int high, int pos)
{
  if ( (l <= low ) && (r >= high) )
    return seg[pos];
  else if( (l > high) || (r < low) )
    return 0; //won't effect the answer;
  int mid = (low + high) >> 1;
  return merge(query(l, r, low, mid, 2*pos), query(l, r, mid+1, high, 2*pos+1));
}

void update(int low, int high, int pos, int ind, int val)
{
  if( (low == high) && (low == ind) )
    {
      seg[pos] = a[ind];
      return;
    }
  else if( (low > ind) || (high < ind) )
    return ;
  int mid = (low + high) >> 1;
  update(low, mid, 2*pos, ind, val);
  update(mid+1, high, 2*pos+1, ind, val);
  seg[pos] = merge(seg[2*pos], seg[2*pos+1]);
}

bool check(int low, int high, int pos)
{
  if(low == high)
    return (seg[pos] >=0);
  return (seg[pos] >= 0) ? check(low, (low+high)>>1, 2*pos) : false;
}

int main() {

  //ios::sync_with_stdio(false);	
  //cin.tie(NULL);

  string str;
  int m, i, n, j;
  int k;
  
  rep(i, 1, 11)
    {
      cin>>n;
      cin>>str;

      rep(j, 0, (int)str.size())
	{
	  if(str[j] == '(')
	    a[j+1] = 1;
	  else
	    a[j+1] = -1;
	}

      build(1, n, 1);

      cin>>m;
      
      cout<<"TEST "<<i<<":"<<endl;

      while(m--)
      	{
      	  cin>>k;
	  
      	  if(k == 0)
      	    {
      	      //trace(seg[1]);
      	      if( (seg[1] == 0) && (check(1, n, 1)) )
      		cout<<"YES"<<endl;
      	      else
      		cout<<"NO"<<endl;
      	    }
      	  else {
      	    if(a[k] == 1)
      	      a[k] = -1;
      	    else
      	      a[k] = 1;
      	    update(1, n, 1, k, a[k]);
      	  }
      	}
    }
  return 0;
}
