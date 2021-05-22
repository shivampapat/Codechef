#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){

      ll t;
      cin>>t;

      while(t--){
            ll n,e,h,a,b,c;
            cin>>n>>e>>h>>a>>b>>c;

            ll max_production = min(e, h) + (e > h ? (e - h) / 2 : (h - e) / 3);

            if(max_production <n){
                  cout << "-1\n";
                  continue;
            }

            map<char, int> item_factor;
            item_factor.insert({'a', 2});
            item_factor.insert({'b', 3});
            item_factor.insert({'c', 1});

            multimap<int,char> soln;
            soln.insert(make_pair(a,'a'));
            soln.insert(make_pair(b,'b'));
            soln.insert(make_pair(c,'c'));

            multimap <int, char> :: iterator it;
          
            for(it = soln.begin(); it != soln.end();it++){
                  cout<<it->first<<" "<<it->second<<endl;
            }
      }

      return 0;

}