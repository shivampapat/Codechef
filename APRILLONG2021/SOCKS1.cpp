#include <iostream>
using namespace std;

typedef long long ll;


int main() {
	
    ll a,b,c;
    cin>>a>>b>>c;
    
    if(a == c || a==b || b==c){
        cout<<"YES";
    }
    else{
        cout<<"NO";
        
    }
	return 0;
}
