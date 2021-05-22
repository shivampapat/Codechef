#include <iostream>
using namespace std;

int main() {
	
	int n,h,x;
	
	cin>>n>>h>>x;
	
	while(n){
	    int i;
	    cin>>i;
	    if(x+i >=h){
	        cout<<"YES";
	        break;
	    }
	    n--;
	}
	if(n==0){
	    cout<<"NO";
	}
	
	
	return 0;
}
