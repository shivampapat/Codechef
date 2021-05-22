#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
      ll testcase;
      cin>>testcase;

      while(testcase--)
      {
            ll rows;
            cin>>rows;
            vector< vector<ll> > v(rows);

            for(ll i=0;i<rows;i++)
            {
                  ll cols;
                  cin>>cols;
                  
                  ll temp;
                  for(ll j=0;j<cols;j++)
                  {
                        cin>>temp;
                        v[i].push_back(temp);
                  }
            }

            int flag=0;
            ll chef= 0;
            for(ll i=0;i<rows;i++)
            {
                  for(ll j=0;j<(v[i].size()/2);j++)
                  {
                              chef+=v[i][j];
                  }

                  if((v[i].size())%2 !=0)
                  {
                        if(flag==0)
                        {
                              chef+=v[i][v[i].size()/2];
                              flag=1;
                        }
                        else
                        {
                              flag=0;
                        }     
                  }     
            }
            cout<<chef<<"\n";
      }


      return 0;
}