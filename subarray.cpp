#include<iostream>
#include<limits.h>
#include<stdio.h>
using namespace std;

int a[1000010], tree[4000040];

void create(int a[], int tree[], int low, int high, int pos)
{
  if(low == high)
    {
      tree[pos] = a[low];
      return;
    }

  int mid = (low + high) / 2;

  create(a, tree, low, mid, 2 * pos + 1);
  create(a, tree, mid + 1, high, 2 * pos + 2);
  tree[pos] = max(tree[2 * pos + 2], tree[2 * pos + 1]);
  return;
}

int rmq(int tree[], int low, int high, int qlow, int qhigh, int pos)
{
  if(low >= qlow && high <= qhigh)
    return tree[pos];
  
  else if(qhigh < low || qlow > high)
    return INT_MIN;
  
  else
    {
      int mid = (low + high) / 2;
      return max(rmq(tree, low, mid, qlow, qhigh, 2*pos + 1), rmq(tree, mid + 1,high, qlow, qhigh, 2*pos + 2));
    }
}

int main()
{
  int n, k;
  
  cin>>n;

  for(int i = 0; i < n; i++)
    cin>>a[i];

  cin>>k;
  
  for(int i = 0; i < 4*n; i++)
    tree[i] = INT_MIN;
  
  create(a, tree, 0, n-1, 0);

  //for(int i = 0; i < 4*n; i++)
  //cout<<tree[i]<<endl;
  
  for(int i = 0; i + k <= n; i++)
    cout<<rmq(tree, 0, n-1, i, i + k-1, 0)<<" ";

  cout<<endl;
  
  return 0;
}
