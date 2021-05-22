#include <iostream>
using namespace std;
typedef long long ll;

int main() {

    ll test;
    cin>>test;
    
    while(test--){
    
        string str;
        cin>>str;
        
        ll counter=0,bracket_counter=0;
        ll max=0;
        
        for(ll i=0;i<str.length();i++){
            if(str[i] == '<'){
                counter++;
            }
            else{
                counter--;
            }
            
            if(counter <0){
                break;
            } 
            if(counter==0)
            max = i+1;
        }

        cout<<max<<"\n";
        
    }
	return 0;
}
