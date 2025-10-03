#include<iostream>
#include<vector>
using namespace std;
//Without DP
int combinationSum4(vector<int> nums, int target) {
    if(target==0){
        return 1;
    }
    else if(target<0){
        return 0;
    }
    int ans = 0;
    for(auto i:nums){
        ans += combinationSum4(nums,target-i);
    }
    return ans;
}
int main(){
    cout<<combinationSum4({1,2,3},4)<<endl;
}