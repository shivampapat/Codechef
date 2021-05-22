#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    
    ll t;
    cin>>t;
    
    while(t--){
        double k1,k2,k3,v;
        
        cin>>k1>>k2>>k3>>v;
    
        double  res = k1*k2*k3*v;

        res = 100/res;
    //  cout<<res<<endl;
        res = (int)(res*100 + 0.5);
        res = res/100;
float bolt=9.58;

       
        if( bolt < res){
            cout<<"NO\n";
        }
        else{
            cout<<"YES\n";
        }
            
    }
	return 0;
}