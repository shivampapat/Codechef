#include <iostream>
#include<algorithm>
using namespace std;

typedef long long ll;

int main() {

    ll n;
    cin>>n;
    
    ll* arr = new ll[n];
    
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }
    
    sort(arr,arr+n);
    
    ll revenue=arr[0]*(n);
    for(ll i=1;i<n;++i){
        if(arr[i]*(n-i) > revenue)
            revenue = arr[i]*(n-i);           
    }
    cout<<revenue;
    
        
	return 0;
}
