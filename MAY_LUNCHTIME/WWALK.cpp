#include <iostream>
using namespace std;
typedef long long ll;

int main() {
	
	
	ll test;cin>>test;
	
	while(test--){
	    
          ll n =0;cin>>n;
	    ll arr[n];
          ll brr[n];
	    ll sum_A=0, sum_B=0;
          ll total=0;
	    for(ll i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    
          for(ll i=0;i<n;i++){
	        cin>>brr[i];
	    }
          for(ll i=0;i<n;i++){

                if(sum_A == sum_B){
                      if(arr[i]== brr[i])
                        total+=arr[i];
                }
	        sum_A+=arr[i];
              sum_B+=brr[i];
	    }

	        cout<<total<<"\n";
	}
	return 0;
}
