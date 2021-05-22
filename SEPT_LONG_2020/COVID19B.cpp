#include<bits/stdc++.h>
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
		
		vector<ll> infected;

		for(ll i=0;i<n;i++){
			ll count=0;
			for(ll j=i+1;j<n;j++){
				if(arr[j] < arr[i]){
					count++;
				}
			}
			
			for(ll j=i-1;j>=0;j--){
				if(arr[j] > arr[i]){
					count++;
				}
			}
			infected.push_back(count+1);
		}		
		
		cout<< *min_element(infected.begin(),infected.end());
		cout<<" " << *max_element(infected.begin(),infected.end());
		cout<<endl;
		
	}
	
	return 0;
}



//
1 2 3 4 || 5 6 7

total =28
half = 14
Go from right to left find 
RightSum >=half

RSUm = 18
M = 7-3 = 4

Diff = Rsum - half = 18-14 = 4
   


   
   
   
   






















