#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){

	ll t;
	cin>>t;
	while(t--){

		ll n; cin>>n;
		map<ll,ll> mp;
			
		mp.insert(pair<ll,ll>(0, 0));
		mp.insert(pair<ll,ll>(1, 20));
		mp.insert(pair<ll,ll>(2, 36));
		mp.insert(pair<ll,ll>(3, 51));
		mp.insert(pair<ll,ll>(4, 60));
		
		if(n<5) {
			cout<<mp.at(n);
		}
		else {
			cout<<((60*(n/4))-(16*(n/4 -1)) + (mp.at(n%4)) - (4*(n%4)));
		}
		cout<<endl;
	}
	return 0;
}