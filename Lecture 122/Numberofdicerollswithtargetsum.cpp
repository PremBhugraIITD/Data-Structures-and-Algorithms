#include<iostream>
using namespace std;
#define mod 1000000007
//Without DP
int numRollsToTarget(int n, int k, int target) {
    if(n==0 && target==0){
        return 1;
    }
    else if(target<0){
        return 0;
    }
    else if(n==0 && target!=0){
        return 0;
    }
    else if(target==0 && n!=0){
        return 0;
    }
    int ans = 0;
    for(int i=1;i<=k;i++){
        ans+=numRollsToTarget(n-1,k,target-i)%mod;
    }
    return ans;
}
int main(){
    cout<<numRollsToTarget(3,6,12)<<endl;
}