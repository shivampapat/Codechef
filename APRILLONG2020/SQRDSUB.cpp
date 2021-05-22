#include<iostream>
using namespace std;
typedef long long ll;

int IsTrue(ll n){
      
      int j=0;

      while(n%2==0){
            n/=2;
            j++;
            if(j>1){
                  break;
            }
      }
      if(j==2 || j==0){
            return  1;
      }
      return 0;
        
}


ll Find_Strange_Subsequence(ll* arr, ll n){

      ll count=0,N=1;
      ll mul =1,divider =1;

      ll* arr_product  = new ll[n];

      for(ll i=0;i<n;i++){
            mul = mul * arr[i];
            arr_product[i]= mul;
      }


      mul=1;

      for(ll i=0;i<n;i++){
            for(ll j=i;j<n;j++){

                  if(IsTrue(arr_product[j]/divider)){
                        count++;
                  }
            }
            divider = arr_product[i];      
      }
      return count;
}




int main(){

      int test;
      cin>>test;

      while(test--){
            ll n;
            cin>>n;
            ll* arr = new ll[n];
            for(ll i=0;i<n;i++){
                  cin>>arr[i];
            } 

            cout<<Find_Strange_Subsequence(arr,n)<<endl;

      }
      return 0;
}