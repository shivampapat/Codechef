#include<iostream>
#include<math.h>
using namespace std;
typedef long long ll;

int main(){

      ll n,q;cin>>n>>q;

      ll arr[n];
      for(ll i=0;i<n;i++){
            cin>>arr[i];
      }

      sort(arr,arr+n);

      while(q--){

            ll x;cin>>x;
            ll min=0;
            ll max=0;
            ll counter=0;
            int xbits[32]={0};

            for(int i=31;i>=0;;i--){
                        if((x>>i)&1 == 1){
                             max+= (pow(2,i));
                        }
            }

            for(ll i=0;i<n && arr[i] <=max;i++){
                  counter++;
            }
            cout<<counter<<endl;


      }
      

      return 0;
}