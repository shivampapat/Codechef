#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){

      ll t;
      cin >> t;
      while(t--){
            int arr[3][3];
            ll count_ = 0, count_x = 0, count_o=0;
            for (int i = 0; i < 3;++i){
                        string temp;
                        cin >> temp;
                        
                        char cArr[4];
                        strcpy(cArr, temp.c_str());

                        for (int j = 0; j < 3;j++){
                              if (cArr[j] == '_')
                              {
                                    arr[i][j] = -10;
                                    count_++;
                              }
                              else if (cArr[j] == 'X')
                              {
                                    arr[i][j] = 1;
                                    count_x++;
                              }
                              else
                              {
                                    arr[i][j] = 0;
                                    count_o++;
                              }
                        }
            }

            int win_x = 0, win_o = 0;

            //Check win for X
            for(int i=0; i<3; i++){
                  if((arr[i][0] == arr[i][1] && arr[i][0] == arr[i][2])){
                        if(arr[i][0] == 1){
                              win_x++;
                        }
                        if(arr[i][0] == 0){
                              win_o++; 
                        }
                  }
                  if(arr[0][i] == arr[1][i] && arr[0][i] == arr[2][i]){
                        if(arr[0][i] == 1){
                              win_x++;
                        }
                        if(arr[0][i] == 0){
                              win_o++;
                        }
                  }
            }
             //checking the win for both diagonal
      
            if(arr[0][0] == arr[1][1] && arr[0][0] == arr[2][2]){
                  if(arr[1][1] == 1)
                        win_x++;
                  if(arr[1][1] == 0)
                        win_o++;
            }
            if(arr[0][2] == arr[1][1] && arr[0][2] == arr[2][0]){
                  if(arr[1][1] == 1)
                        win_x++;
                  if(arr[1][1] == 0)
                        win_o++;
            }


            if(count_x - count_o >1 || count_x - count_o <0){
                  cout << "3\n";
            }
            else if(win_x==1 && win_o==0 && count_x > count_o){
                  cout << "1\n";
            }
            else if(win_x==0 && win_o==1 && count_x == count_o){
                  cout << "1\n";
            }
            else if(win_x==0 && win_o==0 && count_ == 0){
                  cout << "1\n";
            }
            
            else if(count_ == 0 && win_x==2){
                  cout << "1\n";
            }
            
            else if(win_x==0 && win_o==0 && count_ > 0){
                  cout << "2\n";
            }    
            else{
                  cout << "3\n";
            }
      }
      return 0;
}

/*
else if(count_ == 0){
                  if(win_x=0 && win_o ==0 || win_x==2)
                        cout << "1\n";
            }
            
*/