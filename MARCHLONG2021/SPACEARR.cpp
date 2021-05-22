#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	// your code goes here
	ll t;
	cin>>t;
	
	while(t--){
	    
	    ll n;
	    cin>>n;
	    
	    ll* arr = new ll[n];;
	    
	    for(ll i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    
	    sort(arr,arr+n);
	    
	   //ll sum= (n*(n+1))/2;
	   ll sum =0,flag=0;
	    for(ll i=1;i<=n;i++){
	        //sum -=arr[i];
	       
	        if(arr[i-1] > i){
	            flag = 1;
	            break;
	        }
	       sum = sum + (i - arr[i-1]);
	    }
	    
	    if(flag == 1){
	        cout<<"Second"<<"\n";
	  
	    }
	    else{
	            if(sum %2==0){
	                cout<<"Second"<<"\n";
	         }
	                else{
	        cout<<"First"<<"\n";    
	    }
	    
	    }
	    
	}
	return 0;
}