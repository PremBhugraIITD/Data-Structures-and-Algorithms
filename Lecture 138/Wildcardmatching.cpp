#include<iostream>
#include<vector>
using namespace std;
//Top Down Approach
bool solve(string s,string p,int i,int j,vector<vector<int>> &dp){
    if(i<0 && j<0){
        return true;
    }
    else if(i>=0 && j<0){
        return false;
    }
    else if(i<0 && j>=0){ //If the string s has ended being traversed but the string p is still left to be traversed then if any character other than '*' is present in the string p then p won't match the string s
        for(int k=j;k>=0;k--){
            if(p[k]!='*'){
                return false;
            }
        }
        return true;
    }
    if (dp[i][j]==-1){
        if(s[i]==p[j] || p[j]=='?'){
            return dp[i][j] = solve(s,p,i-1,j-1,dp);
        }
        else if(p[j]=='*'){
            return dp[i][j] = solve(s,p,i-1,j,dp) || solve(s,p,i,j-1,dp);
        }
        else{
            return dp[i][j] = false;
        }
    }
    return dp[i][j];
}
bool isMatch(string s, string p) {
    vector<vector<int>> dp(s.length(),vector<int> (p.length(),-1));
    return solve(s,p,s.length()-1,p.length()-1,dp);        
}
int main(){
    cout<<isMatch("aab","c*a*b")<<"   "<<isMatch("aabbbbbbabbaabbbababbbabbaaabbbbabbbaaaabbbababbaaabbbaabaaaaaaabbbbbababaaababbaaabbabababbabbbaaababbaaaabaaaaaabbaabbaaaabbbbabaabaababaabaababaabbaaaaabaababbaabbbbabbbbbabaaaabaabaabaaaaabbabaaaa","b*bbbb**b*a**aababbb******bbbab***a***babb**b*a*****a*b*b*a**b*a**a*ab*b*aba*b***bb****ba*a*****a*aab**a")<<"   "<<isMatch("aa","*")<<endl;
}