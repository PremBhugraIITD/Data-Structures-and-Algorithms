#include<iostream>
using namespace std;
int fact(int a){
    int ans = 1;
    for(int i = 1;i<=a;i++){
        ans=ans*i;
    }
    return ans;
}
int main(){
    int n,r;
    cin>>n>>r;
    cout<<(fact(n)/(fact(r)*fact(n-r)));
}