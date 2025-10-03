#include<iostream>
#include<vector>
using namespace std;
//Without DP
int solve(vector<int> &nums,int i, int prev){ //prev is the index, in the nums array, of the last element in the subsequence 
    if(i>=nums.size()){
        return 0;
    }
    int exclude = solve(nums,i+1,prev);
    int include = exclude;
    if(prev==-1 || nums[i]>nums[prev]){
        include = 1+solve(nums,i+1,i);
    }
    return max(include,exclude);
}
int lengthOfLIS(vector<int> nums) {
    return solve(nums,0,-1);
}
int main(){
    cout<<lengthOfLIS({10,9,2,5,3,7,101,18})<<"   "<<lengthOfLIS({0,1,0,3,2,3})<<endl;
}