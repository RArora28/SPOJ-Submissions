#include<stdio.h>
#include<string.h>

long long int dp[10000], a[10000];

long long int f(long long int i)
{ 
  if(i <= 0)
    return 1;
  
  else if(dp[i] != -1)
    return dp[i];
  
  int num;


  dp[i] = 0;

  
  num = (a[i-1]*10) + a[i];
  
  if(num <= 26 && num >= 10)
     dp[i] += f(i-2);
  
  if(a[i] != 0)
     dp[i] += f(i-1);

  return dp[i];
}


int main()
{
  char str[10000];
  long long int len;
  
  while(1)
    {
      scanf("%s", str);
      len = strlen(str);
      
      if(str[0] == '0' && len == 1)
	break;
      
      for(int i = 0; i < len; i++)
	{
	  a[i] = str[i] - '0';
	  dp[i] = -1;
	}
      
      printf("%lld\n", f(len-1));
    }
  return 0;
}
