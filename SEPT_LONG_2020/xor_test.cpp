#include<iostream>
using namespace std;

int main(){
	
	while(1){
		int n;
		cin>>n;
		
		if(n==-1){
			break;
		}
		cout<< (n^7) +(n^8) +(n^9) +(n^10);
		cout<<endl; 
		
	}
	
	
	return 0;
}
