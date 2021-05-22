#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;

int main(){
	
	int test;
	cin>>test;
	
	while(test--){
		ll n;
		cin>>n;
		
		set<ll> s;
		
		for(ll i=0;i<n;++i){
			ll temp=0;
			cin>>temp;
			s.insert(temp);
		}
		
		set<ll> :: iterator it;
		it = s.begin();
		if((*it) != 0)
			cout<<s.size()<<"\n";
		else
			cout<<s.size()-1<<"\n";
	}
	
	return 0;
}
