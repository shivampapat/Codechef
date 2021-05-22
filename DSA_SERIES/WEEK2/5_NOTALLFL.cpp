#include<iostream>
using namespace std;
typedef long long ll;

void Clear_Used_Flavours(ll flavours[],ll k){

       for(ll i=0;i<k;i++)
            flavours[i]=0;
}


ll FindMaxFlavours(ll arr[], ll n, ll k){
      
      ll curr_counter=0,max_counter=0,used_flav=0;
      
      //For k flavours
      ll* flavours_available_max = new ll[k+1];

      //Make K used at inital 0 
     Clear_Used_Flavours(flavours_available_max,k+1);

      ll temp_index=0;
      //Logic
      for(ll i=0;i<n;i++){
                  
            cout<<arr[i]<<"\n";
            if(flavours_available_max[arr[i]] ==0){
                  used_flav++;
            }
                  flavours_available_max[arr[i]]++;
                  cout<<"used_flav="<<used_flav<<"\t";
            
            //Condition to use only k-1 max flavours
            if(used_flav < k){
                  curr_counter++;
                  cout<<"curr_counter"<<curr_counter<<"\n";
            }
            else{
                  cout<<"came in else\n";
                  max_counter  =  max_counter > curr_counter ? max_counter : curr_counter;
                  
                  while(temp_index <=i && used_flav == k){
                              
                              flavours_available_max[arr[temp_index]]--;
                              if(flavours_available_max[arr[temp_index]] == 0){
                                    used_flav--;
                              }
                              curr_counter--;
                              temp_index++;
                  }
                  curr_counter++;
            }
      }

      return(max_counter > curr_counter ? max_counter : curr_counter);
}

int main(){

      ll test; cin>>test;

      while(test--){

            ll n;cin>>n;
            ll flav;cin>>flav;

            ll* arr = new ll[n];

            ll max=0;
            for(ll i=0;i<n;i++){
                  cin>>arr[i];
                  if(arr[i] > max)
                        max= arr[i];
            }

            if(max < flav)
                  cout<<n<<"\n";
            else      
                  cout<<FindMaxFlavours(arr,n,flav)<<"\n";
      }

      return 0;
}