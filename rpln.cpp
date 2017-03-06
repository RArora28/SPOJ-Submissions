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
  tree[pos] = min(tree[2 * pos + 2], tree[2 * pos + 1]);
  return;
}

int rmq(int tree[], int low, int high, int qlow, int qhigh, int pos)
{
  if(low >= qlow && high <= qhigh)
    return tree[pos];
  
  else if(qhigh < low || qlow > high)
    return INT_MAX;
  
  else
    {
      int mid = (low + high) / 2;
      return min(rmq(tree, low, mid, qlow, qhigh, 2*pos + 1), rmq(tree, mid + 1,high, qlow, qhigh, 2*pos + 2));
    }
}

int main()
{
  int n, k, t, l, r, q;

  scanf("%d", &t);

  while(t--)
    {
  
      scanf("%d %d", &n, &q);

      for(int i = 0; i < n; i++)
	scanf("%d", &a[i]);

      for(int i = 0; i < 4*n; i++)
	tree[i] = INT_MAX;
  
      create(a, tree, 0, n-1, 0);
  
      while(q--)
	{
	  scanf("%d %d", &l, &r);
	  printf("\n%d", rmq(tree, 0, n-1, l-1, r-1, 0));
	}
  
    }
  return 0;
}

