/* Rishabh Arora
   IIIT-Hyderabad */

#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> II;
typedef vector<int> VI;
typedef vector<II> VII;
typedef long long int LL;
typedef unsigned long long int ULL;

#define rep(i, a, b) for(i = a; i < b; i++)
#define rev(i, a, b) for(i = a; i > b; i--)
#define INF INT_MAX
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SET(a,b) memset(a, b, sizeof(a))

//debugging statements
#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

const int N = 1e5+10;
const int mod = 1e9+7;

struct node {
	node *link[10];
	bool end;
	node () {
		for(int i = 0; i < 10; i++) {
			link[i] = NULL;
		}
		end = false;
	}
};

bool ans;

void insert(node *currNode, string s, int level) {
	if(level == (int)s.size()) {
    currNode->end = true;
    for(int i = 0; i < 10; i++) {
      if(currNode->link[i]) {
        ans = false;
      }
    }
    return;
  }

  if(!currNode->link[s[level]-'0']) {
    currNode->link[s[level]-'0'] = new node;
	}
  if(currNode->end) {
    ans = false;
  }
  return insert(currNode->link[s[level]-'0'], s, level+1);
}

int main() {

  ios::sync_with_stdio(false);	
  cin.tie(NULL);   
  int t; cin >> t;
  while(t--) {	
    node *trie = new node;
    ans = true;
  	int n; cin >> n;
  	while(n--) {
  		string s; cin >> s;
  		insert(trie, s, 0);
  	}
  	if(ans) {
  		cout << "YES" << endl;
  	}
  	else {
  		cout << "NO" << endl;
  	}
  }
  return 0;
}
