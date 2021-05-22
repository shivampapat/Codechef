#include<iostream>
#include<math.h>
using namespace std;

int main(){

      int X,N;

      cin>>X>>N;
      int remainder=0;

      switch(N){
            case 1:
                        cout<<X%10;
                        break;
            case 2:
                        cout<<(X*X)%10;
                        break;

            case 3:
                        remainder = pow(X,6);
                        cout<<remainder%10;
                        break;
            case 4:
                        remainder = pow(X,24);
                        cout<<remainder%10;
                        break;
            default:
                        cout<<1;                            
      }
      return 0;
}