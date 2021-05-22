#include<iostream>
using namespace std;

typedef long long ll;

int main(){
	
	ll test;
	cin>>test;
	
	while(test--){
		ll n;
		cin>>n;
		
		ll* arr = new ll[n];
		
		for(ll i=0;i<n;i++){
			cin>>arr[i];
		}
		
		ll min =arr[0],max=arr[0];
		
		for(ll i=1;i<n;i++){
			if(min >arr[i])
				min = arr[i];
			
			if(max < arr[i])
				max = arr[i];
		}
		cout<<2*(max-min)<<"\n";
	}
	
	
	
	return 0;
}
