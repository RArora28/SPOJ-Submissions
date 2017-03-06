#include<bits/stdc++.h>
#include<limits.h>
using namespace std;

#define mi 1000000007

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
      ans = ((ans % mi) *(a % mi)) % mi;
    a=((a % mi)*(a % mi)) % mi;
    b >>= 1;
  }
  
  return ans;
}

struct node {
  int sum , left, right, ans;
};

int arr[100000];
node tree[300000];

node merge(node c1, node c2) {
  node p;
  p.sum = c1.sum + c2.sum;
  p.left = max(c1.left, c1.sum + c2.left);
  p.right = max(c2.right, c1.right + c2.sum);
  p.ans = max(c1.right+c2.left, max(c1.ans, c2.ans));
  return p;
}

void build(int arr[], node tree[], int low, int high, int pos) {

  if(low == high) {
    tree[pos].sum  = tree[pos].left  = tree[pos].right = tree[pos].ans = arr[low]; 
    return;
  }
  
  int mid = (low + high) / 2;
  build(arr, tree, low, mid, 2*pos);
  build(arr, tree, mid + 1, high, 2*pos+1);
  tree[pos] = merge(tree[2*pos], tree[2*pos+1]);
  return;
}

node query(int arr[], node tree[], int low, int high, int l, int r, int pos) {
  
  if(l <= low && r >= high)
    return tree[pos];

  else if(r < low || l > high) {
    node temp;
    temp.left = temp.right = temp.sum = temp.ans = INT_MIN/10000;
    return temp;
  }
  
  int mid = (low + high) / 2;
  node temp1 = query(arr, tree, low, mid, l, r, 2*pos);
  node temp2 = query(arr, tree, mid+1, high, l, r, 2*pos+1);
  return merge(temp1, temp2);
}

int main() {
  
  int n, i, m, x, y;
  
  si(n);
  
  rep(i, 1, n+1) 
    si(arr[i]);
  
  build(arr, tree, 1, n, 1);
  
  si(m);
  
  //rep(i, 1, 4*n)
  //cout<<tree[i].ans<<endl;
  
  while(m--) {
    si(x); si(y);
    node temp = query(arr, tree, 1, n, x, y, 1);
    pi(temp.ans);
  }

  return 0;
}

