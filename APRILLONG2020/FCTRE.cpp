#include<iostream>
using namespace std;

long dfs(long** arr, long n,long* cost,bool* visited, long start, long end){
      long product = 1;

      visited[start]=true;
      if(start==end){
            return product*cost[start];
      }
            for(long i=1;i<n+1;i++){
                  if(i==start)
                        continue;
                  if(arr[start][i] ==1 && !visited[i]){
                        long temp_prod;
                        temp_prod = dfs(arr,n,cost,visited,i,end);  
                        
                        if(temp_prod >1){
                        product = temp_prod*cost[start];
                        return product;
                        }

                  }
            }
       return product;     
      
}

int main(){
      
      int test;
      cin>>test;

      while(test--){
            long n;
            cin>>n;

            long** arr = new long*[n+1];
            for(long i=0;i<n+1;i++){
                  arr[i] = new long[n+1];
                  for(long j=0;j<n+1;j++){
                        arr[i][j]=0;
                  }
            }

            for(long i=1;i<n;i++){
                  int start,end;
                  cin>>start>>end;
                  arr[start][end]=1;
                  arr[end][start]=1;
            }

            long* cost = new long[n+1];
            for(long i=1;i<n+1;i++){
                  cin>>cost[i];
            }

            bool* visited = new bool[n+1];
            for(long i=0;i<n+1;i++)
                  visited[i]= false;

            long query =0;
            cin>>query;
            for(long i=0;i<query;i++){
                  long start,end;
                  cin>>start>>end;
                  long product = dfs(arr,n+1,cost,visited,start,end);
                  long counter=2;
                  for(long j=2;j<=(product/2);j++){
                        if(product%j==0){
                              counter++;
                        }
                  }
                  cout<<counter<<"\n";
            }

      }
      
      return 0;
}