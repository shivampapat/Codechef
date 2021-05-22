#include <bits/stdc++.h>
using namespace std;
typedef  long long ll;

int main() {
	
	ll te;
	cin>>te;
	
	while(te--){
	    ll x,r,m;
	    cin>>x>>r>>m;
	    m = m*60;
	    r = r*60;
	    
	    ll t=(r/x)*x;
	    ll rest = (r/x-1)*x;
	    t += rest;
	    
	    ll remains = (r%x)*2;
	    t += remains;
		
		if(t<=m){
		    cout<<"YES";
		}
		else{
		    cout<<"NO";
		}
		cout<<endl;
	}
	
	return 0;
}

