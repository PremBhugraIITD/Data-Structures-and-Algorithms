#include<iostream>
using namespace std;
int main(){
    int r;
    cin  >> r;
    int i=r;
    while(i>=1){
        int j=1;
        while(j<=i){
            cout<<j<<" ";
            j=j+1;
        }
        int m=1;
        while(m<=r-i){
            cout<<"* ";
            m=m+1;
        }
        int n=1;
        while(n<=r-i){
            cout<<"* ";
            n=n+1;
        }
        int k=i;
        while(k>=1){
            cout<<k<<" ";
            k=k-1;
        }
        cout<<endl;
        i=i-1;
    }
}