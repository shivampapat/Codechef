#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

int main(){
      
      int n;
      cin>>n;

      int* arr = new int[n];

      for(int i=0;i<n;i++)
            cin>>arr[i];

      sort(arr,arr+n,greater<>());

      for(int i=0;i<n;i++)
            cout<<arr[i]<<" ";

      int min = INT_MAX, index_i = -1, index_j=-1;
      for(int i=0,j=n-1;i<=j;){
            int temp = arr[i] + arr[j];
            
            if(min > abs(temp)){
                  min = temp;
                  index_i = i;
                  index_j = j;
            }
            if(min==0){
                  index_i=i;
                  index_j=j;
                  break;
            }
            
            (abs(arr[i]) >= abs(arr[j])) ? i++: j--; 
      }      

      cout<<arr[index_j]<<" "<<(arr[index_i]);


      return 0;
}