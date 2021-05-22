#include<bits/stdc++.h>
using namespace std;

int main(){

      long Total=0;
      int test;
      cin>>test;

      while(test--){
            int n;
            cin>>n;

           int arr[4][4] = {0};

            for(int i=0;i<n;i++){
                  char movie;
                  int time;
                  cin>>movie>>time;

                  if(time == 12)
                        arr[(int)movie-65][0]++;
                  else if(time == 3)
                        arr[(int)movie-65][1]++;
                  else if(time == 6)
                        arr[(int)movie-65][2]++;
                  else
                      arr[(int)movie-65][3]++;
            }

           

            vector<vector<int> > v;
            vector<int> v1[4];
            for(int i=0;i<4;i++){
                  for(int j=0;j<4;j++){
                        v1[i].push_back(arr[j][i]);
                  }   
                  v.push_back(v1);  
            }
            

            long result =0,multiplier=100;

            for(int k=0;k<4;k++){
                  int max = -1,row = -1,time=-1;
                  for(int i=0;i<v.size();i++){
                        int temp = *max_element(v[i].begin(),v[i].end());
                        int index = max_element(v[i].begin(),v[i].end()) - v[i].begin();
                        if(temp>max){
                              max= temp;
                              time = index;
                              row =i;
                        }
                        
                  }
                  if(max ==0){
                        result-=100;
                  }
                  else{
                        result+= multiplier*max;
                        multiplier-=25;
                  }

                  //Delete that time slot 
                  for (int i = 0; i < v.size(); ++i){
                        v[i].erase(v[i].begin() + time);
                  }

                  //Not to include movie again so dlete that row
                  v.erase( v.begin() + row);
            }

            cout<<result<<"\n";
            Total +=result;
            
      }
      cout<<Total;
      return 0;
}