#include <bits/stdc++.h>
using namespace std;
typedef  long long ll;

int main() {
	
	ll t;
	cin>>t;
	
	while(t--){
	    ll a,y,x;
	    cin>>a>>y>>x;
	    
	    if(a>=y){
	    	cout<<y*x<<"\n";
		}
		else{
			cout<<(1+a*x)<<"\n";
		}
	}
	
	return 0;
}

