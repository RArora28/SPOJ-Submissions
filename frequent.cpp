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

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }
ll power(ll a,ll b) {
  ll ans = 1;  
  while(b > 0){
    if(b & 1)
      ans = ((ans % mod) *(a % mod)) % mod;
    a=((a % mod)*(a % mod)) % mod;
    b >>= 1;
  }
  return ans;
}

struct node{
  int left, right, ans, left_val, right_val;
};

int arr[100010];
node tree[400010];

node merge(node a, node b) {

  node temp;
  temp.ans = INT_MIN;
  
  if(a.left_val == b.right_val) {
    temp.left = temp.right = temp.ans = a.ans + b.ans;
    temp.left_val = temp.right_val = a.left_val;
  }
  
  else if(a.left_val == b.left_val) {
    temp.left = temp.ans = a.ans + b.left;
    temp.left_val = a.left_val;
    temp.right = b.right;
    temp.right_val = b.right_val;
  }

  else if(a.right_val == b.right_val) {
    temp.right = temp.ans = b.ans + a.right;
    temp.left_val = a.left_val;
    temp.right = b.right;
    temp.right_val = b.right_val;
  }
  
  else {
    temp.left = a.left;
    temp.left_val = a.left_val;
    temp.right = b.right;
    temp.right_val = b.right_val;
    
    if(a.right_val == b.left_val) 
      temp.ans = a.right + b.left;
  }
  
  temp.ans = max(temp.ans, max(a.ans, b.ans));
  
  return temp;  
}

void build(int low, int high, int pos) {
  if(low == high) {
    tree[pos].left = tree[pos].right = tree[pos].ans = 1;
    tree[pos].left_val = tree[pos].right_val = arr[low];
    return;
  }
  
  int mid = (low + high)/2;
  build(low, mid, 2*pos);
  build(mid+1, high, 2*pos+1);
  tree[pos] = merge(tree[2*pos], tree[2*pos+1]);
  return;
}

node query(int low, int high, int l, int r, int pos) {
  if(l <= low  && r >= high) 
    return tree[pos];
  
  else if(l > high || r < low) {
    node temp;
    temp.left = temp.right = temp.ans = temp.left_val = temp.right_val = 0;
    return temp;
  }
  
  int mid = (low + high) / 2;
  return merge(query(low, mid, l, r, 2*pos),query(mid+1, high, l, r, 2*pos + 1));
}

int main() {
  
  int n, i, l, r, q;
  
  while(1) {

    cin>>n;

    if(n == 0)
      break;
    
    node temp;
    
    temp.left = temp.right = temp.ans = temp.left_val = temp.right_val = 0;
    
    rep(i, 1, 4*n + 1)
      tree[i] = temp;
    
    cin>>q;
    
    rep(i, 1, n+1)
      cin>>arr[i];
    
    build(1, n, 1);
    
    rep(i, 1, 4*n+1)
     cout<<tree[i].ans<<endl;
    
    while(q--) {
      cin>>l>>r;
      temp = query(1, n, l, r, 1);
      cout<<temp.ans<<endl;
    }
  }
  
  return 0;
}

