#include <iostream>
using namespace std;

int main() {
	// your code goes here
	
	long n;
	cin>>n;
	
	while(n--){
	    string str;
	    cin>>str;
	    
	    int counter=0;
	    
	    for(int i = 0; i<str.length(); i++) {
            if(str.at(i)== '1'){
                counter++;
                while(i<str.length() && str.at(i)== '1'){
                    i++;
                }
            }     
        }
        cout<<counter<<endl;
	}
	return 0;
}
