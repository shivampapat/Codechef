#include<iostream>
using namespace std;

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

            int i=0,counter=0;
            while(arr[i] ==0){
                  i++;
            }
            i++;
            for(;i<n;i++){
                  if(arr[i]==1){     
                        if(counter<5)
                              break;
                        else
                        {
                              counter=0;
                        }
                  }
                  else
                  {
                        counter++;
                  }                
            }

            if(i==n)
                  cout<<"YES";
            else
            {
                  cout<<"NO";
            }
                  
      }

      return 0;
}