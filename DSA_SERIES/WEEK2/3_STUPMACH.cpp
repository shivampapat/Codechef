#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

int main(){

      ll test;
      cin>>test;

      while(test--){

            ll n;
            cin>>n;

            vector<ll> v,indices;
            
              ll temp=0;
            cin>>temp;
            v.push_back(temp);
            indices.push_back(0);

            for(ll i=1;i<n;i++){
                  cin>>temp;
                  if(v.back() > temp){
                        v.push_back(temp);
                        indices.push_back(i);
                  }
            }


            ll last_index=n;
            ll tokens=0;
            ll number=0;

            vector<ll>::reverse_iterator vi= v.rbegin();
            vector<ll>::reverse_iterator it = indices.rbegin();

            number = v[v.size()-1];
            tokens = number*last_index;
            last_index = indices[indices.size()-1];
            vi++;
            it++;

            for(; vi != v.rend() ;vi++,it++){
                        number = *vi - *(vi-1);
                        tokens+= number*last_index;
                         last_index = *it;
            }

            cout<<tokens<<"\n";
      }

      return 0;
}
