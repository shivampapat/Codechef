#include<iostream>
#include<algorithm>
using namespace std;



int main(){

      long test;
      cin>>test;
      
      long m = 1000000007;
      
      while(test--){
                 long n;
            cin>>n;

            long* arr = new long[n];

            for(long i=0;i<n;i++){
                  cin>>arr[i];
            }

        sort(arr,arr+n,greater<long>());

           
            long sum = 0,subtractor=0;
            for(long i=0;i<n;i++){
                  if(arr[i]-subtractor >0){
                        sum = sum + (arr[i]-subtractor)%m;
                        sum = sum%m;
                        subtractor++;
                  }
                  else
                  {
                        break;
                  }
                  
            }
            cout<<sum<<"\n";
      }

      return 0;
}