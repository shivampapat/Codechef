#include <iostream>
using namespace std;

int reverse(int n){
    
    int result=0;
    while(n!=0){
        result*=10;
        result+=n%10;
        n=n/10;
    }
    return result;
}


int main() {
	
	int test;
	cin>>test;
	
	while(test--){
	    int n;
	    cin>>n;
	    cout<<reverse(n)<<endl;
	}
	
	return 0;
}
