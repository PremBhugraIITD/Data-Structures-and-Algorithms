#include<iostream>
#include<vector>
using namespace std;
//Without DP
bool solve(vector<int> &nums,int target,int i){
    if(target==0){
        return true;
    }
    else if(target<0){
        return false;
    }
    else if(i>=nums.size()){  //If i surpasses the array and still the target > 0, so now there are no more numbers to include. 
        return false;
    }
    else{
        int include = solve(nums,target-nums[i],i+1);
        int exclude = solve(nums,target,i+1);
        return include||exclude;
    }
}
bool canPartition(vector<int> nums) {
    int sum = 0;
    for(int i=0;i<nums.size();i++){
        sum+=nums[i];
    }
    if(sum&1){
        return false;
    }
    return solve(nums,sum/2,0);
}
//If the sum of the "nums" array is odd then answer is false.
//So, if the number is even then the Questions becomes whether it is possible to obtain the number "target (= sum of the "nums" array)" by adding up the elemtnts of "nums" array, given that we can include or exclude elements as per our choice.
//We are going through inclusion exclusion approach
int main(){
    cout<<canPartition({1,5,11,5})<<endl;
}