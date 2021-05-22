#include<iostream>
using namespace std;
typedef long long ll;

int main(){

      int test;
      cin>>test;

      while(test--){
            int n,queries;
            cin>>n>>queries;

            static int arr[26]= {0};

            for(int i=0;i<n;i++){
                  char ch;
                  cin>>ch;
                  arr[(int)ch-97]++;
            }

            for(int i=0;i<queries;i++){
                  ll isolation_centres=0;
                  cin>>isolation_centres;
                  
                  ll queue_counter=0;
                  for(int j=0;j<26;j++){
                        if(arr[j] > isolation_centres){
                              queue_counter+=(arr[j]-isolation_centres);
                        }
                  }
                  cout<<queue_counter<<endl;
            }

            
      }

      return 0;
}