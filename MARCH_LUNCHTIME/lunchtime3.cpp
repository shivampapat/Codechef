#include <bits/stdc++.h>
using namespace std;
typedef  long long ll;

int main() {
	
	ll t;
	cin>>t;
	
	while(t--){
	    ll u,v,a,s;
	    cin>>u>>v>>a>>s;
	    
	    if(u <= v){
			cout<<"Yes\n";
		}
		else{
			u = (u*u)-(2*a*s);
			v  = v*v;
			if(u<=v){
				cout<<"Yes\n";
			}
			else{
				cout<<"No\n";
			}
		}
	    
	}
	
	return 0;
}

