#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
//Without DP
int solve(int i,int d,vector<int> &nums){
    if(i<0){
        return 0;
    }
    int ans = 0;
    for(int j=i-1;j>=0;j--){
        if(nums[i]-nums[j]==d){
            ans=max(ans,1+solve(j,d,nums));
        }
    }
    return ans;
}
int longestArithSeqLength(vector<int> nums) {
    int n = nums.size();
    if(n<=2){
        return n;
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            ans = max(ans,2+solve(i,nums[j]-nums[i],nums));
        }
    }
    return ans;
}
//Top Down Approach
int solve2(int i,int d,vector<int> &nums,vector<unordered_map<int,int>> &dp){
    if(i<0){
        return 0;
    }
    if(!dp[i].count(d)){
        int ans = 0;
        for(int j=i-1;j>=0;j--){
            if(nums[i]-nums[j]==d){
                ans=max(ans,1+solve2(j,d,nums,dp));
            }
        }
        dp[i][d]=ans;
    }
    return dp[i][d];
}
int longestArithSeqLength2(vector<int> nums) {
    int n = nums.size();
    if(n<=2){
        return n;
    }
    vector<unordered_map<int,int>> dp(n+1);
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            ans = max(ans,2+solve2(i,nums[j]-nums[i],nums,dp));
        }
    }
    return ans;
}
int main(){
    cout<<longestArithSeqLength({20,1,15,3,10,5,8})<<endl;
    cout<<longestArithSeqLength2({20,1,15,3,10,5,8})<<endl;
}