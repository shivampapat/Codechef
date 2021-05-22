#include<iostream>
using namespace std;

typedef long long ll;

ll ZeroesTrail(ll n){
      ll counter=0;
      ll denominator =5;

      while((n/denominator) != 0){
            counter+= (n/denominator);
            denominator *= 5;
      }
      return counter;
}

int main(){

      ll test;
      cin>>test;
      while(test--){

            ll n;
            cin>>n;
            cout<<ZeroesTrail(n)<<endl;
      }

      return 0;
}