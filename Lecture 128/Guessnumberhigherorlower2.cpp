#include<iostream>
#include<limits.h>
using namespace std;
//Without DP
long long int solve(int i,int j){
    if(j<=i){
        return 0;
    }
    else{
        long long int ans=INT_MAX;
        for(int a=i;a<=j;a++){
            ans=min(ans,a+max(solve(i,a-1),solve(a+1,j)));
        }
        return ans;
    }
}
int getMoneyAmount(int n) {
    return solve(1,n);
}
int main(){
    cout<<getMoneyAmount(10)<<endl;
}