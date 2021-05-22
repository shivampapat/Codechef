#include<iostream>
#include<map>
#include<math.h>
using namespace std;
typedef long long ll;

ll FindFactors(ll factors){
      ll temp = factors;

      ll j=0;
      ll i=2;
      while(temp %2 == 0){
                  j++;
            temp/=2;
      }
      
      for(i=3;i<=sqrt(temp);i+=2){
            while(temp % i ==0){
                  j++;
                  temp = temp/i;
            }
      }
      if(temp >2)
            j++;

      return j;
}


int IsNumber(ll factors, ll prime_factors){
      
      ll ans = FindFactors(factors);
      if(ans >= prime_factors)
            return 1;
      return 0;      
}



int main(){

      int test;
      cin>>test;

      while(test--){

            ll factors,prime_factors;
            cin>>factors>>prime_factors;

            cout<<IsNumber(factors,prime_factors); 
      }
      return 0;
}