#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){

      ll t;
      cin >> t;

      while(t--){

            ll n;
            cin>>n;
            n--;        
            ll res = 1;
            ll base = 2;
            base  = base % 1000000007; 

            while (n > 0)
            {
                  if (n & 1)
                      res = (res * base) % 1000000007;

                  n = n >> 1; // y = y/2
                  base = (base * base) % 1000000007;
            }
            cout << res%(1000000000+7)<<endl;
      }

      return 0;
}