#include<iostream>
using namespace std;
typedef long long ll;

int main(){
      ll tester;cin>>tester;
      while(tester--){
            ll G;
            cin>>G;
            while(G--){
                  ll face_initial,rounds,face_wanted;
                  cin>>face_initial>>rounds>>face_wanted;
                  if(rounds %2==0)
                        cout<<rounds/2;
                  else{
                        if(face_wanted ==face_initial)
                              cout<<(rounds/2);
                        else
                              cout<<(rounds/2)+1;
                  }
                  cout<<"\n";
            }
      }
      return 0;
}