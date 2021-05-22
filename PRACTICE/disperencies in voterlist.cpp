#include<bits/stdc++.h>
using namespace std;

void CheckPalPermute(string str)
{
      int n = str.length();

    int arr[26] ={0};
    map<char,vector<int> > m;
    int* v = new int[n];
      
        //freq of each char and then map first  char first index of duplicate
    for(int i=0;i<n;i++)
    {
        m[str[i]].push_back(i);
        arr[(int)str[i]-97]++;
    }


   int flag=0;
    for(int i=0;i<26;i++)
    {
        if(arr[i] %2 !=0)     
        {
                flag++;
        }
        if(flag >1)
        {
            flag = -1;
            break;
        }
    }


    if(str.length() %2==0 && (flag >0 || flag ==-1))
        {      
             //if even all should be %2==0
                cout<<"-1\n";
        }
    else
    {
        if(flag == -1)                // more than 1 char is odd
            cout<<"-1\n";
        else
        {
                map<char, vector<int> > :: iterator it;
                     
                int start=0,end = n-1;
                for(int i=0;i<26;i++)
                {
                    for(int j=0;j<m[(char)(i+97)].size();j+=2)
                    {    
                        if(m[(char)(i+97)].size()-j==1)
                        {
                            v[n/2] = m[(char)(i+97)][j];
                            continue;
                        }
                        v[start] = m[(char)(i+97)][j];
                        v[end] = m[(char)(i+97)][j+1];           
                        start++;
                        end--;
                    }    
                    
                } 
        }

            for(int i=0;i<n;i++)
            {
                cout<<v[i]<<" ";
            }
            cout<<"\n";
        }    
}

int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);

  /*  int test;
    cin>>test;
    cout<<test<<endl;
    */
      string str;
      cin>>str;
      CheckPalPermute(str);
     // test--;
     //cin.ignore(numeric_limits<streamsize>::max(),'\n');
    
    
    return 0;
}