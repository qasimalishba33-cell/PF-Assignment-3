#include<iostream>
using namespace std;
int main(){
    
    int n;
    cout<<"Enter the number:"<<endl;
    cin>>n;
    
    for (int i= 1; i <= n; i++){
        
        for (int spaces = n-i; spaces >= 1; spaces--){
            
            cout<<" ";
            
        }
        for (int j = 1; j <= (2*i)-1; j++){
            
            if (j%2 == 0){
                cout<<"*";
            }
            
            else {
                
                cout<<"#";
            }
        }
        
        cout<<endl;
        
    }
    
    
}