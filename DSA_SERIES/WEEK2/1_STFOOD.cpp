 #include<iostream>
 using namespace std;
 typedef long long ll;

 int main(){

       ll tester;cin>>tester;

       while(tester--){
             ll n;
             cin>>n;

            ll max_profit = 0;
             while(n--){

                   ll stores,people,price_each;
                   cin>>stores>>people>>price_each;

                  ll current_profit = 0;
                  current_profit = (people/(stores+1))*price_each;

                  if(current_profit > max_profit)
                        max_profit = current_profit; 
             }
             cout<<max profit<<"\n";
       }

       return 0;
 }