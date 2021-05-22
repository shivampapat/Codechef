#include <bits/stdc++.h>
using namespace std;
typedef  long long ll;

int main() {
	
	ll t;
	cin>>t;
	
	while(t--){
	    ll n,x;
	    cin>>n>>x;
	    
	    vector< pair <int,int> > vect;
	    for(ll i=0;i<n;i++){
	        ll s,r;
	        cin>>s>>r;
	        vect.push_back( make_pair(r,s) );
        }
    
    
        sort(vect.rbegin(), vect.rend());   
    
    	
    for (int i=0; i<n; i++)
    {
        if(vect[i].second <=x)
		{
			cout<<vect[i].first<<endl;
			break;
		}
			
    }
    
	}
	
	return 0;
}

