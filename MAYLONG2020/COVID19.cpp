#include<iostream>
using namespace std;
typedef long long ll;

int main(){

      int test;
      cin>>test;

      while(test--){
            int n;
            cin>>n;

            int* arr = new int[n];

            for(int i=0;i<n;i++){
                  cin>>arr[i];
            }

            int min_affected=INT16_MAX,max_affected=1;
            int affected=1;

            for(int i=1;i<n;i++){
                  while(arr[i]-arr[i-1] <3 && i<n){
                        affected++;
                        i++;
                  }
                  if(affected > max_affected){
                        max_affected = affected;
                  }
                  if(affected<min_affected){
                        min_affected = affected;
                  }

                  if(i==n-1)
                  {
                        min_affected=1;
                  }
                  affected=1;
                
            }

            if(min_affected == INT16_MAX)
                  min_affected=max_affected;
            cout<<min_affected<<"\t"<<max_affected<<endl;
      }

      return 0;
}