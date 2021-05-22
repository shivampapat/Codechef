#include<iostream>
#include<math.h>
using namespace std;
typedef long long ll;

int main(){

      int test;
      cin>>test;

      while(test--){
            ll X,Y,L,R;
            cin>>X>>Y>>L>>R;


            if(X == 0 || Y ==0){
                  cout<<L<<endl;
                  continue;
            }
            int arr[64]={0};

            for(int i=63;i>=0;i--){
                  int bit_X=0,bit_Y=0;

                  bit_X = (X>>i) & 1;
                  bit_Y = (Y>>i) & 1;
                  
                  if(bit_X == 0 && bit_Y == 0){
                        arr[i]=0;
                  }
                  else if(bit_X == 1 && bit_Y == 1){
                        arr[i]=1;
                  }
                  else{
                        arr[i]=-1;
                  }
            }

            ll max_value=0;
            for(int i=0;i<64;i++){
                  if(arr[i]==1)
                  {
                       max_value+=pow(2,i);
                  }
            }

            if(max_value >R){
                  ll temp = 0,i=0;
                  max_value=0;
                  for(i=0;i<40;i++){
                        if(arr[i]==1)
                        {
                              if((max_value + pow(2,i)) > R)
                                    break;
                        max_value+=pow(2,i);
                        temp = max_value;
                        }
                  }
                  if(i!=64){
                        cout<<"here";
                        cout<<temp<<endl;
                        continue;
                  }
                  
            }
            for(int i=63;i>=0;i--){   
                  if(arr[i]== -1){
                        if((max_value + pow(2,i)) > R)
                              continue;               
                        else{
                              max_value+=pow(2,i);
                        }
                  }
            } 
            cout<<max_value<<endl;     
      }
    
      return 0;
}