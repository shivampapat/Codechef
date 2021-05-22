 // Online C++ compiler to run C++ online.
// Write C++ code in this online editor and run it.

#include <iostream>
using namespace std;

int main() {
    
    int n1,n2;
    cin>>n1>>n2;
    
    int* arr1= new int[n1];
    int* arr2= new int[n2];
    
    for(int i=0;i<n1;++i){
        cin>>arr1[i];
    }
    
    for(int i=0;i<n2;++i){
        cin>>arr2[i];
    }
    
    for(int i=0;i<n1;++i){
        cout<<arr1[i];
    }
    cout<<"asdfghj\n";
    for(int i=0;i<n1;++i){
        cout<<arr2[i];
    }
    
    return 0;
}