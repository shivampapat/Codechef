#include<iostream>
#include<stdio.h>
using namespace std;

typedef long long ll;

int main(){

      int test;
      cin>>test;

      while(test--){
            int n;
            cin>>n;

            ll* arr = new ll[n];


            for(ll i=0;i<n;i++){
                  cin>>arr[i];
            }

            ll counter=1;
            for(ll i=1;i<n;i++){
                  if(arr[i] < arr[i-1]){
                        counter++;
                  }
                  else{
                        arr[i] = arr[i-1];
                  }
            }

            printf("%u\n",counter);

      }

      return 0;
}