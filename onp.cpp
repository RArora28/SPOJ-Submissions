#include<iostream>
#include<stack>
#include<algorithm>
#include<string.h>
using namespace std;

int main()
{
  stack<char>a, b;
  int t;
  char str[450], str2[450];
  
  cin>>t;

  while(t--)
    {
      cin>>str;

      int len = strlen(str);
	
      for(int i = 0; i < len; i++)
	{ 
	  if(str[i] == '+'|| str[i] == '-' || str[i] == '^' || str[i] == '/' || str[i] == '*')
	    b.push(str[i]);
	  
	  else if(str[i] == ')')
	    {
	      a.push(b.top());
	      b.pop();
	    }

	  else if(str[i] != '(')
	    a.push(str[i]);
	}

      int index = 0;
      
      while(!a.empty())
	{
	  str2[index++] = a.top();
	  a.pop();
	}

      for(int i = index-1; i >= 0; i--)
	cout<<str2[i];

      cout<<endl;
    }
  return 0;
}
