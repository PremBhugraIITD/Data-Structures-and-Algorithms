#include<iostream>
#include<vector>
using namespace std;
//Top Down Approach
int solve(int l,int u,string s,vector<vector<int>> &dp){
    if(l>u){
        return 0;
    }
    else if(l==u){
        return 1;
    }
    if(dp[l][u]==-1){
        if(s[l]==s[u]){
            dp[l][u] = 2+solve(l+1,u-1,s,dp);
        }
        else{
            dp[l][u] = max(solve(l+1,u,s,dp),solve(l,u-1,s,dp));
        }
    }
    return dp[l][u];
}
int longestPalindromeSubseq(string s) {
    vector<vector<int>> dp(s.length(),vector<int> (s.length(),-1)); 
    return solve(0,s.length()-1,s,dp);
}
int main(){
    cout<<longestPalindromeSubseq("bbbab")<<endl;
}