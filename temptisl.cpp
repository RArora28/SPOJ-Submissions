#include<bits/stdc++.h>
using namespace std;

#define LL long long int

LL dp[100][100];

LL rec(int n, int k) {

  if(k == 0)
    return 1;
  
  else if(dp[n][k] != -1)
    return dp[n][k];

  else {
    if(n >= 2 && n <= m-1) 
      return dp[n][k] = rec(n+1, k-1) + rec(n-1, k-1);
    else if(n == 1)
      return dp[n][k] = rec(n+1, k-1) + rec(m, k-1);
    else
      return dp[n][k] = rec(n-1, k-1) + rec(1, k-1);
  }
}

int main() {

  memset(dp, -1, sizeof(dp));
  
  return 0;
}
