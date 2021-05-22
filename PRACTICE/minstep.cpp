#include<iostream>
#include<unordered_set>
using namespace std;
typedef long long ll;

int main(){

      ll n,test;
      cin>>n>>test;

      ll arr[n+1];
      unordered_set<ll> s;

      for(ll i=1;i<n+1;i++){
            arr[i]=i;
            s.insert(i);
      }
      ll counter=0;
      counter = s.size();

      while(test--){

            ll a,b;
            cin>>a>>b;
            

            if(arr[b] != arr[a]){
                  arr[b] = arr[a];
                  counter--;
            }

            cout<<counter<<endl;
      }


      return 0;
}