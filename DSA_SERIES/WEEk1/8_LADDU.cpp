#include<iostream>
using namespace std;
typedef long long ll;

int main(){
      ll tester;cin>>tester;
      while(tester--){
            ll G;
            string origin;
            cin>>G;
            cin>>origin;
            ll laddus=0;
            while(G--){
                  string s;cin>>s;
                  if(s=="CONTEST_WON"){
                        int rank=0;cin>>rank;
                        laddus += 300 + (rank <20 ? 20-rank : 0);
                  }
                  else if(s=="TOP_CONTRIBUTOR")
                        laddus+=300;
                  else if(s=="BUG_FOUND"){
                        int x=0;cin>>x;
                        laddus+=x;
                  }      
                  else if(s=="CONTEST_HOSTED")
                        laddus+=50;      
            }

            if(origin=="INDIAN")
                  cout<<(laddus/200);
            else
                  cout<<(laddus/400);
            cout<<"\n";
      }
      return 0;
}