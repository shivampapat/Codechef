#include <iostream>
using namespace std;
typedef long long ll;

int main() {
	
	
	ll test;cin>>test;
	
	while(test--){
	    
	    ll arr[5]={0};
	    ll sum=0;
	    for(int i=0;i<5;i++){
	        cin>>arr[i];
	    }
	    for(int i=0;i<5;i++){
	        sum+=arr[i];
	    }
	    
	    ll p =0;
	    cin>>p;
	    
	    if(120 >= (p*sum))
	        cout<<"Yes\n";
	    else
	        cout<<"No\n";
	}
	return 0;
}
