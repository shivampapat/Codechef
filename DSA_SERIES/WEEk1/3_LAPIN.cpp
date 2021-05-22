#include <iostream>
using namespace std;

int main() {
        
    int test;
    cin>>test;
    
    while(test--){
        
        string s;
        cin>>s;
        cout<<s<<endl;
        int before[26]={0};
        int after[26]={0};
        
        int mid = s.length()/2;
        if((s.length()%2) == 0){
            for(int i=0,j=mid;i<mid;i++,j++){
                before[(int)s[i] - 'a'] ++;
                after[(int)s[j] - 'a'] ++;
            }
        }
        else{
            for(int i=0,j=mid+1;i<mid;i++,j++){
                before[(int)s[i] - 'a'] ++;
                after[(int)s[j] - 'a'] ++;
            }
        }
        
        int i=0;
        for(i=0;i<26;i++){
            if(after[i] != before[i])
            {
                cout<<"NO\n";
                break;
            }
        }
        
        if(i == 26){
            cout<<"YES\n";
        }
    }
    return 0;
}
