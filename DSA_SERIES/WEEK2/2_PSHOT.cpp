#include<iostream>
using namespace std;

int main(){
      
      int tester = 0;cin>>tester;

      while(tester--){
            int n;
            cin>>n;
            int scoreA=0,scoreB=0;
            string s;
            cin>>s;
            int chances_A=n;
            int chances_B=n;

            bool t = true;

            int i=0;
            for(i=0;i<s.length();i++){

                        if(i%2==0){
                              scoreA += (s[i]-'0');
                              chances_A--;
                        }  
                        else{
                              scoreB += (s[i]-'0');
                              chances_B--;
                        }
                              
                     //   cout<<"i: "<<i<<" scoreA : "<<scoreA<<" scoreB:  "<<scoreB<<endl;

                              if(scoreA > (scoreB+chances_B)){
                                           cout<<i+1<<"\n";
                                           break;
                               }
                              if(scoreB > (scoreA+chances_A)){
                                           cout<<i+1<<"\n";
                                           break;
                              }
                               
                        
            }

            if(i==s.length()){
                  cout<<2*n<<"\n";
            }


            // for(int i=0;i<s.length()-1;i+=2){
                  
            //       int score1,score2;
            //       score1 = s[i]-'0';
            //       score2 = s[i+1]-'0';

            //       scoreA+= score1;      
            //       scoreB+= score2;
            //       current_games++;

            //       cout<<i<<" " <<scoreA<<" "<<scoreB<<" "<<current_games<< endl;

            //       if(current_games > (n-current_games)){
            //             if(max(scoreA,scoreB) > (min(scoreA,scoreB)+(n-current_games))){
            //                   cout<<(i+2)<<"\n";
            //                   t=false;
            //                   break;
            //             }                        
            //       }
                  
            // }
            // if(t){
            //       cout<<(2*n)<<"\n";
            // }
      }
      return 0;
}