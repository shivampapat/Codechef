#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int FindisWorthy(ll** sum,ll src_i,ll src_j,ll dest_i,ll dest_j,ll k){
	
	ll result = sum[dest_i][dest_j];
  
    if (src_i > 0)
       result = result - sum[src_i-1][dest_j];
  
    if (src_j > 0)
       result = result - sum[dest_i][src_j-1];
  
    if (src_i > 0 && src_j > 0)
       result = result + sum[src_i-1][src_j-1];
	
	ll size = dest_j - src_j+1;
	size=  size*size;
	
//	cout<<"\tResult is :"<<result<<"\n";
	
	if(result/size >=k){
		return 1;
	}
	return 0;
}


int main(){
		
	ll t;cin>>t;
	
	while(t--){
		ll n,m,k;
		cin>>n>>m>>k;
		
		//Input
		ll arr[n][m];
		for(ll i=0;i<n;i++){
			for(ll j=0;j<m;j++)
				cin>>arr[i][j];
		}
		
		//Sum matrix 
		ll **sum;
		sum = new ll*[n];
		
		for(ll i=0;i<n;i++){
			sum[i] = new ll[m];
			for(ll j=0;j<m;j++){
				if(j==0)
					sum[i][j] = arr[i][j];
 				else
					sum[i][j] = sum[i][j-1] + arr[i][j];
			}
		}
		
		for(ll i=1;i<n;i++){
			for(ll j=0;j<m;j++)
				sum[i][j] += sum[i-1][j];
		}

		
		ll count =0;
		
		//For matrix of each dimension 
		for(ll i= 1; i<=min(n,m); i++){
		
//			cout<<"i :"<<i<<endl;
			//For each valid row find matrix who has avg>=k using BS
			for(ll row_i = 0;row_i <= n-i;row_i++){
				
//				cout<<"row is "<<row_i;
				// Binary search here
				ll left = 0;
				ll right = m-i;
				ll mid =0;
				bool flag = false;
				ll index = 0;
				while(left <=right){
					
					mid = (left+right)/2;
//					cout<<"    mid is:"<<mid<<"\t";
					if(FindisWorthy(sum,row_i,mid,row_i+i-1,mid+i-1,k) > 0){
						flag = true;
						index = mid;
						right = mid-1;
					}
					else{
						left = mid+1;
					}
//					cout<<"    index is"<<index<<"\t";
			//		cout<<"left : "<<left<<"   right: "<<right<<"   mid :"<<mid<<endl;
				}
//				cout<<"     flag :"<<flag<<"\t";
			    if(flag==true)
				    count = count + (m-i) - index + 1;
//			    cout<<"count is everytime : \t"<<count<<endl;
			    
			}
//			cout<<endl;
					
		}

	cout<<count<<endl;
		
		/*
		//Print
		for(ll i=0;i<n;i++){
			for(ll j=0;j<m;j++)
				cout<<sum[i][j]<<"\t";
			cout<<endl;
		}
		*/
	}
	
	
	return 0;
}