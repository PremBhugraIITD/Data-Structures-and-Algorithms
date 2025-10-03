#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
//Without DP
int maxi(int i,int j,vector<int> &arr){
    int ans = INT_MIN;
    for(int a=i;a<=j;a++){
        ans=max(ans,arr[a]);
    }
    return ans;
}
int solve(int i,int j,vector<int> &arr){
    if(j<=i){
        return 0;
    }
    else if(j-i==1){
        return arr[i]*arr[j];
    }
    else{
        int ans=INT_MAX;
        for(int a=i;a<j;a++){
            ans=min(ans,maxi(i,a,arr)*maxi(a+1,j,arr)+solve(i,a,arr)+solve(a+1,j,arr));
        }
        return ans;
    }
}
int mctFromLeafValues(vector<int> arr) {
    return solve(0,arr.size()-1,arr);
}
int main(){
    cout<<mctFromLeafValues({7,12,8,10})<<endl;
}