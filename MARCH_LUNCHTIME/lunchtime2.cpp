#include <bits/stdc++.h>
using namespace std;
typedef  long long ll;

int main() {
	
	ll t;
	cin>>t;
	
	while(t--){
	    ll n;
	    cin>>n;
	    
	    vector<int> vect;
	    int flag = 0,is_two=0;
	    for(ll i=0;i<n;i++){
	        ll s;
	        cin>>s;
	        if(s%2 !=0){
				flag++;
			}
			if(s == 2){
				is_two = 1;
			}
	        vect.push_back(s);
        }
        
        ll vec_sum = accumulate(vect.begin(), vect.end(), 0);
        
        if(vec_sum %2 == 0){
        	cout<<"0\n";
		}
		else{
			if(flag == n){
				cout<<"-1\n";
			}
			else if(is_two !=0){
					cout<<"1\n";
			}
			else{
					cout<<"-1\n";
			}
			
		}
	}
	
	return 0;
}

