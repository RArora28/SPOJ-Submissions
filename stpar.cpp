#include<iostream>
#include<stack>
#include<algorithm>
#include<string.h>
#include<limits.h>
using namespace std;

int main()
{
  stack<int>s
  int t;
  char str[450], str2[450];

  while(1)
    {
      cin>>n;

      if(n == 0)
	break;

      min = INT_MAX;
      
      for(int i = 1; i <= n; i++)
	{
	  cin>>a[i];
	  
	  if(a[i] < min)
	    {
	      min = a[i];
	      min_index = i;
	}
      
      for(int i = n; i >= i; i--)
	{
	  if(a[i] > a[i-1])
	  {
	    s.push(a[i]);
	    a[i] = 0;
	  }
	}
      
    }
  return 0;
}
