#include<iostream>
#include<map>
#include<vector>
using namespace std;

int main(){

      int test=0;
      cin>>test;

      while(test--){

            string str;
            cin>>str;
            cout<<str<<endl;

            map<char,vector<int> > m;

            for(int i=0;i<str.length();i++){
                        m[str[i]].push_back(i);
            }
            
            map<char,vector<int>>:: iterator it;
            vector<int>:: iterator vit;

            for(it=m.begin();it!=m.end();it++){
                  cout<<(*it)->first<<" "<<(*it)->second;
            }

      }

      return 0;
}