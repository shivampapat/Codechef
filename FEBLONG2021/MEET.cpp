#include<bits/stdc++.h>
using namespace std;


/*
if AM && 12   --> make it 00(hh)
if PM  --> make it +12 in hh except 12	
*/


int main(){
		
	int test;
	cin>>test;
	while(test--){
		
		char ch;
		cin>>ch;
		
		string p;
		getline(cin,p);
		cout<<p;
		
		/*
		char* char_arr;
    char_arr = &p[0];	
		char *pch = strtok(char_arr, " :");
		while (pch != NULL)
  		{
    	printf ("%s\n",pch);
    	pch = strtok (NULL, " ,.-");
  }
		
		*/
		cout<<"here";	
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			string c;
			getline(cin,c);
			
			char* char_arr1;
    		char_arr1 = &c[0];	
		
			char *pch1 = strtok(char_arr1, " :");
		
			while (pch1 != NULL)
  			{
			    printf ("%s\n",pch1);
			    pch1 = strtok (NULL, " ,.-");
			}
		
		}
		
	}
		
	return 0;
}
