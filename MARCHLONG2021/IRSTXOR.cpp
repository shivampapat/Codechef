#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	// your code goes here
	
	ll t;
	cin>>t;
	
	while(t--){
	    ll c,a=0,b=0;
	    cin>>c;
	    int d = 1,count=0;
	    while(d<=c){
	        d *=2; 
	        count++;
	    }
	    
//    cout<<d<<"\t"<<count<<"\n";
	    
        int mask=1<<(count-1);
        while(count--){
            int bit = c&mask;
            if(bit != 0){
                 
                int val = (int)pow(2,count);
     //           cout<<"val "<<val<<"\t";
                if(a>b){
                    b+=val;
                }
                else{
                    a+=val;
                }
                   
            }
            else{
                a += (int)pow(2,count);
                b += (int)pow(2,count);
            }
    //        cout<<"a "<<a<<"b "<<b<<"\n";
            mask = mask>>1;
        }
     //   cout<<a<<"\t"<<b<<"\t";
        cout<<a*b<<"\n";

	}
	
	return 0;
}
