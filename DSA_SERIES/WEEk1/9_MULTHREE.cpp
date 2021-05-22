#include<iostream>
using namespace std;
typedef long long ll;

int main(){
      ll tester;cin>>tester;
      while(tester--){
            ll k,d0,d1;
            cin>>k>>d0>>d1;
            ll sum=d0+d1;
            if((sum==1 || sum%10 == 0)|| (sum%10 == 5)){
                  cout<<"NO\n";
                  continue;
            }
            sum+=(sum%10);
            if(k>2){
                  ll quotient = (k-3)/4;
                  sum+=(quotient*20);
                  for(int i=0;i<(k-3)%4;i++){
                        sum+=sum%10;
                  }
            }
            if(sum%3==0)
                  cout<<"YES\n";
            else
                  cout<<"NO\n";
      }
      return 0;
}