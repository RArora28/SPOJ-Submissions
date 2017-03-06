#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;

int a[N], sq[N], normi[N];

int main() {
  int n, m;
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
    normi[i] = normi[i-1] + a[i];
    sq[i] = sq[i-1] + a[i]*a[i];
  }

  cin >> m;
  while(m--) {
    int u, v;
    cin >> u >> v;
    cout << ((normi[v]-normi[u-1])*(normi[v]-normi[u-1]) - (sq[v] - sq[u-1]))/2 << endl;
  }
  return 0;
}
