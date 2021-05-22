    #include <iostream>
    using namespace std;
    
    typedef long long ll;
    
    int main() {
    	// your code goes here
    	ll n;
    	cin>>n;
    	
    	if(n<=10){
    	    cout<<n;
    	}
    	else{
    	    
    	    if(n%10 == 0){
    	        cout<<10;
    	    }
    	    else if(n%9 == 0){
    	        cout<<9	;
    	    }
    	    else if(n%8 == 0){
    	        cout<<8;
    	    }
    	    else if(n%7 == 0){
    	        cout<<7;
    	    }
    	    else if(n%6 == 0){
    	        cout<<6;
    	    }
    	    else if(n%5 == 0){
    	        cout<<5;
    	    }else 
    	        cout<<1;
    	    
    	   
    	}
    	
    	return 0;
    }

