#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;

int dp[6102][6102];

int f(char str1[], int i, char str2[], int j)
{
  if(i == -1 || j == -1)
    return 0;
  
  else if(dp[i][j] != -1)
    return dp[i][j];
  
  else if(str1[i] == str2[j]) 
    return dp[i][j] = 1 + f(str1,i-1, str2, j-1);
      
  else
    return dp[i][j] = max( f(str1,i, str2, j-1), f(str1,i-1, str2, j));
}

int main()
{
  char str1[6102], str2[6102];
  int len , t ,i , j;

  cin>>t;
  
  while(t--)
    {
      cin>>str1;
      
      len = strlen(str1)-1;

      for(i = 0; i <= len; i++)
	{
	  for(j = 0; j <= len; j++)
	    dp[i][j] = -1;
	}

      for(i = len; i >= 0; i--)
	  str2[i] = str1[len-i];
	
      cout<<len + 1- f(str1,len,str2,len)<<endl;     
    }
  return 0;
}
