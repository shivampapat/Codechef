#include<bits/stdc++.h>
using namespace std;

vector<long> dp(10000,-1);

void MaxafterQueries(vector<int>& arr, int m)
{
      queue<long long> q;
      vecotr<int>::iterator it;
      it = v.end()-1;

      long long input,x,temp=0;
      for(int i=0;i<m;i++)
      {
            cin>>input;
            for(int j=temp,j<input;j++)
            {
                  if(input==1)
                  {
                        x = arr[n-1];
                        q.push(arr[n-1]/2);
                        temp++;
                        it--;
                  }
                  else
                  {
                        if(q.front() > *it)
                        {
                              x = q.front();
                              q.push(q.front()/2);
                              q.pop();
                        }
                        else
                        {
                              x = *it;
                              q.push((*it)/2);
                              it--;     
                        }
                  }
                  
                  cout<<x<<endl;
            }

            
            



      }
}

int main()
{
      int n,m;
      cin>>n>>m;

      vector<int> arr(n);

      for(int i=0;i<n;i++)
      {
            int temp=0;
            cin>>temp;
            arr.push_back(temp);
      }

      sort(arr.begin(),arr.end());
      MaxafterQueries(arr,m);

      return 0;
}