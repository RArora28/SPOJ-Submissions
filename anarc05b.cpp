#include <iostream>
using namespace std;

int main()
{

  while(1)
    {
      int n1, n2;
      
      cin>>n1;
      int a[n1+1];
      
      if(n1 == 0)
	break;

      for(int i = 0; i < n1; i++)
	cin>>a[i];
      
      cin>>n2;
      int b[n2+1];
      
      for(int i = 0; i < n2; i++)
	cin>>b[i];
      
      int i = 0, j = 0, s1 = 0, s2 = 0, s = 0;

      while(i < n1 && j < n2)
	{
	  if(a[i] > b[j])
	    {
	      s2 += b[j];
	      j++;
	    }
	  
	  else if(a[i] < b[j])
	    {
	       s1 += a[i];
	       i++;
	    }
	  else
	    {
	      if(s1 > s2)
		  s += s1 + a[i];
	      else 
		  s += s2 + b[j];
	     
	      if(i < n1 - 1)
		  i++;
	      
    	      if(j < n2 - 1)
		  j++;
	      s1 = 0;
	      s2 = 0;
	    }
	  cout<<s<<endl;
	 
	}
       cout<<s<<endl;
    }
  
  return 0;
}
