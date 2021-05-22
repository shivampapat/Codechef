#include <bits/stdc++.h>
using namespace std;
typedef  long long ll;

int main() {
	
	ll t;
	cin>>t;
	
	while(t--){
	    ll n;
	    cin>>n;
	    
	    vector<ll> v;
	   
		for(ll i=0;i<n;i++){
			ll h;
			cin>>h;
			v.push_back(h);
		}
		
		ll i=0;j=0;
		for(i=1;i<n;i++){
			
			
			
			
			
			
			
			
			
			
			
			if(v[i] != v[i-1]){
				for(ll k=j;k<i;k++){
					cout<<(i-j-1)<<" ";
				}
				j = i;
			}
		}
		
		if(i == n && j <n-1){
			cout<<(i-j-1);
		}
		else{
			cout<<"0";
		}
		cout<<endl;
	}
	
	return 0;
}

