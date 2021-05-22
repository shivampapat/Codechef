#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

int main(){

      int test;
      cin>>test;

      while(test--){
            long n;
            cin>>n;


            long counter=0;
            if(n==1)
                  cout<<"1\n1 1\n";
            else if(n==2)
                  cout<<"1\n2 1 2\n";
            else if(n==3)
                  cout<<"1\n3 1 2 3\n";      
            else{
                  cout<<n/2<<"\n";
                  cout<<"3 1 2 3\n";  
                  for(long i=4;i<=n;i+=2){
                        int diff = n-i;
                              if(m == 0){
                                    cout<<"1 "<<i<<endl;
                              }
                              else
                              cout<<"2 "<<i<<" "<<i+1<<"\n";
                        }
            }      
      
      }
      return 0;
}