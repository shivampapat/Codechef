#include<bits/stdc++.h>
using namespace std;

typedef long long ll;


ll findSwaps(ll n){
	
	ll half_sum = n*(n+1)/4;
	ll M =0 , diff =0, Rsum=0;
	ll curr=n;
	ll total_swaps =0;
	
	//Find max M
	while(Rsum < half_sum){
		Rsum += curr;
		curr--;
	}
	
	M = curr+1;
	diff = Rsum - half_sum;
	
	//max diff
	ll max_diff = n-1;
	
	while(diff < max_diff){
		
		ll right = M> diff ? M: diff+1<=n ? diff+1 : 0;
		ll left  = right - diff;
		
		
		if(right==0 || left <0)
			break;
		
		total_swaps= total_swaps + min(M-left, n-right+1);
		
		Rsum += curr;
		diff = Rsum - half_sum;
		curr--;
		M--;
	}
		
	return total_swaps;
		
}
int main(){
	
	ll test;
	cin>>test;
	
	while(test--){
		ll n;
		cin>>n;
		
		if(n<3)
			cout<<"0";
		else if(n<7)
			cout<<"2";	
		else
			cout<<findSwaps(n);	
		cout<<"\n";
	}
	
	return 0;
}


/*


16

1 2 3 4 5 6 7 8 9 || 10  11  12 13 14 15 16
   
Sum/2 = 68

Rsum = 16   31   45  58  70  81    91
diff = 52   37   23  10  -2  -13  -23
curr = 16   15   14  13  12  11    10  9 

M    = 12   11












M = 11
Rsum = 70
Diff = 2
Count = 2

M = 10
Rsum = 81
Diff = 13
Count = 3

M = 9
Rsum = 91
Diff = 23
Diff larger than existance so break;

Count = 5   

   
  */ 
