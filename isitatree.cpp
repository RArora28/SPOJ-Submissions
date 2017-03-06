#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

int flag[10005], parent[10005];

int main()
{
  int n, m, temp_flag = 1, u, v;
  cin>>n>>m;
  vector<vector<int> >g(n+1);

  for(int i = 0; i < m; i++)
    {
      cin>>u>>v;
      g[u].push_back(v);
      g[v].push_back(u);
    }

  stack<int>s;
  s.push(u);
  flag[u] = 1;
  parent[u] = 0;
  
  while(!s.empty())
    {
      int temp = s.top();
      s.pop();
      
      for(vector<int>::iterator it = g[temp].begin(); it != g[temp].end(); it++)
	{
	  
	  if(flag[*it] == 0)
	    {
	      flag[*it] = 1;
	      s.push(*it);
	      parent[*it] = temp;
	    }
	  
	  else if(flag[*it] == 1 && parent[temp] != *it)
	    {
	      temp_flag = 0;
	      break;
	    }
	  
	}
      if(temp_flag == 0)
	break;
    }
  
  if(temp_flag == 0)
    cout<<"NO"<<endl;
  else
    cout<<"YES"<<endl;
  return 0;
}
